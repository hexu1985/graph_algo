#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <cassert>

#include "GRAPH.hpp"
#include "IO.hpp"
#include "JsonFileIO.hpp"
#ifdef USE_BFS_IMPROVED
#include "BFS_improved.hpp"
#else
#include "BFS.hpp"
#endif
#include "get_st.hpp"
#include "get_ord.hpp"

using namespace std;
using namespace graph_algo;

int main(int argc, char *argv[])
{ 
    if (argc != 2) {
        cout << "usage: " << argv[0] << " filepath" << endl;
        exit(1);
    }

    auto G = JsonFileIO<GRAPH>::loadEZ(argv[1]);
    cout << "============== graph show ==============\n";
    IO<GRAPH>::show(*G);
    cout << endl;

    cout << "total edges: " << G->E() << endl;

    cout << "\nDepth-first search test\n";
    BFS<GRAPH> bfs(*G);

    cout << "    |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << i;
    cout << '\n';

    cout << "-----";
    for (int i = 0; i < G->V(); i++) cout << "---";
    cout << '\n';

    auto ord = get_ord(bfs);
    assert(ord.size() == G->V());
    cout << "ord |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << ord[i];
    cout << '\n';

    auto st = get_st(bfs);
    assert(st.size() == G->V());
    cout << "st  |";
    for (int i = 0; i < G->V(); i++) cout << ' ' << setw(2) << st[i];
    cout << '\n';

    cout << endl;
    return 0;
}

