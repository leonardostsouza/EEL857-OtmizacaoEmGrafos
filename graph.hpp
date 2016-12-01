#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex{
public:
	Vertex();

	void setColour(unsigned int newColour);
	unsigned int getColour();

	void createNeighbor(unsigned int neighborId);
	void deleteNeighbor(unsigned int neighborId);
	std::vector<unsigned int> getNeighbors();

	void setMark(unsigned int newValue);
	bool getMark();

	unsigned int degree();

	friend bool operator< (Vertex &v1, Vertex &v2){ return v1.degree() < v2.degree(); }
	friend bool operator> (Vertex &v1, Vertex &v2){ return v2 < v1; }
	friend bool operator<=(Vertex &v1, Vertex &v2){ return !(v1 > v2); }
	friend bool operator>=(Vertex &v1, Vertex &v2){ return !(v1 < v2); }

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
	Graph(std::string inputFile);

	void createEdge(unsigned int source, unsigned int target);
	void deleteEdge(unsigned int source, unsigned int target);

	unsigned int size();
	Vertex vertex(unsigned int vertexId); // returns specified vertex

	void sort();
	void reverse();

private:
	std::vector<Vertex> myGraph;
};

#endif