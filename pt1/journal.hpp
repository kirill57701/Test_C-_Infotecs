#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

struct journal {
  std::string name;
  int lvl;
  std::string lvl_name;
  std::ofstream out;
  journal(std::string name_init, int l_init);
  void save_mess(std::string mess, int l);
  void change_lvl(int new_lvl);
};

#endif
