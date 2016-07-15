#pragma once

#include <vector>
#include <algorithm>

using std::vector;


/*******************************************************************************/
// Представление графа
template <typename T>
class GraphRepresentation
{
private:
	int numberOfVertices_;

protected:
	vector<vector<T> > matrix_;

public:
	GraphRepresentation() = default;
	GraphRepresentation(int numberOfVertices) : numberOfVertices_(numberOfVertices) {}
	virtual ~GraphRepresentation() = default;

	int Size() const;
	virtual void Resize(int newSize) = 0;
	void AddVertex();
	virtual void AddEdge(int begin, int end) = 0;
	virtual bool IsVerticesConnected(int begin, int end) const = 0;

protected:
	void SetNumberOfVertices(int numberOfVertices);
};


template <typename T>
int GraphRepresentation<T>::Size() const
{
	return numberOfVertices_;
}


template <typename T>
void GraphRepresentation<T>::SetNumberOfVertices(int numberOfVertices)
{
	numberOfVertices_ = numberOfVertices;
}


template <typename T>
void GraphRepresentation<T>::AddVertex()
{
	Resize(Size() + 1);
}

/*******************************************************************************/


template <typename T>
class AdjacencyMatrixRepresentation : public GraphRepresentation<T>
{
private:

public:
	AdjacencyMatrixRepresentation() = default;
	AdjacencyMatrixRepresentation(int numberOfVertices) : GraphRepresentation(numberOfVertices)
	{
		Resize(numberOfVertices);
	}

	virtual ~AdjacencyMatrixRepresentation() = default;

	void Resize(int newSize) override
	{
		SetNumberOfVertices(newSize);
		matrix_.resize(newSize);
		for (auto& elem : matrix_)
		{
			elem.resize(newSize);
		}
	}

	void AddEdge(int begin, int end) override;

	bool IsVerticesConnected(int begin, int end) const override
	{
		if (matrix_[begin][end] != T())
			return true;
		return false;
	}
};


template <typename T>
void AdjacencyMatrixRepresentation<T>::AddEdge(int begin, int end)
{
	matrix_[begin][end] = 1;
}


/*******************************************************************************/


template <typename T>
class AdjacencyListRepresentation : public GraphRepresentation<T>
{
private:

public:
	AdjacencyListRepresentation() = default;
	AdjacencyListRepresentation(int numberOfVertices) : GraphRepresentation(numberOfVertices)
	{
		Resize(numberOfVertices);
	}
	virtual ~AdjacencyListRepresentation() {}

	void Resize(int newSize) override
	{
		SetNumberOfVertices(newSize);
		matrix_.resize(newSize);
	}

	void AddEdge(int begin, int end) override;

	bool IsVerticesConnected(int begin, int end) const override
	{
		if (std::find(matrix_[begin].begin(), matrix_[begin].end(), end) != matrix_[begin].end())
			return true;
		return false;
	}
};


template <typename T>
void AdjacencyListRepresentation<T>::AddEdge(int begin, int end)
{
	if (std::find(matrix_[begin].begin(), matrix_[begin].end(), end) == matrix_[begin].end())
	{
		int currentSize = matrix_[begin].size();
		matrix_[begin].resize(currentSize + 1);
		matrix_[begin][currentSize] = end;
	}
}
