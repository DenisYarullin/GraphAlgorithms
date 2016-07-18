#pragma once

#include "Graph.h"

#include <gtest/gtest.h>
#include <memory>

using ::testing::TestWithParam;
using ::testing::Values;

typedef GraphRepresentation* CreateRepresentationFunc();

inline GraphRepresentation* CreateAdjacencyMatrixRepresentationGraphTest()
{
	return new AdjacencyMatrixRepresentation();
}


inline GraphRepresentation* CreateAdjacencyListRepresentationGraphTest()
{
	return new AdjacencyListRepresentation();
}


class GraphTest : public ::TestWithParam<CreateRepresentationFunc*>
{
public:
	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H, 8 - I, 9 - J, 10 - K, 11 - L

	void CreateFirstUndirectedGraph()
	{
		representation->Resize(12);
		graph = std::make_unique<UndirectedGraph>(representation);
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
	}

	void CreateSecondUndirectedGraph()
	{
		representation->Resize(12);
		graph = std::make_unique<UndirectedGraph>(representation);
		graph->AddEdge(0, 1);	// A < - > B
		graph->AddEdge(0, 4);	// A < - > E
		graph->AddEdge(2, 3);	// C < - > D
		graph->AddEdge(2, 6);	// C < - > G
		graph->AddEdge(2, 7);	// C < - > H
		graph->AddEdge(4, 8);	// E < - > I
		graph->AddEdge(4, 9);	// E < - > J
		graph->AddEdge(6, 7);	// G < - > H
		graph->AddEdge(6, 10);	// G < - > K
		graph->AddEdge(7, 10);	// H < - > K
		graph->AddEdge(7, 11);	// H < - > L
		graph->AddEdge(8, 9);	// I < - > J
	}

	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H, 8 - I, 9 - J, 10 - K, 11 - L
	void CreateFirstDirectedGraph()
	{
		representation->Resize(8);
		graph = std::make_unique<DirectedGraph>(representation);
		graph->AddEdge(0, 1);	// A - > B
		graph->AddEdge(0, 2);	// A - > C
		graph->AddEdge(0, 5);	// A - > F
		graph->AddEdge(1, 4);	// B - > E
		graph->AddEdge(2, 4);	// C - > D
		graph->AddEdge(3, 0);	// D - > A
		graph->AddEdge(3, 7);	// D - > H
		graph->AddEdge(4, 5);	// E - > F
		graph->AddEdge(4, 6);	// E - > G
		graph->AddEdge(4, 7);	// E - > H
		graph->AddEdge(5, 1);	// F - > B
		graph->AddEdge(5, 6);	// F - > G
		graph->AddEdge(7, 6);	// H - > G
	}

	void CreateSecondDirectedGraph()
	{
		representation->Resize(6);
		graph = std::make_unique<DirectedGraph>(representation);
		graph->AddEdge(0, 2);	// A - > C
		graph->AddEdge(1, 3);	// B - > D
		graph->AddEdge(1, 0);	// B - > A
		graph->AddEdge(3, 2);	// D - > C
		graph->AddEdge(2, 4);	// C - > E
		graph->AddEdge(2, 5);	// C - > F
	}



	GraphRepresentation* representation;
	std::unique_ptr<Graph> graph;

protected:

	virtual void SetUp()
	{
		representation = (*GetParam())();
	}

	virtual void TearDown()
	{
		if (representation)
		{
			delete representation;
			representation = nullptr;
		}
	}
};

