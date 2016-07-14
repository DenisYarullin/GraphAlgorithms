#pragma once

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

using std::vector;


/*******************************************************************************/

template <typename T>
class GraphRepresentation;

template <typename T>
class ProxyGraphRepresentation
{
private:
	GraphRepresentation<T>& representation_;
	int begin_;
	int end_;
public:
	ProxyGraphRepresentation(GraphRepresentation<T>& representation, int begin) : representation_(representation), begin_(begin) {}

	ProxyGraphRepresentation& operator [](int end)
	{
		end_ = end;
		return *this;
	}

	ProxyGraphRepresentation& operator=(T value)
	{
		representation_.matrix_[begin_][end_] = value;
		return *this;
	}
};

// Представление графа
template <typename T>
class GraphRepresentation
{
private:
	int numberOfVertices_;

protected:
	vector<vector<T> > matrix_;

public:
	friend class ProxyGraphRepresentation<T>;
	GraphRepresentation() = default;
	GraphRepresentation(int numberOfVertices) : numberOfVertices_(numberOfVertices) {}
	virtual ~GraphRepresentation() = default;

	int Size() const;
	virtual void Resize(int newSize) = 0;
	void AddVertex();
	virtual void AddEdge(int begin, int end, T value) = 0;

	T& operator ()(int begin, int end)
	{
		return matrix_[begin][end];
	}

	ProxyGraphRepresentation<T> operator [](int begin)
	{
		return ProxyGraphRepresentation<T>(*this, begin);
	}

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

	void AddEdge(int begin, int end, T value) override;
};


template <typename T>
void AdjacencyMatrixRepresentation<T>::AddEdge(int begin, int end, T value)
{
	matrix_[begin][end] = value;
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

	void AddEdge(int begin, int end, T value) override;
};


template <typename T>
void AdjacencyListRepresentation<T>::AddEdge(int begin, int end, T value)
{
	int currentSize = matrix_[begin].size();
	matrix_[begin].resize(currentSize + 1);
	matrix_[begin][currentSize] = value;
}


/*******************************************************************************/
// Типы графов
template <typename T>
class Graph
{
protected: 
	GraphRepresentation<T>* representation_;
public:
	Graph() = default;
	Graph(GraphRepresentation<T>* representation) : representation_(representation) {}
	virtual ~Graph() = default;

	int NumberOfVertices() { return representation_->Size();  }

	void AddVertex();
	virtual void AddEdge(int beginVertex, int endVertex, T value) = 0;

	GraphRepresentation<int>& operator ()(int begin, int end)
	{
		return *representation_(begin, end);
	}
};


template <typename T>
void Graph<T>::AddVertex()
{
	representation_->AddVertex();
}


/*******************************************************************************/


template <typename T>
class DirectedGraph : public Graph<T>
{
private:

public:
	DirectedGraph() = default;
	DirectedGraph(GraphRepresentation<T>* representation) : Graph(representation) {};

	virtual ~DirectedGraph() = default;

	void AddEdge(int beginVertex, int endVertex, T value) override;
};


template <typename T>
void DirectedGraph<T>::AddEdge(int beginVertex, int endVertex, T value)
{
	representation_->AddEdge(beginVertex, endVertex, value);
}


/*******************************************************************************/

template <typename T>
class UndirectedGraph : public Graph<T>
{
private:
public:
	UndirectedGraph() = default;
	UndirectedGraph(GraphRepresentation<T>* representation) : Graph(representation) {};
	virtual ~UndirectedGraph() = default;

	void AddEdge(int beginVertex, int endVertex, T value) override;
};


template <typename T>
void UndirectedGraph<T>::AddEdge(int beginVertex, int endVertex, T value)
{
	representation_->AddEdge(beginVertex, endVertex, value);
	representation_->AddEdge(endVertex, beginVertex, value);
}


#endif // GRAPH_H_
