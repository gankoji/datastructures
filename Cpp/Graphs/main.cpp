#include "graph.h"

int main(int argc, char ** argv) {
   // Construct a graph
   Graph grp(4);
   grp.add_edge(0, 1);
   grp.add_edge(1, 2);
   grp.add_edge(2, 3);
   grp.add_edge(2, 1);
   grp.add_edge(0, 3);

   // Traverse with DFS
   printf("Traversing with DFS: \n");
   grp.depth_first_search();
   std::cout << "\n";

   // Reset graph colors for BFS traversal
   for (auto& u:grp.vertices) {
      u.color = grp.WHITE;
   }

   // Traverse with BFS
   printf("Traversing with BFS: \n");
   grp.breadth_first_search();
   std::cout << "\n";

   // Finally, find shortest paths from first node with Dijkstra's algorithm
   printf("Dijkstra for shortest paths: \n");
   grp.dijkstra();
}