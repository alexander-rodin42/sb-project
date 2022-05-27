#include <iostream>

#include "IGraph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

void print_vertices(IGraph* graph) {
    std::vector<int> vertices;

    std::cout << "-------------------" << std::endl;
    graph->GetNextVertices(3, vertices);
    for (auto & i : vertices) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    vertices.clear();
    graph->GetPrevVertices(3, vertices);
    for (auto & i : vertices) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
}

int main() {
    IGraph* c = new MatrixGraph(5);

    c->AddEdge(3,4);
    c->AddEdge(3,2);
    c->AddEdge(3,0);
    c->AddEdge(1,3);
    c->AddEdge(2,3);

    c->Print();
    print_vertices(c);

    IGraph* d = new ListGraph(c);

    d->Print();
    print_vertices(d);

    return 0;
}
