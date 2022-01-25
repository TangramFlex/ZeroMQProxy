#include "ZeroMqProxy.h"
#include <iostream>
#include <errno.h>

ZeroMqProxy::ZeroMqProxy(const std::string listenAddress, const std::string publishAddress)
{
  context = zmq_ctx_new();
  //
  frontend = zmq_socket(context, ZMQ_XSUB);
  zmq_setsockopt(frontend, ZMQ_SUBSCRIBE, "", 0);
  if(zmq_bind(frontend, listenAddress.c_str()) != 0)
  {
    int errsv = errno;
    std::cout << "Error binding XSUB. Error Code: " << errsv << std::endl;
  }
  else
  {
    std::cout << "Subscribing on " << listenAddress << std::endl;
  }

  //This is where subscribers listen
  backend = zmq_socket(context, ZMQ_XPUB);
  if(!backend)
  {
    std::cout << "Invalid Socket" << std::endl;
  }
  if(zmq_bind(backend, publishAddress.c_str()) != 0)
  {
    int errsv = errno;
    std::cout << "Error binding XPUB. Error Code: " <<  errsv << std::endl;
  }
  else
  {
    std::cout << "Publishing on " << publishAddress << std::endl;
  }
}
ZeroMqProxy::~ZeroMqProxy()
{
  zmq_close(frontend);
  zmq_close(backend);
  zmq_ctx_destroy(context);
}
void ZeroMqProxy::startProxy()
{
  zmq_proxy(frontend, backend, NULL);
}
