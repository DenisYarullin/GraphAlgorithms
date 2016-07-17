#pragma once

#ifndef GRAPH_REPRESENTATION_H_
#define GRAPH_REPRESENTATION_H_

#include <vector>
#include <algorithm>

using std::vector;

/*******************************************************************************/
// Представление графа
class GraphRepresentation
{
private:

protected:
	int numberOfVertices_;
	vector<vector<int>> matrix_;

public:
	GraphRepresentation() = default;
	GraphRepresentation(int numberOfVertices);
	virtual ~GraphRepresentation() = default;

	int Size() const;
	virtual void Resize(int newSize) = 0;
	void AddVertex();
	virtual void AddEdge(int begin, int end) = 0;
	virtual bool IsVerticesConnected(int begin, int end) const = 0;

	vector<int>::iterator Begin(int startVertex);
	vector<int>::iterator End(int startVertex);
	virtual ptrdiff_t NextVertex(vector<int>::iterator first, vector<int>::iterator last) = 0;

protected:
	void SetNumberOfVertices(int numberOfVertices);
};


/*******************************************************************************/


class AdjacencyMatrixRepresentation : public GraphRepresentation
{
private:

public:
	AdjacencyMatrixRepresentation() = default;
	AdjacencyMatrixRepresentation(int numberOfVertices);
	virtual ~AdjacencyMatrixRepresentation() = default;
	void Resize(int newSize) override;
	void AddEdge(int begin, int end) override;
	bool IsVerticesConnected(int begin, int end) const override;

	ptrdiff_t NextVertex(vector<int>::iterator first, vector<int>::iterator last) override;
};


/*******************************************************************************/


class AdjacencyListRepresentation : public GraphRepresentation
{
private:

public:
	AdjacencyListRepresentation() = default;
	AdjacencyListRepresentation(int numberOfVertices);
	virtual ~AdjacencyListRepresentation() = default;
	void Resize(int newSize) override;
	void AddEdge(int begin, int end) override;
	bool IsVerticesConnected(int begin, int end) const override;

	ptrdiff_t NextVertex(vector<int>::iterator first, vector<int>::iterator last) override;
};


#endif