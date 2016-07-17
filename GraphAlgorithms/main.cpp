#include "Graph.h"
#include "DepthFirstSearch.h"
#include <iostream>
#include <memory>

int main()
{
	//AdjacencyListRepresentation* representation = new AdjacencyListRepresentation;
	AdjacencyMatrixRepresentation* representation = new AdjacencyMatrixRepresentation;
	representation->Resize(12);
	std::unique_ptr<UndirectedGraph> graph = std::make_unique<UndirectedGraph>(representation);
	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H, 8 - I, 9 - J, 10 - K, 11 - L
	
	graph->AddEdge(0, 1);	// A < - > B
	graph->AddEdge(0, 2);	// A < - > C
	graph->AddEdge(0, 3);	// A < - > D
	
	graph->AddEdge(1, 4);	// B < - > E
	graph->AddEdge(1, 5);	// B < - > F
	
	graph->AddEdge(2, 5);	// C < - > F
	
	graph->AddEdge(3, 6);	// D < - > G
	graph->AddEdge(3, 6);	// D < - > H
	
	graph->AddEdge(4, 8);	// E < - > I
	graph->AddEdge(4, 9);	// E < - > J
	
	graph->AddEdge(6, 7);	// G < - > H
	
	graph->AddEdge(8, 9);	// I < - > J
	
	graph->AddEdge(10, 11);	// K < - > L

	//Explore(graph.get(), 10);
	DepthFirstSearch(graph.get());
	std::cin.get();

	return 0;
}