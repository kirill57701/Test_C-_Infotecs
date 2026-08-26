#define BOOST_TEST_MODULE test_journal
#include <boost/test/included/unit_test.hpp>
#include "../pt1/journal.hpp"
#include <string>

BOOST_AUTO_TEST_CASE(test_init_us) {
  std::string s = "hello";
  int c = 1;
  journal master{s, c};
  BOOST_CHECK_EQUAL(1, master.lvl);
  BOOST_CHECK_EQUAL("hello", master.name);
  BOOST_CHECK_EQUAL("usual", master.lvl_name);
}

BOOST_AUTO_TEST_CASE(test_init_at) {
  std::string s = "hello";
  int c = 2;
  journal master{s, c};
  BOOST_CHECK_EQUAL(2, master.lvl);
  BOOST_CHECK_EQUAL("hello", master.name);
  BOOST_CHECK_EQUAL("attention", master.lvl_name);
}

BOOST_AUTO_TEST_CASE(test_init_er) {
  std::string s = "hello";
  int c = 3;
  journal master{s, c};
  BOOST_CHECK_EQUAL(3, master.lvl);
  BOOST_CHECK_EQUAL("hello", master.name);
  BOOST_CHECK_EQUAL("err", master.lvl_name);
}
