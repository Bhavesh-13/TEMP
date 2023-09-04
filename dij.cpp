#include <iostream>
using namespace std;

void dijkstras();
int c[10][10], n, src;

int main() {
    int i, j;
    cout << "Enter number of vertices:";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    cout << "Enter the source node:\t";
    cin >> src;
    dijkstras();
    return 0;
}

void dijkstras() {
    int vis[10], dist[10], u, i, j, count, min;
    for (j = 1; j <= n; j++) {
        dist[j] = c[src][j];
    }
    for (j = 1; j <= n; j++) {
        vis[j] = 0;
    }
    dist[src] = 0;
    vis[src] = 1;
    count = 1;
    while (count != n) {
        min = 9999;
        for (j = 1; j <= n; j++) {
            if (dist[j] < min && vis[j] != 1) {
                min = dist[j];
                u = j;
            }
        }
        vis[u] = 1;
        count++;
        for (j = 1; j <= n; j++) {
            if (min + c[u][j] < dist[j] && vis[j] != 1) {
                dist[j] = min + c[u][j];
            }
        }
    }
    cout << "\nThe shortest distance is:" << endl;
    for (j = 1; j <= n; j++) {
        cout << src << " to " << j << "=" << dist[j] << " ";
    }
    cout << endl;
}
