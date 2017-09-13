//
// main.cpp for  in /home/souman_a//Desktop/my_project/ZAPPY
// 
// Made by abd-el-moxine soumanou
// Login   <souman_a@epitech.net>
// 
// Started on  Tue May 31 14:12:25 2011 abd-el-moxine soumanou
// Last update Sun Jul 10 20:11:38 2011 adrien barrau
//

#include	<sstream>
#include	<iostream>
#include	"Core.hh"

int	main(int argc, char **argv)
{
  QApplication  app(argc, argv);
  int port;
  std::stringstream ss;
  if (argc == 3)
    {
      ss << argv[2];
      ss >> port;
      Core c(argv[1], port);
      c.ex();
    }
  else
    std::cout << "Usage: ./client_graphic IP PORT" << std::endl;
  return (0);
}
