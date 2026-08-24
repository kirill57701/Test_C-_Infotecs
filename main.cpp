#include <iostream>
#include "journal.hpp"

int main() {
  journal c("kirill", 1);
  c.save_mess("hello", "22-08-2026 12:38", 2);
  c.print_info();
}
