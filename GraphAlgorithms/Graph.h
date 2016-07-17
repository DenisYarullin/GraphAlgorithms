#pragma once

#ifndef GRAPH_H_
#define GRAPH_H_

#include "GraphRepresentation.h"


/*******************************************************************************/
// Типы графов
class Graph
{
protected: 
	GraphRepresentation* representation_;
	vector<bool> visited_;
	int connectedComponentsNumber_;
	vector<int>	connectedComponents_;
	int timer_;
	vector<std::pair<int, int>> times_;
public:
	Graph() = default;
	Graph(GraphRepresentation* representation);
	virtual ~Graph() = default;

	int NumberOfVertices();
	void AddVertex();
	bool IsVerticesConnected(int begin, int end) const;
	void VisitVertex(int vertexNumber);
	bool IsVertexVisited(int vertexNumber) const;
	virtual void AddEdge(int beginVertex, int endVertex) = 0;

	vector<int>::iterator Begin(int startVertex);
	vector<int>::iterator End(int startVertex);
	ptrdiff_t NextVertex(vector<int>::iterator first, vector<int>::iterator last);

	void AddConnectedComponent();
	void SetVertexConnectedComponentNumber(int vertex);
	void ResetGraph();

	void IncreaseTime();
	void SetVertexInTime(int vertex);
	void SetVertexOutTime(int vertex);
};


/*******************************************************************************/


class DirectedGraph : public Graph
{
private:
public:
	DirectedGraph() = default;
	DirectedGraph(GraphRepresentation* representation) : Graph(representation) {};
	virtual ~DirectedGraph() = default;
	void AddEdge(int beginVertex, int endVertex) override;
};


/*******************************************************************************/

class UndirectedGraph : public Graph
{
private:
public:
	UndirectedGraph() = default;
	UndirectedGraph(GraphRepresentation* representation) : Graph(representation) {};
	virtual ~UndirectedGraph() = default;
	void AddEdge(int beginVertex, int endVertex) override;
};


#endif // GRAPH_H_

