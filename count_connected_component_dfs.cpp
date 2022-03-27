#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
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

int countConnectedComponent()
{
    int cnt = 0;

    for (int i = 1; i <= m; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }

    return cnt;
}

//Input
/*
9 7
1 2
1 3
2 4
2 6
3 6
5 8
8 9
*/

int main()
{
    input();
    init();
    
    cout << "\nSo luong thanh phan lien thong: " << countConnectedComponent() << endl;

    return 0;
}