class Aresta
{
    public:
    // Constructors
    Aresta() { m_dirigit = false; m_cost = 0.0f; }

    // Getters and setters
    void setCost(const float cost) { m_cost = cost; }
    void setOrigen(const int nOrigen) {m_nOrigen = nOrigen; }
    void setFinal(const int nFinal) { m_nFinal = nFinal; }
    void setDirigit(const bool dirigit) { m_dirigit = dirigit; }

    int getOrigen() const { return m_nOrigen; }
    int getFinal() const { return m_nFinal; }
    float getCost() const {return m_cost; }
    bool getDirigit() const {return m_dirigit; }
    
    // Operator overloads
    bool operator==(Aresta aresta2)
    {
        if(m_nOrigen == aresta2.getOrigen() && m_nFinal == aresta2.getFinal() && m_dirigit == aresta2.getDirigit() && m_cost == aresta2.getCost())
            return true;
        return false;
    }

    private:
    float m_cost;
    int m_nOrigen, m_nFinal;
    bool m_dirigit;

};