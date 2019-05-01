#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

Graph::Graph()
{
    vertex = 0;
    edge = 0;
    neighbourList = nullptr;
}

Graph::~Graph()
{
    if(!neighbourList)
        delete [] neighbourList;
}

void Graph::inputGraphConsole(void)
{
    cin >> vertex;
    neighbourList = new vector<unsigned int>[vertex];
    unsigned int v1, v2;
    edge = 0;
    while(cin >> v1 >> v2)
    {
        neighbourList[v1].push_back(v2);
        neighbourList[v2].push_back(v1);
        edgesList.push_back(make_pair(v1,v2));
        edge++;
    }
    cin.clear();
}

bool Graph::inputGraphFile(std::string filename)
{
    fstream file;
    file.open(filename, ios::in);
    if(!file.good())
        return false;
    file >> vertex;
    neighbourList = new vector<unsigned int>[vertex];
    unsigned int v1, v2;
    edge = 0;
    while(file.good())
    {
        file >> v1 >> v2;
        if(file.fail())
            break;
        neighbourList[v1].push_back(v2);
        neighbourList[v2].push_back(v1);
        edgesList.push_back(make_pair(v1,v2));
        edge++;
    }
    file.close();
    return true;
}

int Graph::getQuantityOfComponents(unsigned int V1, unsigned int V2)
{
    int cn = 0;
	unsigned int v, u;
	bool visited[vertex];
	stack<unsigned> stc;

	for (auto i = 0; i < vertex; ++i)
        visited[i] = false;
	visited[V1] = true;
	visited[V2] = true;

	for (unsigned i = 0; i < vertex; ++i)
    {
		if (!visited[i])
		{
			cn++;
			if (cn > 1)
                return cn;
			stc.push(i);
			visited[i] = true;
			while (!stc.empty())
			{
				v = stc.top();
				stc.pop();
				for (auto it = neighbourList[v].begin(); it != neighbourList[v].end(); ++it)
                {
					u = *it;
					if (!visited[u])
					{
						stc.push(u);
						visited[u] = true;
					}
				}
			}
		}
    }

	return cn;
}


std::vector<std::pair<unsigned int, unsigned int>> Graph::getBridges()
{
    unsigned V1, V2, cn;
    std::vector<std::pair<unsigned int, unsigned int>> bridgeEdes;
	for (auto i = 0; i < edgesList.size(); ++i)
    {
		V1 = edgesList[i].first;
		V2 = edgesList[i].second;
		cn = getQuantityOfComponents(V1, V2);
		if(cn>1)
            bridgeEdes.push_back(make_pair(V1, V2));
	}
	return bridgeEdes;
}

void Graph::printGraph()
{
    cout << "Vertex: " << vertex << "\tEdge: " << edge;
    cout << "\nEdges:\n";
    for(auto i = 0; i < edgesList.size(); i++)
    {
        cout << edgesList[i].first << " " << edgesList[i].second << endl;
    }
}
