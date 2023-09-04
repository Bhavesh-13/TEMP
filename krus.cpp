#include <iostream>
using namespace std;

int find(int v, int parent[10]) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void union1(int i, int j, int parent[10]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void kruskal(int n, int a[10][10]) {
    int count, k, min, sum, i, j, u, v;
    int t[10][10], parent[10];
    count = 0;
    k = 0;
    sum = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count != n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] < min && a[i][j] != 0) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u, parent);
        j = find(v, parent);

        if (i != j) {
            union1(i, j, parent);
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum = sum + a[u][v];
        }
        a[u][v] = a[v][u] = 999;
    }

    if (count == n - 1) {
        cout << "spanning tree" << endl;
        for (i = 0; i < n - 1; i++) {
            cout << t[i][0] + 1 << " " << t[i][1] + 1 << endl;
        }
        cout << "cost of spanning tree=" << sum << endl;
    } else {
        cout << "spanning tree does not exist" << endl;
    }
}

int main() {
    int n, i, j, a[10][10];
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the adjacency matrix" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    kruskal(n, a);
    return 0;
}
