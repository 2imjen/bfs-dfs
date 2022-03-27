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

int cntConnectedComponent()
{
    int cnt = 0;

    for (int i = 1; i <= m; i++)
    {
        if (!visited[i])
        {
            cnt++;
            bfs(i);
        }
    }

    return cnt;
}

// Input
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

    cout << "\nSo luong thanh phan lien thong: " << cntConnectedComponent() << endl;

    return 0;
}