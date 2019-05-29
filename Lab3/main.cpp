#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_N 20000

using namespace std;

int main() {
    int edges, vertices;
    cout << "Enter N:\n";
    cin >> edges;

    set<int> connections[MAX_N];

    set<int> uniqueVertices;
    cout << "Enter V1 -> V2 by pairs\n";
    for (int pairNumber = 0; pairNumber < edges; pairNumber++) {
        int vertex1, vertex2;
        cin >> vertex1;
        cin >> vertex2;
        uniqueVertices.insert(vertex1);
        uniqueVertices.insert(vertex2);
        connections[vertex1].insert(vertex2);
        connections[vertex2].insert(vertex1);
    }
    vertices = uniqueVertices.size();

    for (int vert = 1; vert <= vertices; vert++) {
        for (auto conVert : connections[vert]) {
            for (auto conVertElement : connections[conVert]) {
                connections[vert].insert(conVertElement);
                connections[conVertElement].insert(vert);
            }
        }
    }

    int pairs = 0;
    for (int vert = 1; vert <= vertices; vert++) {
        for (auto vertex : uniqueVertices) {
            if (vert == vertex) {
                continue;
            }
            if (connections[vert].find(vertex) != connections[vert].end()) {
                continue;
            }
            if (!((vert % 2) == (vertex % 2))) {
                pairs++;
            }
        }
    }
    pairs /= 2;

    cout << "Pairs: " << pairs << endl;

    return 0;
}
