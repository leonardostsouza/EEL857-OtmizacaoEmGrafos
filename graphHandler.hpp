#include <iostream>
#include <vector>
#include <ctime>
#include "graph.hpp"

#ifndef __GRAPH_HANDLER_H__
#define __GRAPH_HANDLER_H__

class GraphHandler{
public:
	GraphHandler(Graph* inputGraph);

	unsigned int h_colour(); // colorir grafo usando heuristica. Retorna o número de cores usadas
	void bb_colour(); // colorir grafo usando branch-and-bound *** NÃO IMPLEMENTADO ***
	void bt_colour(unsigned int vertexIndex, unsigned int usedColours, unsigned int * upperLimit); // colorir grafo usando backtrack

	Graph getSolution();
	unsigned int getQttColours();

private:
	Graph * G;
	Graph Solution;
	unsigned int qttColours;
	time_t startingTime;
	time_t timeLimit;
	bool promissing(unsigned int vertex, unsigned int colour);
	void storeSolution();
};

#endif
