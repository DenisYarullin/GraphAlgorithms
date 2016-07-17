#include "GraphRepresentationTest.h"


TEST_F(GraphRepresentationTest, MatrixTest)
{
	representation = new AdjacencyMatrixRepresentation(10);
	EXPECT_EQ(10, representation->Size());
	representation->Resize(20);
	EXPECT_EQ(20, representation->Size());
	representation->AddVertex();
}


TEST_F(GraphRepresentationTest, ListTest)
{
	representation = new AdjacencyListRepresentation(100);
	EXPECT_EQ(100, representation->Size());
	representation->Resize(50);
	EXPECT_EQ(50, representation->Size());
	representation->AddVertex();
	EXPECT_EQ(51, representation->Size());
}

