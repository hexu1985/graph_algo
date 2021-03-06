#ifndef GRAPH_ALGO_RANDE_HPP
#define GRAPH_ALGO_RANDE_HPP

#include <stdlib.h>
#include "Edge.hpp"

namespace graph_algo {

template <class Graph>
void randE(Graph &G, int E)
{ 
	for (int i = 0; i < E; i++)
	{
		int v = int(G.V()*(rand()/(1.0+RAND_MAX)));
		int w = int(G.V()*(rand()/(1.0+RAND_MAX)));
		G.insert(Edge(v,w));
	}
}

}	// namespace 

#endif
