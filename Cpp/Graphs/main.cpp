#include "graph.h"

int main(int argc, char ** argv) {
   Graph grp(4);
   grp.add_edge(0, 1);
   grp.add_edge(1, 2);
   grp.add_edge(2, 3);
   grp.add_edge(2, 1);
   grp.add_edge(0, 3);
   grp.depth_first_search();
   std::cout << "\n";

   for (auto& u:grp.vertices) {
      u.color = grp.WHITE;
   }

   grp.breadth_first_search();
   std::cout << "\n";
}