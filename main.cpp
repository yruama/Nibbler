#include "SDL/sdl.hh"
#include "SDL/SDL.h"
#include <stdio.h>
#include <dlfcn.h>
#include <cstdlib>
#include <iostream>
#include "./inc/fmod.h"
#include "Algorithm/IGrafic.h"

void		my_error(std::string str)
{
  std::cout << str << std::endl;
  std::exit(0);
}

void		my_play()
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*musique;
  FMOD_RESULT	resultat;

  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  resultat = FMOD_System_CreateSound(system, "nyan_cat.mp3", 
  FMOD_LOOP_NORMAL |FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  if (resultat != FMOD_OK)
    my_error("Open mp33 file failed.");
  FMOD_Sound_SetLoopCount(musique, -1);
  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
}

void		myCheckError(char **av)
{
  if (atoi(av[1]) < 10 || atoi(av[2]) < 10)
    my_error("Windows too small. Usage : X [10 - 90] Y [10 - 50]");
  if (atoi(av[1]) > 95 || atoi(av[2]) > 50)
    my_error("Windows too long. Usage :  X [10 - 90] Y [10 - 50]");
}

int		main(int ac, char **av)
{
  IGrafic*	(*create)(int, int);
  void		*dlhandle;
  
  if (ac < 3)
    my_error("Usage : WIDTH HEIGHT LIBRARY");
  myCheckError(av);
  dlhandle = dlopen(av[3], RTLD_LAZY);
  if (dlhandle == NULL)
    my_error("Library doesnt exist.");
  create = reinterpret_cast<IGrafic * (*)(int, int)>(dlsym(dlhandle, "create_obj"));
  if (create == NULL)
    my_error("Create Object Failed.");
  IGrafic*	test = create(atoi(av[1]), atoi(av[2]));
    my_play();

  test->init();
  dlclose(dlhandle);
  return (0);
}
