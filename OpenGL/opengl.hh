/*
** sdl.h for sdl in /home/roche_b/rendu/cpp_nibbler/SDL
** 
** Made by charly roche
** Login   <roche_b@epitech.net>
** 
** Started on  Wed Mar 19 00:15:42 2014 charly roche
// Last update Wed Mar 19 01:16:33 2014 charly roche
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
#include "GL/gl.h"
#include "GL/glu.h"

enum Type { EMPTY, SNAKE, FRUIT };

class	Map : public IGrafic
{
 public:
  Map(int, int);
  ~Map();

  void			init();
  void			event();
  void			completeMap(Snake &, Fruit &);
  void			drawSnake(int, int);
  void			drawFruit(int, int);
  void			tempo(Snake*, Fruit*);
private:
  SDL_TimerID			timer;
  SDL_Event			my_event;
  int				tailleY;
  int				tailleX;
  int				boost;
  int				ta;
  int				tp;
  int			        smith;
};

#endif
