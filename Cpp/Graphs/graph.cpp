#include "graph.h"

Graph::Graph(int v) {
	vertex_count = v;
	adjacent.resize(vertex_count);

	for (int i = 0; i < vertex_count; i++) {
    	vertices.push_back( Vertex(i) );
		adjacent[i].head = nullptr;
	}
}

void Graph::breadth_first_search() {
	std::queue<Vertex*> toVisit;
	std::set<Vertex *> s;

	// Pick a node to start at, put it on the queue. 
	toVisit.push(&vertices.front());
	s.insert(&vertices.front());

	while(!toVisit.empty()) {
		// Remove node from queue and set
		Vertex * current = toVisit.front();
		toVisit.pop();
		s.extract(current);

		// Mark node as being processed
		int u = current->id;
		current->color = GRAY;
		std::cout << current->id <<" ";

		// Add all of it's neighbors to the queue
		auto v = adjacent[u].head;

		while(v != nullptr) {
			// If neighbor hasn't yet been processed ...
			if (vertices[v->dest_id].color == WHITE) {
				Vertex * ref = &vertices[v->dest_id];
				// ... and it's not already in the queue
				if (s.find(ref) == s.end()) {
					// Enqueue it
					toVisit.push(ref);
					s.insert(toVisit.back());
				}
			}
			// Check next item in the adjacency list
			v = v->next;
		}

		// Mark node as done processing
		current->color = BLACK;
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

void Graph::dijkstra_single(Vertex * src) {
	// Data structures we'll use for traversal
	std::queue<Vertex*> q;

	for (auto & v: vertices) {
		dist[v.id] = INT32_MAX;
		path[v.id] = -1;
		known[v.id] = false;
	}

	// Pick a node to start at, put it on the queue. 
	q.push(src);

	dist[src->id] = 0;
	known[src->id] = true;

	while(!q.empty()) {
		Vertex * n = q.front();
		std::cout << "Searching for shortest path to " << n->id << 
					 " from " << src->id << std::endl;
		q.pop();

		known[n->id] = true;

		int minDist = 100;
		Vertex * nextv = nullptr;
		
		auto v = adjacent[n->id].head;
		while(v != nullptr) {
			if (!known[v->dest_id]) {
				Vertex * ref = &vertices[v->dest_id];
				if (v->cost < minDist) {
					minDist = v->cost;
					nextv = ref;
				}

			}
			// Check next item in the adjacency list
			v = v->next;
		}
		if (nextv == nullptr) {
			// We didn't find a candidate in the adjacency list
			long unsigned int cand = (long unsigned int)(n->id + 1);
			if (cand < vertices.size()) {
				nextv = &vertices[n->id + 1];
				q.push(nextv);
			} 
			continue;
		}

		// Enqueue it
		q.push(nextv);

		if (nextv != nullptr) {
			//printf("Nextv is not null.\n");
			//printf("Changing distance for node %d.\n", nextv->id);
			//printf("Old distance for node %d: %d.\n", nextv->id, dist[nextv->id]);
			//printf("Current distance for node %d: %d.\n", n->id, dist[n->id]);
			//printf("Cost to add: %d.\n", minDist);
			if (dist[nextv->id] > dist[n->id] + minDist) {
				dist[nextv->id] = dist[n->id] + minDist;
				path[nextv->id] = n->id;
			}

			printPath(n);
			printf("\n");
		} else {
			printf("Nextv is null.\n");
		}
	}
}

void Graph::printPath(Vertex * dest) {
	if (path[dest->id] != -1) {
		printPath(&vertices[path[dest->id]]);
		std::cout << " to ";
	}
	std::cout << dest->id;
}

void Graph::dijkstra() {
	for (int i=0; i<vertex_count; i++) {
		dijkstra_single(&vertices[i]);
	}
}