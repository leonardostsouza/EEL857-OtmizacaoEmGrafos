/*****************************
*
* Autor: Leonardo Souza
*
* Trabalho desenvolvido para a disciplina
* EEL 857 - Otimização em Grafos no segundo
* período de 2016
*
* Objetivo é criar um algoritmo exato 
* (Branch and Bound) e um não-exato 
* (heuristica) a fim de achar soluções
* para o problema de coloração de vértices
*
* Os grafos usados para testar os algoritmos
* podem ser encontrados em:
* 
* https://turing.cs.hbg.psu.edu/txn131/graphcoloring.html#graph_coloring
*
******************************/

#include "graph.hpp"
#include "graphHandler.hpp"

using namespace std;

int main(){

	Graph g("graph_files/test.col");
	// Graph g("graph_files/test2.col");
	// Graph g("graph_files/test3.col");

	GraphHandler gh(&g);

	//gh.h_colour();

	// // print solution
	// for(unsigned int i = 1; i < g.size() + 1; i++){
	// 	cout << "Vertex (" << i << ", " << g.vertex(i)->getColour() << ") ==> ";
	// 	for(unsigned int j = 0; j<g.vertex(i)->getNeighbors().size(); j++){
	// 		unsigned int n = g.vertex(i)->getNeighbors()[j];
	// 		cout << "(" << n << ", " << g.vertex(n)->getColour() << ") ";
	// 	}
	// 	cout << endl;
	// }



	//backtrack
	g.sort();
	g.reverse();

	unsigned int upperLimit = 0;

	gh.bt_colour(0, 1, &upperLimit);

	g = gh.getSolution();

	// print solution
	std::cout << "+++++++++++++++++++ BEST SOLUTION +++++++++++++++++++" << std::endl;
	std::cout << "=== USED " << gh.getQttColours() << " COLOURS ===" << std::endl;
	for(unsigned int i = 1; i < g.size() + 1; i++){
		std::cout << "Vertex (" << i << ", " << g.vertex(i)->getColour() << ") ==> ";
		for(unsigned int j = 0; j<g.vertex(i)->getNeighbors().size(); j++){
			unsigned int n = g.vertex(i)->getNeighbors()[j];
			std::cout << "(" << n << ", " << g.vertex(n)->getColour() << ") ";
		}
		std::cout << std::endl;
	}

	return 0;
}