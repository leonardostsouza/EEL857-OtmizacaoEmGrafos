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

	for(int i = 1; i < g.size(); i++){
		cout << g.vertex(i).degree() << endl;
	}

	return 0;
}