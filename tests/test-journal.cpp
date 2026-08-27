#include "../pt1/journal.hpp"
#include <string>

template<class T>
int is_eq(T a, T b) {
  if (a != b) {
    return 1;
  }
  return 0;
}

int test_init_us() {
  std::string s = "hello";
  int c = 1, d = 0;
  journal master{s, c};
  d += is_eq(1, master.lvl);
  d += is_eq<std::string>("hello", master.name);
  d += is_eq<std::string>("usual", master.lvl_name);
  return d;
}

int test_init_at() {
  std::string s = "hello";
  int c = 2, d = 0;
  journal master{s, c};
  d += is_eq(2, master.lvl);
  d += is_eq<std::string>("hello", master.name);
  d += is_eq<std::string>("attention", master.lvl_name);
  return d;
}

int test_init_er() {
  std::string s = "hello";
  int c = 3, d = 0;
  journal master{s, c};
  d += is_eq(3, master.lvl);
  d += is_eq<std::string>("hello", master.name);
  d += is_eq<std::string>("err", master.lvl_name);
  return d;
}

int test_change_lvl() {
  std::string s = "hello";
  int c = 1, d = 0;
  journal master{s, c};
  d += is_eq(1, master.lvl);
  d += is_eq<std::string>("hello", master.name);
  d += is_eq<std::string>("usual", master.lvl_name);
  master.change_lvl(3);
  d += is_eq(3, master.lvl);
  d += is_eq<std::string>("hello", master.name);
  d += is_eq<std::string>("err", master.lvl_name);
  master.change_lvl(2);
  d += is_eq(2, master.lvl);
  d += is_eq<std::string>("hello", master.name);
  d += is_eq<std::string>("attention", master.lvl_name);
  return d;
}

int main() {
  if (test_init_us()) {
    std::cerr << "err, test not pass\n";
    return -1;
  }
  if (test_init_at()) {
    std::cerr << "err, test not pass\n";
    return -1;
  }
  if (test_init_er()) {
    std::cerr << "err, test not pass\n";
    return -1;
  }
  if (test_change_lvl()) {
    std::cerr << "err, test not pass\n";
    return -1;
  }
  std::cout << "tests passed good\n";
}
