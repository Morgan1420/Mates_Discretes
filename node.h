#include <vector>
#include "aresta.h"

class Node
{
    public:
    // Constructor
    
    // Setters i Getters
    void setAresta(const Aresta aresta) {m_arestes.push_back(aresta); }
    void setVectorAresta(const std::vector<Aresta> arestes) { m_arestes = arestes; }

    int getGrauNode() const { return m_arestes.size(); }
    Aresta getArestaPos(int pos) const {return m_arestes.at(pos); }
    
    // altres funcions

    private:
    std::vector<Aresta> m_arestes;

};