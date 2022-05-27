#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(const int &verticesNumber) {
    std::vector<bool> temp( verticesNumber);
    for (int i = 0; i < verticesNumber; ++i) {
        matrix.push_back(temp);
    }
}

MatrixGraph::MatrixGraph(IGraph* other) : IGraph(other) {
    for (int i = 0; i < other->VerticesCount(); ++i) {
        std::vector<int> nextVertices;
        other->GetNextVertices(i, nextVertices);

        std::vector<bool> temp( other->VerticesCount());
        matrix.push_back(temp);

        for (auto & j : nextVertices) {
            matrix[i][j] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    if (from >= 0 && from < matrix.size() && to >= 0 && to < matrix.size()) {
        matrix[from][to] = true;
    }
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (!vertices.empty()) {
        vertices.clear();
    }

    for (int i = 0; i < matrix[vertex].size(); ++i) {
        if (matrix[vertex][i]) {
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (!vertices.empty()) {
        vertices.clear();
    }

    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][vertex]) {
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::Print() const {
    for (auto& i : matrix) {
        for(auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


