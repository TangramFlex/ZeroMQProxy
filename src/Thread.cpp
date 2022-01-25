#include "Thread.h"

Thread::Thread()
{
  futureObj = exitSignal.get_future();
}

void Thread::start()
{
  t = std::thread(&Thread::run, this);
}

void Thread::stop()
{
  exitSignal.set_value();
}

bool Thread::keepRunning()
{
  if(futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
  {
    return true;
  }
  return false;
}

void Thread::startProcess()
{
  this->run();
}
