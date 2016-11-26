#include "graph.h"

/////////////////////// VERTEX /////////////////////////////

Vertex::Vertex(){
	this.mark = 0;
	this.colour = 0;
}

void Vertex::setColour(unsigned int newColour){
	this.colour = newColour;
}

unsigned int Vertex::getColour(){
	return this.colour;
}

void Vertex::createNeighbor(unsigned int neighborId){
	this.neighbors.push_back(neighborId);
}

void Vertex::deleteNeighbor(unsigned int neighborId){
	for (int i = 0; i<this.neighbors.size(); i++){
		if(neighbors[i] == neighborId){
			neighbors[i] = neighbors.back();
			neighbors.pop_back();
			i = neighbors.size()+1;
		}
	}
}

std::vector<unsigned int> Vertex::getNeighbors(){
	return neighbors;
}

void Vertex::setMark(unsigned int newValue){
	this.mark = newValue;
}

bool Vertex::getMark(){
	return mark;
}

unsigned int degree(){
	return this.neighbors.size();
}

/////////////////////////////////////////////////////////////




/////////////////////// GRAPH /////////////////////////////

Graph::Graph(fstream inputFile){
	// read file
}

void Graph::createEdge(unsigned int source, unsigned int target){
	myGraph[source].createNeighbor(target);
	myGraph[target].createNeighbor(source);
}

void Graph::deleteEdge(unsigned int source, unsigned int target){
	myGraph[source].deleteNeighbor(target);
	myGraph[target].deleteNeighbor(source);
}


unsigned int Graph::size(){
	return myGraph.size();
}

Vertex Graph::vertex(unsigned int vertexId){
	return myGraph.at(vertexId);
}

void Graph::sort(){
	std::sort(myGraph.begin(), myGraph.end());
}

void Graph::reverse(){
	std::reverse(myGraph.begin(), myGraph.end());
}
/////////////////////////////////////////////////////////////