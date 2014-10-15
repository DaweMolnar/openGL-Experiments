CC=g++
CFLAGS = \
				-std=c++11 \
				-Wall \
				-Wpedantic \
				-Wextra \
				-g

INCLUDES= \
	-I. \
	-I/usr/include/ \
	-I/usr/local/include/GLFW

LIBDIR  = -L/usr/X11R6/lib -L/usr/local/lib/

LIBS = -lstdc++ -lglut -lGL -lGLU -lGLEW -lglfw -lm

# DEPS = Enemy.h \

OBJ = experiment.o

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

experiment: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBDIR) $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *~ experiment core
