#include "../pt1/journal.hpp"
#include <iostream>
#include <thread>

int main() {
  std::string s;
  int l;
  std::cin >> s >> l;
  journal master{s, l};
  /*
  std::cin >> mess >> l2;
  master.save_mess(mess, l2);
  */
  std::string r;
  int r1 = master.lvl;
  while (std::cin >> r) {
    int c;
    if (std::cin >> c) {
      r1 = c;
    } else {
      std::cin.clear();
    }
    if (r == "end") {
      break;
    } else {
      std::thread t2(&journal::save_mess, &master, r, r1);
      t2.join();
    }
  }
}
