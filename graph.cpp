#include "graph.hpp"

/////////////////////// VERTEX /////////////////////////////

Vertex::Vertex(){
	this->mark = 0;
	this->colour = 0;
}

void Vertex::setColour(unsigned int newColour){
	this->colour = newColour;
}

unsigned int Vertex::getColour(){
	return this->colour;
}

void Vertex::createNeighbor(unsigned int neighborId){
	this->neighbors.push_back(neighborId);
}

void Vertex::deleteNeighbor(unsigned int neighborId){
	for (int i = 0; i<this->neighbors.size(); i++){
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
	this->mark = newValue;
}

bool Vertex::getMark(){
	return mark;
}

unsigned int Vertex::degree(){
	return this->neighbors.size();
}

/////////////////////////////////////////////////////////////


/////////////////////// GRAPH /////////////////////////////

Graph::Graph(std::string inputFileName){
	char *pEnd; // pointer to end of line parsing. used on strtol
	unsigned int source, target;
	std::string line;

	std::ifstream inputFile;
	inputFile.open(inputFileName.c_str());

	while (!inputFile.eof()){
		getline(inputFile, line);

		//read source and target of edge
		if (line.c_str()[0] == 'e'){
			source = (unsigned int)strtol(&line.c_str()[1], &pEnd, 10);
			target = (unsigned int)strtol(pEnd, NULL, 10);

			createEdge(source, target);
		}
		else if (line.c_str()[0] == 'p') {
			this->myGraph.resize((strtol(&line.c_str()[6], NULL, 10)) + 1);
		}

	}

	inputFile.close();
}

void Graph::createEdge(unsigned int source, unsigned int target){
	myGraph[source - 1].createNeighbor(target);
	myGraph[target - 1].createNeighbor(source);
}

void Graph::deleteEdge(unsigned int source, unsigned int target){
	myGraph[source - 1].deleteNeighbor(target);
	myGraph[target - 1].deleteNeighbor(source);
}


unsigned int Graph::size(){
	return myGraph.size();
}

Vertex Graph::vertex(unsigned int vertexId){
	if (((vertexId - 1) < 0) || ((vertexId - 1) > myGraph.size())){
		std::cerr << "ERROR: Graph::vertex() ==> Index out of range" << std::endl;
	}

	return myGraph.at(vertexId - 1);
}

void Graph::sort(){
	std::sort(myGraph.begin(), myGraph.end());
}

void Graph::reverse(){
	std::reverse(myGraph.begin(), myGraph.end());
}
/////////////////////////////////////////////////////////////