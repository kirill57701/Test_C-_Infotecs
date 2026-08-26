#include "../pt1/journal.hpp"
#include <iostream>
#include <thread>

int main(int argc, char** argv) {
  if (argc < 3 || argc > 3) {
    std::cerr << "enter 3 params\n";
    return -1;
  }
  journal master{argv[1], std::stoi(argv[2])};
  std::string r;
  int r1 = master.lvl;
  while (std::cin >> r) {
    if (r == "end") {
      break;
    }
    int c;
    if (std::cin >> c) {
      r1 = c;
    } else {
      std::cin.clear();
    }
    std::thread t2(&journal::save_mess, &master, r, r1);
    t2.join();
  }
}
