//
// fruit.cpp for fruit in /home/roche_b/rendu/cpp_nibbler/SDL
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Tue Mar 18 14:37:04 2014 charly roche
// Last update Wed Mar 19 00:56:28 2014 charly roche
//

#include <stdlib.h>
#include <time.h>
#include "fruit.hh"

Fruit::Fruit(int max_x, int max_y)
{
  _max_x = max_x;
  _max_y = max_y;
}

Fruit::Fruit () {}

Fruit::~Fruit() {}

int	Fruit::check_pos(std::list<std::pair<int, int> > s, int x, int y, int size)
{
  while (--size >= 0)
    {
      if (s.front().first == x && s.front().second == y)
	return (0);
      s.pop_front();
    }
  return (1);
}

void	Fruit::setPos(std::list<std::pair<int, int> > s, int size)
{
  srand(time(NULL));
  _x = rand() % _max_x;
  _y = rand() % _max_y;
  while (!check_pos(s, _x, _y, size))
    {
      _x = rand() % _max_x;
      _y = rand() % _max_y;
    }
}

int	Fruit::getX()
{
  return (_x);
}

int	Fruit::getY()
{
  return (_y);
}
