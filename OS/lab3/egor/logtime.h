#include <queue>
#include <iostream>
#include <ctime>

#include "signal.h"

class LogTime {
 public:
  LogTime(std::queue<std::pair<Signal, double> > &signals, std::mutex &s) : signals(signals), s(s) { startWrite(); }

 private:
  void startWrite() {
    while (true) { // true !signals.empty()
      if (!signals.empty()) {
        s.lock();
   
        std::cout << "[logger time]  [" << (signals.back().first == 0 ? "RECIEVED" : "RECORDED") << "] -> " << signals.back().second << " |  time:" << std::time(nullptr) << std::endl;
        signals.pop();
        s.unlock();
      }
    }
  }
  
  std::mutex &s;
  std::queue<std::pair<Signal, double> > &signals;
};