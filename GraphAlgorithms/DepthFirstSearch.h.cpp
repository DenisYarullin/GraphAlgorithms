#include "DepthFirstSearch.h"

void Previsit(Graph* graph, int currentgVertex)
{
	//std::cout << currentgVertex << " ";
}


void Postvisit(Graph* graph, int currentgVertex)
{
	//std::cout << currentgVertex << " ";
}


// нахождение всех вершин, достижимых из данной
void Explore(Graph* graph, int startingVertex)
{
	graph->VisitVertex(startingVertex);

	Previsit(graph, startingVertex);

	for (vector<int>::iterator i = graph->Begin(startingVertex); i != graph->End(startingVertex); ++i)
	{
		int nextVertex = graph->NextVertex(graph->Begin(startingVertex), i);
		if (nextVertex != -1 && !graph->IsVertexVisited(nextVertex))
		{
			Explore(graph, nextVertex);
		}
	}
	Postvisit(graph, startingVertex);
}


void DepthFirstSearch(Graph* graph)
{
	graph->ResetVisitedVertices();

	for (int i = 0; i < graph->NumberOfVertices(); ++i)
	{
		if (!graph->IsVertexVisited(i))
		{
			Explore(graph, i);
		}
	}
}