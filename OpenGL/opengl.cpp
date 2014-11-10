
//
// sdl.cpp for sdl in /home/roche_b/rendu/cpp_nibbler/SDL
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Wed Mar 19 00:18:34 2014 charly roche
// Last update Sun Apr  6 11:57:36 2014 charly roche
//

#include "opengl.hh"
#include "event.hh"

Map::Map(int x, int y) : IGrafic()
{
  tailleX = x;
  tailleY = y;
  ta = 0;
  tp = 0;
  boost = 100;
}

void		Map::init()
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Nibbler",NULL);
  SDL_SetVideoMode(tailleX * 15, tailleY * 15, 32, SDL_OPENGL);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluOrtho2D(0,tailleX,0,tailleY);
  event();
  SDL_Quit();
}

Map::~Map()
{
  std::cout << "End of Nibbler" << std::endl;
}

void		Map::completeMap(Snake &s, Fruit &f)
{
  std::list<std::pair<int, int>	> p;
  int		x;

  p = s.getSnake();
  x = s.getSize() + 1;
  drawFruit(f.getX(), f.getY());
  while (--x > 0)
    {
      drawSnake(p.front().first + 1, p.front().second + 1);
      p.pop_front();
    }
}

void		Map::drawSnake(int x, int y)
{
  glBegin(GL_QUADS);
  glColor3ub(0,0,255);
  glVertex2d(x, y);
  glVertex2d(x, y - 1);
  glVertex2d(x - 1, y - 1);
  glVertex2d(x - 1, y);
  glEnd();
  glFlush();
}

void		Map::drawFruit(int x, int y)
{
  glBegin(GL_QUADS);
  glColor3ub(0,255,0);
  glVertex2d(x + 1, y + 1);
  glVertex2d(x + 1, y);
  glVertex2d(x, y);
  glVertex2d(x, y + 1);
  glEnd();
  glFlush();
}

void		Map::tempo(Snake *s, Fruit *f)
{
  ta = SDL_GetTicks();
  if (ta - tp > boost)
    {
      glClear(GL_COLOR_BUFFER_BIT);
      glClear(GL_COLOR_BUFFER_BIT);
      s->forward();
      s->gameOver(s->getSnake());
      s->setLastDir();
      tp = ta;
      completeMap(*s, *f);
    }
}

void		Map::event()
{
  Snake		s(tailleX, tailleY);
  Fruit		f(tailleX, tailleY);
  Events	e(&s);

  f.setPos(s.getSnake(), s.getSize());
  while (s.getEnd())
    {
      tempo(&s, &f);
      while (SDL_PollEvent(&my_event))
	{
	  if (my_event.type == SDL_QUIT)
	    s.setEnd();
	  if (my_event.key.type == SDL_KEYDOWN)
	    e.checkEvents(my_event.key.keysym.sym);
	}
      if (s.getSnake().front().first == f.getX() && s.getSnake().front().second == f.getY())
        {
          s.eat();
          f.setPos(s.getSnake(), s.getSize());
        }
      SDL_GL_SwapBuffers();
      SDL_GL_SwapBuffers();
    }
}

extern "C"
{
  IGrafic* create_obj(int x, int y)
  {
    return (new Map(x, y));
  }
}
