#pragma once

#include <map>

#include "IGraph.h"

class ListGraph  : public IGraph {
public:
    ListGraph(const int& verticesNumber);
    ListGraph(IGraph* other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void Print() const override;
private:
    std::vector<std::map<int, bool>> listFrom;
    std::vector<std::map<int, bool>> listTo;

    static std::map<int, bool> ConvertVector(const std::vector<int>& vector);
};

