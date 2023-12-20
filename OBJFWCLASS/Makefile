# Everything else
#CC = gcc

# OpenBSD
CC = egcc 

WARNINGS = -Wall -Wextra

ALTWARNINGS =-Wshadow -Wpointer-arith \
	-Wcast-align -Wwrite-strings -Wmissing-prototypes \
	-Wmissing-declarations -Wredundant-decls -Wnested-externs \
	-Winline -Wuninitialized -Wconversion -Wstrict-prototypes \
	-Wpedantic -ansi

# OpenBSD & FreeBSD
INCS = -I/usr/local/include
LIBS = -L/usr/local/lib

# NetBSD
#INCS = -I/usr/include
#LIBS = -L/usr/lib

LDFLAGS = $(LIBS) -lc -lobjfw -lobjfwrt -lobjfwtls
CFLAGS = $(INCS) $(WARNINGS) \
	-std=c99 -O0 -g

all:
	$(CC) $(CFLAGS) src/main.m -c
	$(CC) $(CFLAGS) src/File/File.m -c
	$(CC) $(LDFLAGS) main.o File.o
