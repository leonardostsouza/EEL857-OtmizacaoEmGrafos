#include "graph_handler.hpp"

GraphHandler::GraphHandler(Graph* inputGraph){
	this.G = inputGraph;
}

GraphHandler::~GraphHandler(){
	free(this.G);
}

// colorir grafo usando heuristica
void GraphHandler::h_colour(){
	std::vector<unsigned int> colour; // 0 se a cor não é usada e 1 se a cor é usada nas adjacencias
	colour.push_back(0); // inicializar com 1 cor

	// vértices em ordem decrescente de grau
	G->sort();
	G-> reverse();

	// colorir
	for (int i = 0; i<G->size(); i++){ 	// para cada vértice vi em G
		
		for (int j = 0; j < G->vertex(i).degree(); j++){	// para cada vizinho de vi
			// proibir cores usadas por vizinhos
			if (G->vertex(i).getColour() != 0){				
				colour[(G->vertex(i).getColour() -1)] = 1;
			}
		}

		// atribuir cor a vi
		for(int k = 0; k < colour.size(); k++){ // checar se existe alguma cor disponível
			if(colour[k] == 0){
				G->vertex(i).setColour(k+1);	// atribuir cor
				break;
			}
		}

		if(G->vertex(i).getColour() == 0){			// se não existir cor disponível
			colour.push_back(0);					// criar nova cor
			G->vertex(i).setColour(colour.size()); 	// atribuir nova cor
		}

		// zerar vetor de cores usadas
		for(int w = 0; w < colour.size(); w++){ // checar se existe alguma cor disponível
			colour[w] = 0;
		}
	}

	std::cout << "Cores usadas:" << colour.size() << std::endl;
}

void GraphHandler::bb_colour(){
	// colorir grafo usando branch-and-bound
} 