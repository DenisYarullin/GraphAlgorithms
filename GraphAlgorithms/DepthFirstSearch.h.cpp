#include "DepthFirstSearch.h"

void Previsit(Graph* graph, int currentgVertex)
{
	graph->SetVertexConnectedComponentNumber(currentgVertex);
	graph->SetVertexInTime(currentgVertex);
	graph->IncreaseTime();
}


void Postvisit(Graph* graph, int currentgVertex)
{
	graph->SetVertexOutTime(currentgVertex);
	graph->IncreaseTime();
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
	graph->ResetGraph();

	for (int i = 0; i < graph->NumberOfVertices(); ++i)
	{
		if (!graph->IsVertexVisited(i))
		{
			graph->AddConnectedComponent();
			Explore(graph, i);
		}
	}
}