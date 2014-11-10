//
// snake.hh for snake in /home/roche_b/nibbler/NEW
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Mon Mar 17 22:45:55 2014 charly roche
// Last update Sun Apr  6 22:42:02 2014 charly roche
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

#include <iostream>
#include <list>
#include <cstdlib>

enum { UP, RIGHT, DOWN, LEFT };

class	Snake
{
public:
  Snake();
  Snake(int, int);
  ~Snake();

  std::list<std::pair<int, int> >	getSnake() const;
  int					getSize() const;
  int					getEnd() const;
  int					getBoost() const;
  int					getX() const;
  int					getY() const;
  int					getProgKey() const;
  void					setEnd();
  void					setLastDir();
  void					setProgKey();
  void					setBoost();
  void					setDir(int dir);
  void					gameOver(std::list<std::pair<int, int> >);
  void					eat();
  void					forward();

private:
  std::list<std::pair<int, int> >	_snake;
  int					_dir;
  int					_last_dir;
  int					_size;
  int					_y;
  int					_x;
  int					_eat;
  int					_end;
  int					_prog_key;
  int					_boost;
  void					move(int x, int y);
};

#endif /* SNAKE_HH_ */
