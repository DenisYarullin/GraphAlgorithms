#include "GraphTest.h"

TEST_P(GraphTest, AddVertexDirectedTest)
{
	representation->Resize(10);
	graph = std::make_unique<DirectedGraph>(representation);
	graph->AddVertex();

	EXPECT_EQ(11, graph->NumberOfVertices());
	representation->AddVertex();
	EXPECT_EQ(12, graph->NumberOfVertices());
}


TEST_P(GraphTest, AddVertexUndirectedTest)
{
	representation->Resize(10);
	graph = std::make_unique<UndirectedGraph>(representation);
	graph->AddVertex();

	EXPECT_EQ(11, graph->NumberOfVertices());
	representation->AddVertex();
	EXPECT_EQ(12, graph->NumberOfVertices());

}


TEST_P(GraphTest, AddEdgeDirectedTest)
{
	representation->Resize(5);
	graph = std::make_unique<DirectedGraph>(representation);
	EXPECT_EQ(5, graph->NumberOfVertices());

	graph->AddEdge(0, 1);
	EXPECT_TRUE(graph->IsVerticesConnected(0, 1));
	EXPECT_FALSE(graph->IsVerticesConnected(1, 2));
}


TEST_P(GraphTest, AddEdgeUndirectedTest)
{
	representation->Resize(5);
	graph = std::make_unique<UndirectedGraph>(representation);
	EXPECT_EQ(5, graph->NumberOfVertices());

	graph->AddEdge(0, 1);
	EXPECT_TRUE(graph->IsVerticesConnected(0, 1));
	EXPECT_FALSE(graph->IsVerticesConnected(1, 2));
}


INSTANTIATE_TEST_CASE_P(GraphRepresentations, GraphTest, Values(&CreateAdjacencyMatrixRepresentationGraphTest, &CreateAdjacencyListRepresentationGraphTest));


