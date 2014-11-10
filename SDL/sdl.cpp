//
// sdl.cpp for sdl in /home/roche_b/rendu/cpp_nibbler/SDL
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Wed Mar 19 00:18:34 2014 charly roche
// Last update Sun Apr  6 11:35:43 2014 charly roche
//

#include "sdl.hh"
#include "event.hh"

Map::Map(int x, int y) : IGrafic()
{
  tailleX = x;
  tailleY = y;
  tete = NULL;
  serpent = NULL;
  background = NULL;
  windows = NULL;
  ta = 0;
  tp = 0;
}

void		Map::init()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    std::exit(0);
  windows = SDL_SetVideoMode(tailleX * 20, tailleY * 20, 32, SDL_SWSURFACE);
  if (windows == NULL)
    std::exit(0);
  SDL_WM_SetCaption("Nibbler", NULL);
  event();
  SDL_FreeSurface(windows);
  SDL_Quit();
}

Map::~Map()
{
  std::cout << "End of Nibbler" << std::endl;
}

void		Map::initMap()
{
  tete = loadImage(TETE);
  SDL_SetColorKey(tete, SDL_SRCCOLORKEY, SDL_MapRGB(tete->format, 0, 255, 0));
  background = loadImage(BACKGROUND);
  serpent = loadImage(SERPENT);
  SDL_SetColorKey(serpent, SDL_SRCCOLORKEY, SDL_MapRGB(serpent->format, 0, 0, 0));
  fruit = loadImage(FRUITS);
  SDL_SetColorKey(fruit, SDL_SRCCOLORKEY, SDL_MapRGB(fruit->format, 0, 0, 0));
}

SDL_Surface	*Map::completeMap(Snake s, Fruit f)
{
  std::list<std::pair<int, int>	> p;
  int		x;

  p = s.getSnake();
  x = s.getSize() + 1;
  initMap();
  applySurface(0, 0, background, windows);
  applySurface(f.getX() * 20, f.getY() * 20, fruit, windows);
  while (--x > 0)
    {
      if (x == s.getSize())
	applySurface(p.front().first * 20, p.front().second * 20, tete, windows);
      else
	applySurface(p.front().first * 20, p.front().second * 20, serpent, windows);
      p.pop_front();
    }
  return (windows);
}

void		Map::myFreeSurface()
{
  SDL_FreeSurface(tete);
  SDL_FreeSurface(background);
  SDL_FreeSurface(serpent);
  SDL_FreeSurface(fruit);
}

void		Map::applySurface(int x, int y, SDL_Surface *src, SDL_Surface *dest)
{
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dest, &offset);
  SDL_FreeSurface(dest);
}

SDL_Surface	*Map::loadImage(std::string str)
{
  tamponImg = NULL;
  optiImg = NULL;
  tamponImg = IMG_Load(str.c_str());
  if (tamponImg != NULL)
    {
      optiImg = SDL_DisplayFormat(tamponImg);
      SDL_FreeSurface(tamponImg);
    }
  return (optiImg);
}

void		Map::tempo(Snake *s)
{
  ta = SDL_GetTicks();
  if (ta - tp > s->getBoost())
    {
      s->forward();
      s->gameOver(s->getSnake());
      s->setLastDir();
      tp = ta;
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
      windows = completeMap(s, f);
      if (SDL_Flip(windows) == -1)
	//	std::exit(0);
	s.setEnd();
      myFreeSurface();
      tempo(&s);
      while (SDL_PollEvent(&my_event))
	{
	  if (my_event.type == SDL_QUIT)
	    //std::exit(0);
	    s.setEnd();
	  if (my_event.key.type == SDL_KEYDOWN)
	    e.checkEvents(my_event.key.keysym.sym);
	}
      if (s.getSnake().front().first == f.getX() && s.getSnake().front().second == f.getY())
        {
          s.eat();
          f.setPos(s.getSnake(), s.getSize());
        }
    }
}

extern "C"
{
  IGrafic* create_obj(int x, int y)
  {
    return (new Map(x, y));
  }
}
