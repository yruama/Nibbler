//
// ncurses.cpp for ncurses in /home/roche_b/rendu/cpp_nibbler/Ncurses
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Wed Apr  2 15:02:11 2014 charly roche
// Last update Sun Apr  6 11:37:51 2014 charly roche
//

#include "ncurses.hh"

Map::Map(int x, int y) : IGrafic()
{
  tailleX = x;
  tailleY = y;
}

void		Map::init()
{
  initscr();
  noecho();
  event();
  echo();
  endwin();
}

int		Map::checkSnake(Snake s, int x, int y)
{
  std::list<std::pair<int, int> > p;
  int		i;

  p = s.getSnake();
  i = s.getSize() + 1;
  while (--i > 0)
    {
      if (p.front().first == x && p.front().second == y)
	return (1);
      p.pop_front();
    }
  return (0);
}

void	Map::displayMap(Snake s, Fruit f, WINDOW *win)
{
  int	x;
  int	y;

  wclear(win);
  y = -1;
  while (++y < s.getY())
    {
      x = -1;
      while (++x < s.getX())
	{
	  wmove(win, y + 1, x + 1);
	  if (checkSnake(s, x, y))
	    wprintw(win, "M");
	  else if (f.getX() == x && f.getY() == y)
	    wprintw(win, "O");
	}
    }
  wattron(win, A_REVERSE);
  box(win, ' ', ' ');
  wattroff(win, A_REVERSE);
  wrefresh(win);
  refresh();
}

void		Map::event()
{
  Snake		s(tailleX, tailleY);
  Fruit		f(tailleX, tailleY);
  int		ch;
  WINDOW	*win;

  f.setPos(s.getSnake(), s.getSize());
  win = newwin(tailleY + 2, tailleX + 2, 0, 0);
  while (s.getEnd())
    {
      s.forward();
      s.setLastDir();
      s.gameOver(s.getSnake());
      if (s.getEnd())
	{
	  displayMap(s, f, win);
	  timeout(200);
	  ch = getch();
	  if (ch == 27)
	    {
	      ch = getch();
	      ch = getch();
	    }
	  if (ch == 68)
	    s.setDir(LEFT);
	  else if (ch == 65)
	    s.setDir(UP);
	  else if (ch == 66)
	    s.setDir(DOWN);
	  else if (ch == 67)
	    s.setDir(RIGHT);
	  else if (ch == 'k')
	    s.setProgKey();
	  else if (ch == 27)
	    s.setEnd();
	  if (s.getSnake().front().first == f.getX() && s.getSnake().front().second  == f.getY())
	    {
	      s.eat();
	      f.setPos(s.getSnake(), s.getSize());
	    }
	}
    }
  delwin(win);
}

extern "C"
{
  IGrafic* create_obj(int x, int y)
  {
    return (new Map(x, y));
  }
}
