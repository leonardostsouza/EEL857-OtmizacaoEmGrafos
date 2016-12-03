#include <iostream>
#include <vector>
#include "graph.hpp"

#ifndef __GRAPH_HANDLER_H__
#define __GRAPH_HANDLER_H__

class GraphHandler{
public:
	GraphHandler(Graph* inputGraph);

	void h_colour(); // colorir grafo usando heuristica
	void bb_colour(); // colorir grafo usando branch-and-bound
	void bt_colour(unsigned int vertexIndex, unsigned int usedColours, unsigned int * upperLimit); // colorir grafo usando backtrack

	Graph getSolution();
	unsigned int getQttColours();

private:
	Graph * G;
	Graph Solution;
	unsigned int qttColours;
	bool promissing(unsigned int vertex, unsigned int colour);
	void storeSolution();
};

#endif
