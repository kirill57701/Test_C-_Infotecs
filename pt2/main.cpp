#include "../pt1/journal.hpp"
#include <iostream>

int main() {
  std::string s, mess;
  int l, l2;
  std::cin >> s >> l;
  journal master{s, l};
  std::cin >> mess >> l2;
  master.save_mess(mess, l2);
}
