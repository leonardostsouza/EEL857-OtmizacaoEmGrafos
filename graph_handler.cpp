#include "graph_handler.hpp"

GraphHandler::GraphHandler(Graph* inputGraph){
	this.G = inputGraph;
}

GraphHandler::~GraphHandler(){
	free(this.G);
}

// colorir grafo usando heuristica
void GraphHandler::h_colour(){
	vector<unsigned int> colour;
	colour.push_back(1);
}

void GraphHandler::bb_colour(){
	// colorir grafo usando branch-and-bound
} 