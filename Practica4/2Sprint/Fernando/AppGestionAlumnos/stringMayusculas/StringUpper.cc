#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::toupper


inr main(int argc, char const *argv[])
{

  std::locale loc;
  std::string str="Test String.\n";
  for (std::string::size_type i=0; i<str.length(); ++i)
    std::cout << std::toupper(str[i],loc);
  return 0;
	return 0;
}