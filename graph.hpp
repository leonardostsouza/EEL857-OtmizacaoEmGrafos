#include <iostream>
#include <fstream>
#include <vector>

#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex{
public:
	Vertex();
	~Vertex();

	void setColour(unsigned int newColour);
	unsigned int getColour();

	void createNeighbor(unsigned int neighborId);
	void deleteNeighbor(unsigned int neighborId);
	std::vector<unsigned int> getNeighbors();

	void setMark(unsigned int newValue);
	bool getMark();

private:
	unsigned int colour;
	unsigned int mark;
	std::vector<unsigned int> neighbors; 
};

#endif

#ifndef __GRAPH_H__
#define __GRAPH_H__

class Graph{
public:
	Graph(fstream inputFile);
	~Graph();

	void createEdge(unsigned int source, unsigned int target);
	void deleteEdge(unsigned int source, unsigned int target);

private:
	std::vector<std::vector<Vertex>> graphStructure;
};

#endif