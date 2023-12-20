# Everything else
#CC = g++

# OpenBSD
CC = clang++ 

WARNINGS = -Wall -Wpointer-arith \
	-Wcast-align -Wwrite-strings \
	-Wmissing-declarations -Wredundant-decls 

# FreeBSD & OpenBSD
INCS = -I/usr/local/include
LIBS = -L/usr/local/lib

X11INCS = -I/usr/X11R6/include
X11LIBS = -L/usr/X11R6/lib

# NetBSD
#INCS = -I/usr/include
#LIBS = -L/usr/lib

LDFLAGS = -lc++ -lX11 -lfltk -lm $(LIBS) $(X11LIBS)
CFLAGS = $(WARNINGS) $(INCS) $(X11INCS) -std=c++98 -O0 -g

all:
	$(CC) $(CFLAGS) src/main.cpp -c
	$(CC) $(CFLAGS) src/Window.cpp -c
	$(CC) $(CFLAGS) src/System.c -c
	$(CC) $(CFLAGS) $(LDFLAGS) main.o Window.o System.o
