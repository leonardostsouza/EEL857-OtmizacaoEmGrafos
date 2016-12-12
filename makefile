CC=g++-5

MAIN_FILE=main.cpp
GRAPH_LIB=graph.cpp
GRAPH_HANDLER_LIB=graphHandler.cpp

MAIN_OBJ_FILE=main.o
GRAPH_LIB_OBJ_FILE=graph.o
GRAPH_HANDLER_LIB_OBJ_FILE=graphHandler.o

default:
	$(CC) -c $(GRAPH_LIB) -o $(GRAPH_LIB_OBJ_FILE) -Wall
	$(CC) -c $(GRAPH_HANDLER_LIB) -o $(GRAPH_HANDLER_LIB_OBJ_FILE) -Wall
	$(CC) -c $(MAIN_FILE) -o $(MAIN_OBJ_FILE) -Wall
	$(CC) $(MAIN_OBJ_FILE) $(GRAPH_LIB_OBJ_FILE) $(GRAPH_HANDLER_LIB_OBJ_FILE) -o main -Wall

run:
	$(CC) -c $(GRAPH_LIB) -o $(GRAPH_LIB_OBJ_FILE) -Wall
	$(CC) -c $(GRAPH_HANDLER_LIB) -o $(GRAPH_HANDLER_LIB_OBJ_FILE) -Wall
	$(CC) -c $(MAIN_FILE) -o $(MAIN_OBJ_FILE) -Wall
	$(CC) $(MAIN_OBJ_FILE) $(GRAPH_LIB_OBJ_FILE) $(GRAPH_HANDLER_LIB_OBJ_FILE) -o main -Wall
	./main

clean:
	rm graph.o
	rm graphHandler.o
	rm main.o
	rm main