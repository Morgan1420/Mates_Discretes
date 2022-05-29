#include <iostream>
#include <fstream>
#include "algorismes.h"

void LlegirArxiu(const std::string&, std::vector<Node>&, std::vector<Aresta>&);

int main()
{
    std::vector<Node> v_nodes;
    std::vector<Aresta> v_arestes;

    LlegirArxiu("./fitxer.txt", v_nodes, v_arestes);

    //DFS(v_nodes, v_arestes);

    

    return 0;
}

void LlegirArxiu(const std::string& nomArxiu, std::vector<Node>& v_nodes, std::vector<Aresta>& v_arestes)
{
    /*
    Estructura fitxer:

    Primera fila el nombre total de nodes
    Les demes files donaràn:nodeOrigen, nodeFinal, cost i direccio (en aquest ordre i separades per un espai)
    */

    int nombreNodes;

    std::ifstream fitxer(nomArxiu);
    
    fitxer >> nombreNodes;
    v_nodes.resize(nombreNodes);
    
    while(!fitxer.eof())
    {
        // crear variables
        Aresta novaAresta;
        float cost;
        int nOrigen, nFinal;
        bool direccio;
        
        // llegir variables del fitxer
        fitxer >> nOrigen >> nFinal >> cost >> direccio;
        std::cout << nOrigen << nFinal << cost << direccio << std::endl;
        
        // Afegir dades a aresta
        novaAresta.setOrigen(nOrigen);
        novaAresta.setFinal(nFinal);
        novaAresta.setCost(cost);
        novaAresta.setDirigit(direccio);

        // afegir aresta als nodes corresponents
        v_nodes.at(nOrigen).setAresta(novaAresta);
        if(direccio == false)
            v_nodes.at(nFinal).setAresta(novaAresta);

        // afegir aresta al vector d'arestes
        v_arestes.push_back(novaAresta);
    }

    fitxer.close();
}
