#include "ListGraph.h"

ListGraph::ListGraph(const int &verticesNumber) {
    for (int i = 0; i < verticesNumber; ++i) {
        listFrom.emplace_back();
        listTo.emplace_back();
    }
}

ListGraph::ListGraph(IGraph *other) : IGraph(other) {
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> vertices;
        other->GetNextVertices(i, vertices);
        listFrom.push_back(ConvertVector(vertices));

        vertices.clear();
        other->GetPrevVertices(i, vertices);
        listTo.emplace_back(ConvertVector(vertices));
    }
}

void ListGraph::AddEdge(int from, int to) {
    if (from >= 0 && from < listFrom.size() && to >= 0 && to < listFrom.size()) {
        listFrom[from][to] = true;
        listTo[to][from] = true;
    }
}

int ListGraph::VerticesCount() const {
    return listFrom.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (!vertices.empty()) {
        vertices.clear();
    }

    for (auto & i : listFrom[vertex]) {
        vertices.push_back(i.first);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (!vertices.empty()) {
        vertices.clear();
    }

    for (auto & i : listTo[vertex]) {
        vertices.push_back(i.first);
    }
}

void ListGraph::Print() const {
    std::cout << "From" << std::endl;
    for (int i = 0; i < listFrom.size(); ++i) {
        std::cout << i << "( ";
        for (auto & j : listFrom[i]) {
            std::cout << j.first << " ";
        }
        std::cout << ")" << std::endl;
    }
    std::cout << "To" << std::endl;
    for (int i = 0; i < listTo.size(); ++i) {
        std::cout << i << "( ";
        for (auto & j : listTo[i]) {
            std::cout << j.first << " ";
        }
        std::cout << ")" << std::endl;
    }
}

std::map<int, bool> ListGraph::ConvertVector(const std::vector<int>& vector) {
    std::map<int, bool> temp;
    for(auto & i : vector) {
        temp[i] = true;
    }
    return temp;
}




