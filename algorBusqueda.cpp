#pragma once
#include <iostream>
#include "node.h"

bool arestaInVector(std::vector<Aresta> const, Aresta);


void DFS(std::vector<Node> const nodes, std::vector<Aresta>& arestesReturn)
{
    int node;
    bool fiBusqueda, backToZero;
    std::vector<Aresta> arestesTemporals;
    
    node = 0;
    fiBusqueda = false;
    backToZero = true;
    
    while(!fiBusqueda)
    {
        printf("%d", node);
        // Busquem una aresta del node a on estem per la qual encara no haguèm passat 
        bool trobat = false;
        int i = 0;
        while(!trobat && i < nodes.at(node).getGrauNode())
        {
            printf("%d - ", i);
            if(arestaInVector(arestesReturn, nodes.at(node).getArestaPos(i)))
            {
                printf("f");
                arestesReturn.push_back(nodes.at(node).getArestaPos(i));
                arestesTemporals.push_back(nodes.at(node).getArestaPos(i));
                trobat = true;  
            }
            i++;
        }

        // agafem el seguent node en cas de trobar una aresta i l'anterior en cas de no
        if(trobat)
        {
            printf("b");
            backToZero = false;
            node = arestesReturn.back().getFinal();
        }
        else if (!backToZero) {
            printf("a");
            node = arestesReturn.back().getOrigen();
            arestesTemporals.pop_back();
        }

        
        
        // comprobem que hem tornat al origen
        if(arestesTemporals.capacity() == 0 && backToZero)
            fiBusqueda = true;
        else if(arestesTemporals.capacity() == 0)
            backToZero = true;
        

    }   
}

bool arestaInVector(std::vector<Aresta> const arestes, Aresta aresta)
{
    bool trobat = false;
    int i = 0;

    while(!trobat && i < arestes.size())
    {
        if(aresta == arestes.at(i))
            trobat = true;
        i++;
    }
 
    return trobat;

}