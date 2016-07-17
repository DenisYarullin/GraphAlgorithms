#include "Graph.h"


int Graph::NumberOfVertices()
{
	return representation_->Size();
}


Graph::Graph(GraphRepresentation* representation) : representation_(representation)
{
	visited_.resize(representation_->Size());
}


void Graph::AddVertex()
{
	representation_->AddVertex();
	visited_.resize(representation_->Size() + 1);
}


bool Graph::IsVerticesConnected(int begin, int end) const
{
	return representation_->IsVerticesConnected(begin, end);
}


void Graph::VisitVertex(int vertexNumber)
{
	visited_[vertexNumber] = true;
}


bool Graph::IsVertexVisited(int vertexNumber) const
{
	return visited_[vertexNumber];
}


vector<int>::iterator Graph::Begin(int startVertex)
{
	return representation_->Begin(startVertex);
}


vector<int>::iterator Graph::End(int startVertex)
{
	return representation_->End(startVertex);
}


ptrdiff_t Graph::NextVertex(vector<int>::iterator first, vector<int>::iterator last)
{
	return representation_->NextVertex(first, last);
}


void Graph::ResetVisitedVertices()
{
	for(auto& elem: visited_)
	{
		elem = false;
	}
}


void DirectedGraph::AddEdge(int beginVertex, int endVertex)
{
	representation_->AddEdge(beginVertex, endVertex);
}


void UndirectedGraph::AddEdge(int beginVertex, int endVertex)
{
	representation_->AddEdge(beginVertex, endVertex);
	representation_->AddEdge(endVertex, beginVertex);
}

