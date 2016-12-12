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

	// Aleatorio - Modelo G(n, p)
	//Graph g("graph_files/Gnp/DSJC125.1.col");
	//Graph g("graph_files/Gnp/DSJC250.1.col");

	// k-insertions
	//Graph g("graph_files/Ins/1-Insertions_4.col");
	//Graph g("graph_files/Ins/1-FullIns_4.col");
	//Graph g("graph_files/Ins/3-FullIns_3.col");

	// Grafos Reais
	//Graph g("graph_files/Real/jean.col");



	//Graph g("graph_files/test.col");
	// Graph g("graph_files/test2.col");
	// Graph g("graph_files/test3.col");
	cout << g.size() << endl;
	GraphHandler gh(&g);

	gh.h_colour();

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

	// unsigned int upperLimit = 0;

	// gh.bt_colour(0, 1, &upperLimit);

	// g = gh.getSolution();

	// // print solution
	// std::cout << "+++++++++++++++++++ BEST SOLUTION +++++++++++++++++++" << std::endl;
	// std::cout << "=== USED " << gh.getQttColours() << " COLOURS ===" << std::endl;
	// for(unsigned int i = 1; i < g.size() + 1; i++){
	// 	std::cout << "Vertex (" << i << ", " << g.vertex(i)->getColour() << ") ==> ";
	// 	for(unsigned int j = 0; j<g.vertex(i)->getNeighbors().size(); j++){
	// 		unsigned int n = g.vertex(i)->getNeighbors()[j];
	// 		std::cout << "(" << n << ", " << g.vertex(n)->getColour() << ") ";
	// 	}
	// 	std::cout << std::endl;
	// }

	cout << "Usou " << gh.getQttColours() << " cores" << endl;

	return 0;
}