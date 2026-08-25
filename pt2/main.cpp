#include "../pt1/journal.hpp"
#include <iostream>
#include <thread>

int main() {
  std::string s, mess;
  int l, l2;
  std::cin >> s >> l;
  journal master{s, l};
  /*
  std::cin >> mess >> l2;
  master.save_mess(mess, l2);
  */
  while (1) {
    std::string r;
    int r1;
    std::cin >> r;
    if (r == "end") {
      break;
    } else if (std::cin.eof()) {
      r1 = master.lvl;
      std::thread t1(&journal::save_mess, &master, r, r1);
      t1.join();
    } else {
      std::cin >> r1;
      std::thread t2(&journal::save_mess, &master, r, r1);
      t2.join();
    }
  }
}
