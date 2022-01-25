#include <zmq.hpp>
#include <iostream>
#include "ZeroMqProxy.h"


int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    std::cout << "Usage: ./zmq_proxy <listenAddress> <PushlishAddress> " << std::endl;
    std::cout << "Example ./zmq_proxy tcp://*:5555 tcp://*:5556" << std::endl;
    exit(1);
  }
  //Instantiate Proxy
  ZeroMqProxy* proxy = new ZeroMqProxy(argv[1], argv[2]);
  //Start Proxy as thread
  proxy->startProxy();
  std::cout << "Shouldn't get here" << std::endl;
  //Stop Proxy
  return 0;
}
