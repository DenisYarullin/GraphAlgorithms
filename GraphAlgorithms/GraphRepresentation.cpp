#include "GraphRepresentation.h"


GraphRepresentation::GraphRepresentation(int numberOfVertices) 
	: numberOfVertices_(numberOfVertices) {}


int GraphRepresentation::Size() const
{
	return numberOfVertices_;
}


void GraphRepresentation::SetNumberOfVertices(int numberOfVertices)
{
	numberOfVertices_ = numberOfVertices;
}


void GraphRepresentation::AddVertex()
{
	Resize(Size() + 1);
}


vector<int>::iterator GraphRepresentation::Begin(int startVertex)
{
	return matrix_[startVertex].begin();
}


vector<int>::iterator GraphRepresentation::End(int startVertex)
{
	return matrix_[startVertex].end();
}


AdjacencyMatrixRepresentation::AdjacencyMatrixRepresentation(int numberOfVertices) : GraphRepresentation(numberOfVertices)
{
	Resize(numberOfVertices);
}


void AdjacencyMatrixRepresentation::AddEdge(int begin, int end)
{
	matrix_[begin][end] = 1;
}


void AdjacencyMatrixRepresentation::Resize(int newSize)
{
	SetNumberOfVertices(newSize);
	matrix_.resize(newSize);
	for (auto& elem : matrix_)
	{
		elem.resize(newSize);
	}
}


bool AdjacencyMatrixRepresentation::IsVerticesConnected(int begin, int end) const
{
	if (matrix_[begin][end] != 0)
		return true;
	return false;
}


ptrdiff_t AdjacencyMatrixRepresentation::NextVertex(vector<int>::iterator first, vector<int>::iterator last)
{
	if (*last != 0)
		return std::distance(first, last);
	else
		return -1;
}


AdjacencyListRepresentation::AdjacencyListRepresentation(int numberOfVertices) : GraphRepresentation(numberOfVertices)
{
	Resize(numberOfVertices);
}


void AdjacencyListRepresentation::Resize(int newSize)
{
	SetNumberOfVertices(newSize);
	matrix_.resize(newSize);
}

void AdjacencyListRepresentation::AddEdge(int begin, int end)
{
	if (std::find(matrix_[begin].begin(), matrix_[begin].end(), end) == matrix_[begin].end())
	{
		int currentSize = matrix_[begin].size();
		matrix_[begin].resize(currentSize + 1);
		matrix_[begin][currentSize] = end;
	}
}


bool AdjacencyListRepresentation::IsVerticesConnected(int begin, int end) const
{
	if (std::find(matrix_[begin].begin(), matrix_[begin].end(), end) != matrix_[begin].end())
		return true;
	return false;
}


ptrdiff_t AdjacencyListRepresentation::NextVertex(vector<int>::iterator first, vector<int>::iterator last)
{
	return *last;
}