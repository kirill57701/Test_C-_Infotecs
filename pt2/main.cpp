#include "../pt1/journal.hpp"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mut;

void mut_save(journal& master, std::string mess, int lvl) {
  std::lock_guard<std::mutex> lock(mut);
  master.save_mess(mess, lvl);
}

int main(int argc, char** argv) {
  if (argc < 3 || argc > 3) {
    std::cerr << "enter 3 params\n";
    return -1;
  }
  journal master{argv[1], std::stoi(argv[2])};
  std::string r;
  int r1 = master.lvl;
  while (std::cin >> r) {
    r1 = master.lvl;
    if (r == "end") {
      break;
    }
    int c;
    if (std::cin >> c) {
      r1 = c;
    } else {
      std::cin.clear();
    }
    std::thread t2(mut_save, std::ref(master), r, r1);
    t2.detach();
  }
  master.cl_ofstr();
}
