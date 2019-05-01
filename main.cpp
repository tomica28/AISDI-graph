#include <iostream>
#include <ctime>
#include "Graph.h"

void test(void);

using namespace std;
int main() {
    test();
    cout << "1.konsola 2.plik 3.koniec: ";
    int mode;
    cin >> mode;
    while(mode == 1 || mode == 2)
    {
        Graph g;
        if(mode == 1)
        {
            g.inputGraphConsole();
        }
        else
        {
            cout << "Podaj nazwe pliku: ";
            string fname;
            cin >> fname;
            g.inputGraphFile(fname);
        }
        g.printGraph();
        clock_t begin = clock();
        std::vector<std::pair<unsigned int, unsigned int>> temp = g.getBridges();
        clock_t end = clock();
        cout << endl << "Czas obliczania: " << double(end - begin) / CLOCKS_PER_SEC << endl;
        cout << "\nMosty rozlegle:\n";
        for(int i = 0; i < temp.size(); i++)
            cout << temp[i].first << " " << temp[i].second << endl;
        cout << "1.konsola 2.plik 3.koniec: ";
        cin >> mode;
    }
	return 0;
}

void test(void)
{
    Graph g[5];
    cout << "Test sciezka: ";
    std::vector<std::pair<unsigned int, unsigned int>> sciezka = {{1, 2}, {2, 3}};
    g[0].inputGraphFile("sciezka.txt");
    if(sciezka == g[0].getBridges())
        cout << "passed\n";
    else
        cout << "failed\n";
    cout << "Test cykl: ";
    g[1].inputGraphFile("cykl.txt");
    std::vector<std::pair<unsigned int, unsigned int>> cykl = g[1].getBridges();
    if(cykl.empty())
        cout << "passed\n";
    else
        cout << "failed\n";
    cout << "Test gwiazda1: ";
    std::vector<std::pair<unsigned int, unsigned int>> gwiazda1 = {{0, 1}, {0, 2}, {0, 3}};
    g[2].inputGraphFile("gwiazda1.txt");
    if(gwiazda1 == g[2].getBridges())
        cout << "passed\n";
    else
        cout << "failed\n";
    cout << "Test gwiazda2: ";
    std::vector<std::pair<unsigned int, unsigned int>> gwiazda2 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9}, {0, 10}};
    g[3].inputGraphFile("gwiazda2.txt");
    if(gwiazda2 == g[3].getBridges())
        cout << "passed\n";
    else
        cout << "failed\n";
    cout << "Test pelny: ";
    g[4].inputGraphFile("pelny.txt");
    std::vector<std::pair<unsigned int, unsigned int>> pelny = g[4].getBridges();
    if(pelny.empty())
        cout << "passed\n";
    else
        cout << "failed\n";

}
