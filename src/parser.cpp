#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("i.txt");
    int num_vertices;
    vector<vector<int>> adj_matrix;
    int i, j;

    if (!input.is_open()) {
        cout << "Error opening file.\n";
        return 1;
    }

    input >> num_vertices;

    adj_matrix.resize(num_vertices);
    for (i = 0; i < num_vertices; i++) {
        adj_matrix[i].resize(num_vertices);

        for (j = 0; j < num_vertices; j++) {
            input >> adj_matrix[i][j];
        }
    }

    cout << "Adjacency Matrix:\n";
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    input.close();
    return 0;
}
