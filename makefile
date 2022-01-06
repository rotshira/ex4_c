.PHONY = all clean
CC=gcc
OBJ=  dijkstra.o tsp.o graph.o main.o graph.h
NAME = main
CFLAGS = -Wall -Werror -g

all : graph
graph: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o graph  
nodes.o: nodes.c graph.h
	$(CC) $(CFLAGS) -c nodes.c
edges.o: edges.c graph.h
	$(CC) $(CFLAGS) -c edges.c
graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c
dijkstra.o: dijkstra.c graph.h
	$(CC) $(CFLAGS) -c dijkstra.c
tsp.o: tsp.c graph.h
	$(CC) $(CFLAGS) -c tsp.c
main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.a *.txt graph