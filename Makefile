NAME_EXE = 	nibbler
SRC_EXE  = 	main.cpp
OBJ_EXE  = 	$(SRC_EXE:.cpp=.o)

NAME_SDL =	lib_nibbler_sdl.so
SRC_SDL  = 	SDL/sdl.cpp	 	\
		SDL/event.cpp		\
	  	Algorithm/snake.cpp	\
	  	Algorithm/fruit.cpp

OBJ_SDL  = 	$(SRC_SDL:.cpp=.o)

NAME_OGL = 	lib_nibbler_opengl.so
SRC_OGL  = 	OpenGL/opengl.cpp	\
	  	OpenGL/event.cpp	\
	  	Algorithm/snake.cpp	\
	  	Algorithm/fruit.cpp

OBJ_OGL  =	$(SRC_OGL:.cpp=.o)

NAME_NCU = 	lib_nibbler_ncurses.so
SRC_NCU  = 	Ncurses/ncurses.cpp	\
	  	Algorithm/snake.cpp	\
	  	Algorithm/fruit.cpp

OBJ_NCU  =	$(SRC_NCU:.cpp=.o)

LDFLAGS  =	-ldl 
CXXFLAGS =	-fPIC -lSDL -lSDLmain -lSDL_image -lGL -lGLU -lncurses

FMOD     =	./lib/libfmodex64.so

CXX      =	g++

all:		$(NAME_SDL) $(NAME_EXE) $(NAME_OGL) $(NAME_NCU) $(FMOD)

$(NAME_EXE):	$(OBJ_EXE)
		$(CXX) -o $(NAME_EXE) -export-dynamic $(OBJ_EXE) $(LDFLAGS) $(CXXFLAGS) $(FMOD)

$(NAME_SDL):	$(OBJ_SDL)
	        $(CXX) -shared -o $(NAME_SDL) $(OBJ_SDL) $(CXXFLAGS) $(FMOD)

$(NAME_OGL):	$(OBJ_OGL)
	        $(CXX) -shared -o $(NAME_OGL) $(OBJ_OGL) $(CXXFLAGS) $(FMOD)

$(NAME_NCU):	$(OBJ_NCU)
		$(CXX) -shared -o $(NAME_NCU) $(OBJ_NCU) $(CXXFLAGS) $(FMOD)

clean:
		rm -f $(OBJ_SDL) $(OBJ_EXE) $(OBJ_OGL) $(OBJ_NCU)

fclean:		clean
		rm -f $(NAME_EXE) $(NAME_SDL) $(NAME_OGL) $(NAME_NCU)

re:		fclean all
