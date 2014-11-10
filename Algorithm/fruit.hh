//
// fruit.hh for fruit in /home/roche_b/rendu/cpp_nibbler/SDL
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Tue Mar 18 14:36:57 2014 charly roche
// Last update Tue Mar 18 18:37:49 2014 charly roche
//

#ifndef FRUIT_H_
# define FRUIT_H_

#include <list>
#include <iostream>

class	Fruit
{
public:
  Fruit(int, int);
  Fruit();
  ~Fruit();
  void	setPos(std::list<std::pair<int, int> >, int);
  int	getX();
  int	getY();

private:
  int	_max_x;
  int	_max_y;
  int	_x;
  int	_y;

  int	check_pos(std::list<std::pair<int, int> >, int, int, int);
};

#endif /* FRUIT_H_ */
