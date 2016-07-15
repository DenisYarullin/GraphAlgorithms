#pragma once

#ifndef GRAPH_H_
#define GRAPH_H_

#include "GraphRepresentation.h"


/*******************************************************************************/
// Типы графов
template <typename T>
class Graph
{
protected: 
	GraphRepresentation<T>* representation_;
	vector<bool> visited_;
public:
	Graph() = default;
	Graph(GraphRepresentation<T>* representation) : representation_(representation)
	{
		visited_.resize(representation_->Size());
	}

	virtual ~Graph() = default;

	int NumberOfVertices() { return representation_->Size();  }

	void AddVertex();
	virtual void AddEdge(int beginVertex, int endVertex) = 0;
	bool IsVerticesConnected(int begin, int end) const;

	void VisitVertex(int vertexNumber);
	bool IsVertexVisited(int vertexNumber) const;
};


template <typename T>
void Graph<T>::AddVertex()
{
	representation_->AddVertex();
	visited_.resize(representation_->Size() + 1);
}


template <typename T>
bool Graph<T>::IsVerticesConnected(int begin, int end) const
{
	return representation_->IsVerticesConnected(begin, end);
}


template <typename T>
void VisitVertex(int vertexNumber)
{
	visited_[vertexNumber] = true;
}


template <typename T>
bool Graph<T>::IsVertexVisited(int vertexNumber) const
{
	return visited_[vertexNumber];
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

	void AddEdge(int beginVertex, int endVertex) override;
};


template <typename T>
void DirectedGraph<T>::AddEdge(int beginVertex, int endVertex)
{
	representation_->AddEdge(beginVertex, endVertex);
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

	void AddEdge(int beginVertex, int endVertex) override;
};


template <typename T>
void UndirectedGraph<T>::AddEdge(int beginVertex, int endVertex)
{
	representation_->AddEdge(beginVertex, endVertex);
	representation_->AddEdge(endVertex, beginVertex);
}


#endif // GRAPH_H_
