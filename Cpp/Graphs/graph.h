#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <set>

/*
 * This code largely from an example implementation found at
 * https://programmercave0.github.io/blog/2018/03/05/C++-Depth-First-Search-using-Adjacency-List
 */

class Graph
{
    public:
        int vertex_count;
        enum Color {WHITE, GRAY, BLACK};

        struct Vertex
        {
            int id;
            Color color;
            Vertex(int _id) : id(_id), color(Color::WHITE) {}
        };

        struct Adj_list_node
        {
            int dest_id;
            Adj_list_node * next;
            Adj_list_node(int _dest_id) : dest_id(_dest_id), next(nullptr) {}
        };

        struct Adj_list
        {
            Adj_list_node *head;
        };

        std::vector<Vertex> vertices;
        std::vector<Adj_list> adjacent;

        Graph(int);
        void add_edge(int, int);
        void depth_first_search();
        void breadth_first_search();

    private:
        void depth_first_search_visit(int);
};

#endif //GRAPH