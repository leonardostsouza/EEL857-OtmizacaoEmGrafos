#include <iostream>
#include <vector>
#include "graph.hpp"

#ifndef __GRAPH_HANDLER_H__
#define __GRAPH_HANDLER_H__

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
