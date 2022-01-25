#pragma once

//#include "Thread.h"
#include <zmq.hpp>
#include <string>


class ZeroMqProxy
{
public:
  //ZeroMqProxy();
  ZeroMqProxy(const std::string listenAddress, const std::string publishAddress);
  ~ZeroMqProxy();
  //virtual void run();
  void startProxy();

private:
  void* context;
  void* frontend;
  void* backend;

};
