#include "SearchAlgorithmsTest.h"

// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H, 8 - I, 9 - J, 10 - K, 11 - L


TEST_P(GraphTest, ExploreFirstUndirectedTest)
{
	CreateFirstUndirectedGraph();

	Explore(graph.get(), 0);

	for (int i = 0; i < graph->NumberOfVertices(); i++)
	{
		if (i == 10 || i == 11)
		{
			EXPECT_FALSE(graph->IsVertexVisited(i));
		}
		else
		{
			EXPECT_TRUE(graph->IsVertexVisited(i));
		}
	}
}


TEST_P(GraphTest, DFSFirstUndirectedTest)
{
	CreateFirstUndirectedGraph();

	DepthFirstSearch(graph.get());

	for (int i = 0; i < graph->NumberOfVertices(); i++)
	{
		EXPECT_TRUE(graph->IsVertexVisited(i));
	}
}


TEST_P(GraphTest, ExploreSecondUndirectedTest)
{
	CreateSecondUndirectedGraph();

	Explore(graph.get(), 0);
	vector<int> numbersVisitedVertices{0, 1, 4, 8, 9};

	for (const auto& i : numbersVisitedVertices)
	{
		EXPECT_TRUE(graph->IsVertexVisited(i));
	}

	graph->ResetVisitedVertices();

	Explore(graph.get(), 2);
	numbersVisitedVertices = {2, 3, 7, 6, 10, 11};

	for (const auto& i : numbersVisitedVertices)
	{
		EXPECT_TRUE(graph->IsVertexVisited(i));
	}

	graph->ResetVisitedVertices();

	Explore(graph.get(), 5);
	numbersVisitedVertices = {5};

	for (const auto& i : numbersVisitedVertices)
	{
		EXPECT_TRUE(graph->IsVertexVisited(i));
	}
}


TEST_P(GraphTest, DFSSwcondUndirectedTest)
{
	CreateSecondUndirectedGraph();

	DepthFirstSearch(graph.get());

	for (int i = 0; i < graph->NumberOfVertices(); i++)
	{
		EXPECT_TRUE(graph->IsVertexVisited(i));
	}
}


INSTANTIATE_TEST_CASE_P(GraphSearchAlgorithms, GraphTest, Values(&CreateAdjacencyMatrixRepresentationGraphTest, &CreateAdjacencyListRepresentationGraphTest));