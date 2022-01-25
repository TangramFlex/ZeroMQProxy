#pragma once

#include <thread>
#include <chrono>
#include <future>
#include <iostream>

class Thread
{
public:
  Thread();
  virtual ~Thread(){t.join();};
  void start();
  void stop();
  bool keepRunning();

  //implement this in subclass, this is what is executed in the thread.
  //call keepRunning to see if thread should keep running.
  virtual void run(){while(true){std::cout <<"Thread class" << std::endl;}};
private:
  std::thread t;
  void startProcess();
  Thread(const Thread& rhs);
  Thread& operator=(const Thread& rhs);
  std::promise<void> exitSignal;
  std::future<void> futureObj;

};
