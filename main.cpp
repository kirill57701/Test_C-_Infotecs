#include <iostream>
#include "journal.hpp"

int main() {
  journal c("kirill", 1);
  c.save_mess("hello", 2);
  c.print_info();
  c.save_file();
}
