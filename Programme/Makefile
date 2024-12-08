# Variables
CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRCS = N_Cell.cpp Obs_Cell.cpp Cell.cpp Grid.cpp Graphic.cpp Console.cpp Game.cpp File.cpp Controller.cpp View.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)
EXEC = main

# Règle par défaut : compilation et exécution
all: $(EXEC)
	./$(EXEC)

# Compilation du programme principal
$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXEC)

# Compilation des fichiers source en objets
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers objets et exécutables
clean:
	rm -f $(OBJS) $(EXEC)

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(EXEC)

# Recompiler tout à partir des sources
re: fclean all
