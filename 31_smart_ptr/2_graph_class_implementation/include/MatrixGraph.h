#pragma once

#include "IGraph.h"

class MatrixGraph : public IGraph {
public:
    MatrixGraph(const int& verticesNumber);
    MatrixGraph(IGraph* other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void Print() const override;
private:
    std::vector<std::vector<bool>> matrix;
};

