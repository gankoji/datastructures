#include "graph.h"

Graph::Graph(int v) {
	vertex_count = v;
	adjacent.resize(vertex_count);

	for (int i = 0; i < vertex_count; i++) {
      vertices.push_back( Vertex(i) );
		adjacent[i].head = nullptr;
	}
}

void Graph::depth_first_search() {
	for (const auto& u: vertices) {
		if (vertices[u.id].color == WHITE) {
			depth_first_search_visit(u.id);
		}
	}
}

void Graph::depth_first_search_visit(int u) {
	vertices[u].color = GRAY;
	std::cout << vertices[u].id <<" ";
	const auto& v = adjacent[u].head;

	if (vertices[v->dest_id].color == WHITE) {
		depth_first_search_visit(v->dest_id);
	}

	vertices[u].color = BLACK;
}

void Graph::add_edge(int src, int dest) {
	Adj_list_node *node = new Adj_list_node(dest);
	if (adjacent[src].head == nullptr) {
		adjacent[src].head = node;
	} else {
		Adj_list_node *tmp = adjacent[src].head;
		while (tmp->next != nullptr)
			tmp = tmp->next;

		tmp->next = node;
	}

	node = new Adj_list_node(src);
	if (adjacent[dest].head == nullptr) {
		adjacent[dest].head = node;
	} else {
		Adj_list_node *tmp = adjacent[dest].head;
		while (tmp->next != nullptr)
			tmp = tmp->next;

		tmp->next = node;
	}
}

