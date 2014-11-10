/*
** sdl.h for sdl in /home/roche_b/rendu/cpp_nibbler/SDL
** 
** Made by charly roche
** Login   <roche_b@epitech.net>
** 
** Started on  Wed Mar 19 00:15:42 2014 charly roche
// Last update Wed Apr  2 16:11:01 2014 charly roche
*/

#ifndef SDL_H_
# define SDL_H_

#include <list>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "../Algorithm/IGrafic.h"
#include "../Algorithm/snake.hh"
#include "../Algorithm/fruit.hh"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"

# define BACKGROUND	"./SDL/img/background.png"
# define TETE		"./SDL/img/tete.png"
# define SERPENT	"./SDL/img/serpent.png"
# define FRUITS		"./SDL/img/fruit.png"

enum Type { EMPTY, SNAKE, FRUIT };

class	Map : public IGrafic
{
 public:
  Map(int, int);
  ~Map();

  void			init();
  void			event();
  void			applySurface(int, int, SDL_Surface*, SDL_Surface*);
  void			initMap();
  SDL_Surface		*completeMap(Snake, Fruit);
  SDL_Surface		*loadImage(std::string);
  void			myFreeSurface();
  void			tempo(Snake *);

private:
  SDL_Surface			*background;
  SDL_Surface			*tete;
  SDL_Surface			*serpent;
  SDL_Surface			*windows;
  SDL_Surface			*fruit;
  SDL_Surface			*tamponImg;
  SDL_Surface			*optiImg;
  SDL_TimerID			timer;
  SDL_Event			my_event;
  SDL_Rect			offset;
  int				tailleY;
  int				tailleX;
  int				boost;
  int				ta;
  int				tp;
  int			        smith;
};

#endif
