#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct journal {
  std::string name;
  int lvl;
  std::string lvl_name;
  int server;
  sockaddr_in addr;
  journal(std::string name_init, int l_init);
  journal(std::string name_init, int l_init, std::string addr_init, int server);
  void save_mess(std::string mess, int l);
  void change_lvl(int new_lvl);
};

#endif
