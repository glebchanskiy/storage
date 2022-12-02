#include "signal.h"
#include "point.h"

class Logger {
 public:
  Logger(std::queue<std::unique_ptr<Point> > &queue, std::mutex &q,
         std::mutex &s, std::queue<std::pair<Signal, double> > &signals)
      : queue(queue), q(q), s(s), signals(signals) {
    startLogs();
  }

 private:
  void startLogs() {
    while (true) { //true !queue.empty()
      if (!queue.empty()) {
        q.lock();
        s.lock();

        std::cout << "[logger data]  [" << queue.front()->x << "] : [" << queue.front()->y << "]" << std::endl;
        signals.push(std::make_pair(Signal::RECORDED, queue.front()->y));
        queue.pop();

        q.unlock();
        s.unlock();
      }
    }
  }

  std::queue<std::pair<Signal, double> > &signals;
  std::mutex &q;
  std::mutex &s;
  std::queue<std::unique_ptr<Point> > &queue;
  double start_X;
  double end_X;
  double (*func)(double x);
};