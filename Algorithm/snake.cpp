//
// snake.cpp for snake in /home/roche_b/nibbler/NEW
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Mon Mar 17 23:08:53 2014 charly roche
// Last update Sun Apr  6 22:33:54 2014 charly roche
//

#include "snake.hh"

Snake::Snake(int x, int y)
{
  _eat = 0;
  _x = x;
  _y = y;
  _dir = RIGHT;
  _size = 4;
  _prog_key = 0;
  _end = 1;
  _boost = 100;
  _snake.push_front(std::pair<int, int> (x/2 - 4, y/2));
  _snake.push_front(std::pair<int, int> (x/2 - 3, y/2));
  _snake.push_front(std::pair<int, int> (x/2 - 2, y/2));
  _snake.push_front(std::pair<int, int> (x/2 - 1, y/2));
}

Snake::Snake() {}

Snake::~Snake() {}

std::list<std::pair<int, int> >	Snake::getSnake() const
{
  return (_snake);
}

int				Snake::getSize() const
{
  return (_size);
}

int				Snake::getEnd() const
{
  return(_end);
}

void				Snake::move(int x, int y)
{
  x = _snake.front().first + x;
  y = _snake.front().second + y;
  _snake.push_front(std::pair<int, int> (x, y));
  if (_eat)
    {
      --_eat;
      _size++;
    }
  else
    _snake.pop_back();
}

void				Snake::forward()
{

  if (_dir == UP)
    move(0, -1);
  else if (_dir == DOWN)
    move(0, 1);
  else if (_dir == RIGHT)
    move(1, 0);
  else if (_dir == LEFT)
    move(-1, 0);
}

void				Snake::setDir(int dir)
{
  if (_prog_key)
    {
      if (dir == UP)
	if (_last_dir != DOWN)
	  _dir = dir;
      if (dir == DOWN)
	if (_last_dir != UP)
	  _dir = dir;
      if (dir == RIGHT)
	if (_last_dir != LEFT)
	  _dir = dir;
      if (dir == LEFT)
	if (_last_dir != RIGHT)
	  _dir = dir;
    }
  else
    {
      if (dir == LEFT)
	_dir = (_dir + 3) % 4;
      if (dir == RIGHT)
	_dir = (_dir + 1) % 4;
    }
}

void				Snake::setLastDir()
{
  _last_dir = _dir;
}

void				Snake::setProgKey()
{
  _prog_key = !_prog_key;
}

void				Snake::gameOver(std::list<std::pair<int, int> > l)
{
  int				x, y = 0;
  
  x = l.front().first;
  y = l.front().second;
  l.pop_front();
  while (!l.empty())
    {
      if (l.front().first == x && l.front().second == y)
	{
	  std::cout << "GAME OVER !\nMiiiiiiiaaaam." << std::endl;
	  _end = 0;
	}
      l.pop_front();
    }
  if (_snake.front().first == _x || _snake.front().first < 0 ||
      _snake.front().second == _y || _snake.front().second < 0)
    {
      std::cout << "GAME OVER !\nAïïïïïïïïïïïïïïïe !" << std::endl;
      _end = 0;
    }
}

void				Snake::eat()
{
  _eat = 1;
}

void				Snake::setEnd()
{
  _end = 0;
}

void				Snake::setBoost()
{
  if (_boost == 50)
    _boost = 100;
  if (_boost == 100)
    _boost = 50;
}

int				Snake::getBoost() const
{
  return (_boost);
}

int				Snake::getX() const
{
  return (_x);
}

int				Snake::getY() const
{
  return (_y);
}

int				Snake::getProgKey() const
{
  return (_prog_key);
}
