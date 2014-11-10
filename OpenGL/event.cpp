#include "event.hh"
#include <algorithm>
#include <iterator>
#include <vector>

Events::Events() {}

Events::Events(Snake *s)
{
  _snake = s;
  _Map = false;
  _event[SDLK_UP] = &Events::mooveUp;
  _event[SDLK_LEFT] = &Events::mooveLeft;
  _event[SDLK_DOWN] = &Events::mooveDown;
  _event[SDLK_RIGHT] = &Events::mooveRight;
  _event[SDLK_ESCAPE] = &Events::quit;
  _event[SDLK_k] = &Events::changeMoove;
}

Events::~Events() {}

void            Events::quit()
{
  _snake->setEnd();
}

void            Events::changeMoove()
{
  _snake->setProgKey();
}

void		Events::Rien()
{
  std::cout << "oui" << std::endl;
}

void		Events::mooveUp()
{
  _snake->setDir(DOWN);
}

void		Events::mooveDown()
{
  _snake->setDir(UP);
}

void		Events::mooveLeft()
{
  if (_snake->getProgKey())
    _snake->setDir(LEFT);
  else
    _snake->setDir(RIGHT);
}

void		Events::mooveRight()
{
  if (_snake->getProgKey())
    _snake->setDir(RIGHT);
  else
    _snake->setDir(LEFT);
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
