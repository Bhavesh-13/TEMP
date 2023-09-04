#include <iostream>
using namespace std;

float cost[10][10];
int vt[10], et[10][10], vis[10], j, n;
float sum = 0;
int x = 1;
int e = 0;

void prims();

int main() {
    int i;
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    cout << "Enter the cost adjacency matrix" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
        vis[i] = 0;
    }
    prims();
    cout << "Edges of spanning tree" << endl;
    for (i = 1; i <= e; i++) {
        cout << et[i][0] << "," << et[i][1] << "\t";
    }
    cout << "weight=" << sum << endl;
    return 0;
}

void prims() {
    int s, m, k, u, v;
    float min;
    vt[x] = 1;
    vis[x] = 1;
    for (s = 1; s < n; s++) {
        j = x;
        min = 999;
        while (j > 0) {
            k = vt[j];
            for (m = 2; m <= n; m++) {
                if (vis[m] == 0) {
                    if (cost[k][m] < min) {
                        min = cost[k][m];
                        u = k;
                        v = m;
                    }
                }
            }
            j--;
        }
        vt[++x] = v;
        et[s][0] = u;
        et[s][1] = v;
        e++;
        vis[v] = 1;
        sum = sum + min;
    }
}
