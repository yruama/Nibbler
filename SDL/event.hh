#ifndef EVENT_HH
# define EVENT_HH

#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include "SDL/SDL.h"
#include "../Algorithm/snake.hh"

class	Events
{
public:
  Events();
  Events(Snake*);
  ~Events();
  
  void		mooveUp();
  void		mooveRight();
  void		mooveLeft();
  void		mooveDown();
  void		quit();
  void		changeMoove();
  void		checkEvents(SDLKey);

private:
  std::map<SDLKey, void (Events::*)()>	_event;
  Snake *_snake;
};

#endif
