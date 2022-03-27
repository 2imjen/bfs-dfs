#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

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

void bfs(int u)
{
    queue<int> q;

    q.push(u);
    
    visited[u] = true;

    while (!q.empty())
    {
        int v = q.front();

        q.pop();

        cout << v << " ";

        for (int x : adj[v])
        {
            if (!visited[x])
            {
                q.push(x);

                visited[x] = true;
            }
        }

    }
}

// Input
/*
9 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9
*/

int main()
{
    input();
    init();

    bfs(1);

    return 0;
}