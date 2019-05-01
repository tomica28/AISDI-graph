#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph
{
private:

    unsigned int vertex;
    unsigned int edge;

    std::vector<unsigned int> *neighbourList ;
    std::vector<std::pair<unsigned int, unsigned int>> edgesList;

public:
    Graph();
    ~Graph();

    void inputGraphConsole(void);
    bool inputGraphFile(std::string filename);
    std::vector<std::pair<unsigned int, unsigned int>> getBridges();
	int getQuantityOfComponents(unsigned int V1, unsigned int V2);
	void printGraph();
};
#endif // GRAPH_H
