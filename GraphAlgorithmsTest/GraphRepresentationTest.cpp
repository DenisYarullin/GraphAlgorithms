#include "GraphRepresentationTest.h"
#include "GraphRepresentation.h"

#include <gtest/gtest.h>

class GraphRepresentationTest : public ::testing::Test
{
protected:

	virtual void SetUp()
	{
		representation = nullptr;
	}

	virtual void TearDown()
	{
		if (representation)
			delete representation;
	}

	GraphRepresentation<int>* representation;
};


TEST_F(GraphRepresentationTest, MatrixTest)
{
	representation = new AdjacencyMatrixRepresentation<int>(10);
	EXPECT_EQ(10, representation->Size());
	representation->Resize(20);
	EXPECT_EQ(20, representation->Size());
	representation->AddVertex();
}


TEST_F(GraphRepresentationTest, ListTest)
{
	representation = new AdjacencyListRepresentation<int>(100);
	EXPECT_EQ(100, representation->Size());
	representation->Resize(50);
	EXPECT_EQ(50, representation->Size());
	representation->AddVertex();
	EXPECT_EQ(51, representation->Size());
}

