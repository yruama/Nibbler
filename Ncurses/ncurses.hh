//
// ncurses.hh for ncurses in /home/roche_b/rendu/cpp_nibbler/Ncurses
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Wed Apr  2 15:58:49 2014 charly roche
// Last update Wed Apr  2 17:03:33 2014 charly roche
//

#ifndef NCURSES_H_
# define NCURSES_H_

#include <list>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ncurses.h>
#include <unistd.h>
#include "../Algorithm/IGrafic.h"
#include "../Algorithm/snake.hh"
#include "../Algorithm/fruit.hh"

class	Map : public IGrafic
{
public:
  Map(int, int);
  ~Map();

  void		init();
  int		checkSnake(Snake s, int x, int y);
  void		displayMap(Snake s, Fruit f, WINDOW *win);
  void		event();

private:
  int		tailleY;
  int		tailleX;
  int		boost;
};

#endif /* NCURSES_H_ */
