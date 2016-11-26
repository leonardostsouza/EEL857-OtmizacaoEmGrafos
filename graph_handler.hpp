#include <iostream>
#include <vector>
#include "graph.h"

#ifndef __GRAPH_HANDLER__
#define __GRAPH_HANDLER__

class GraphHandler{
public:
	GraphHandler(Graph* inputGraph);
	~GraphHandler();

	void h_colour(); // colorir grafo usando heuristica
	void bb_colour(); // colorir grafo usando branch-and-bound

private:
	Graph * G;
};

#endif