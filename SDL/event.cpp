//
// event.cpp for event in /home/roche_b/rendu/cpp_nibbler/SDL
// 
// Made by charly roche
// Login   <roche_b@epitech.net>
// 
// Started on  Thu Apr  3 11:52:02 2014 charly roche
// Last update Sun Apr  6 13:18:35 2014 charly roche
//

#include "event.hh"

Events::Events() {}

Events::Events(Snake *s)
{
  _snake = s;
  _event[SDLK_UP] = &Events::mooveUp;
  _event[SDLK_LEFT] = &Events::mooveLeft;
  _event[SDLK_DOWN] = &Events::mooveDown;
  _event[SDLK_RIGHT] = &Events::mooveRight;
  _event[SDLK_ESCAPE] = &Events::quit;
  _event[SDLK_k] = &Events::changeMoove;
}

Events::~Events() {}

void		Events::mooveUp()
{
  _snake->setDir(UP);
}

void		Events::mooveDown()
{
  _snake->setDir(DOWN);
}

void		Events::mooveLeft()
{
  _snake->setDir(LEFT);
}

void		Events::mooveRight()
{
  _snake->setDir(RIGHT);
}

void		Events::quit()
{
  _snake->setEnd();
}

void		Events::changeMoove()
{
  _snake->setProgKey();
}

void		Events::checkEvents(SDLKey e1)
{
  int		a;
  std::map<SDLKey, void (Events::*)()>::iterator it;
  
  a = 0;
  for (it = _event.begin(); it != _event.end(); ++it)
    ++a;
  if (_event.find(e1)->first != a)
    {
      (this->*_event[e1])();
    }
}
