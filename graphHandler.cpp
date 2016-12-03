#include "graphHandler.hpp"

GraphHandler::GraphHandler(Graph* inputGraph){
	this->G = inputGraph;
	qttColours = 0;
}


// colorir grafo usando heuristica
void GraphHandler::h_colour(){

	std::vector<unsigned int> colour; // 0 se a cor não é usada e 1 se a cor é usada nas adjacencias
	colour.push_back(0); // inicializar com 1 cor

	std::vector<unsigned int> n; // vizinhos de um dado vértice
	unsigned int nColour; // cor de um dado vizinho

	// coloca vértices em ordem decrescente de grau
	G->sort();
	G->reverse();

	// colorir
	for (unsigned int i = 0; i < G->size(); i++){ 	// para cada vértice vi em G
		n = G->at(i)->getNeighbors();
		
		// checar cores adjacentes
		for (unsigned int j = 0; j < n.size(); j++){	// para cada vizinho de vi
			// proibir cor usada por vizinho
			nColour = G->vertex(n.at(j))->getColour();
			if (nColour > 0){				
				colour[nColour - 1] = 1;
			}
		}

		// atribuir cor a vi
		for(unsigned int k = 0; k < colour.size(); k++){ // checar se existe alguma cor disponível
			if(colour.at(k) == 0){
				G->at(i)->setColour(k+1);	// atribuir cor
				break;
			}
		}

		if(G->at(i)->getColour() == 0){			// se não existir cor disponível
			colour.push_back(0);					// criar nova cor
			G->at(i)->setColour(colour.size()); 	// atribuir nova cor
		}

		// zerar vetor de cores usadas
		for(unsigned int w = 0; w < colour.size(); w++){ // checar se existe alguma cor disponível
			colour[w] = 0;
		}
	}

	storeSolution();
	std::cout << "Cores usadas:" << colour.size() << std::endl;
}



void GraphHandler::bb_colour(){
	// colorir grafo usando branch-and-bound
} 


void GraphHandler::bt_colour(unsigned int vertexIndex, unsigned int usedColours, unsigned int * upperLimit){
	if(vertexIndex < G->size()){
		// obtem limite superior
		if (!(*upperLimit > 0)){
			*upperLimit = 10;
		}
		G->at(vertexIndex)->setColour(0); // inicializar cor do vértice

		// tentar colorir
		for (unsigned int i = 1; i < usedColours+1; i++){ 	// para cada cor que vi pode assumir
			if (i < *upperLimit){
				if (promissing(vertexIndex, i)){ // se promissor

					G->at(vertexIndex)->setColour(i);


					if (vertexIndex >= G->size() - 1){ // se existe solução
						qttColours = usedColours;
						storeSolution();
						*upperLimit = usedColours - 1;
					}
					else{
						bt_colour(vertexIndex + 1, usedColours, upperLimit);
					}
				}
			}
		}

		if(G->at(vertexIndex)->getColour() == 0){						// Se após tentar todas as cores já usadas, ainda não existir solução
			if(usedColours < *upperLimit){ 								// se ainda for possível usar mais uma cor
				usedColours++;											// criar nova cor
				G->at(vertexIndex)->setColour(usedColours);				// atribuir nova cor ao vértice


				if (vertexIndex >= G->size() - 1){ 						// se existe solução
					qttColours = usedColours;
					storeSolution();
					*upperLimit = usedColours - 1;
					std::cout << "+++++++++>> upper limit = " << *upperLimit << std::endl;
				}
				else{
					bt_colour(vertexIndex + 1, usedColours, upperLimit);	// continuar procurando solução
				}
				
			}
		}
		G->at(vertexIndex)->setColour(0);
	}
} 


bool GraphHandler::promissing(unsigned int vertexId, unsigned int colour){
	std::vector<unsigned int> n = G->at(vertexId)->getNeighbors();

	for (unsigned int i = 0; i < n.size(); i++){	// para cada vizinho de vi
		// proibir cor usada por vizinho
		if (G->vertex(n.at(i))->getColour() == colour){
			return false; // solução inviável
		}
	}
	return true;
}

void GraphHandler::storeSolution(){
	Solution = *G;
}

Graph GraphHandler::getSolution(){
	return Solution;
}

unsigned int GraphHandler::getQttColours(){
	return this->qttColours;
}