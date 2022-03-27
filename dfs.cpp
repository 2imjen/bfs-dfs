#include <iostream>
#include <cstring>
#include <vector>

using namespace std;



// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9

int m, n; //m = vertexs, n = edges
bool visited[10000];
vector<int> adj[10000];

void input()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        int x, y;

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void init()
{
    memset(visited, false, sizeof visited);
}

void dfs(int v)
{
    // thăm đỉnh v
    visited[v] = true;

    // In ra màn hình đỉnh đã thăm
    cout << v << " ";

    // Duyệt các đỉnh kề với v
    for (int u : adj[v])
        if (!visited[u])
            dfs(u);
}

int main()
{
    input();
    init();
    dfs(1);

    return 0;
}