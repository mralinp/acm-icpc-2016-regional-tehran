// C++ program for implementation of Ford Fulkerson algorithm
#include <bits/stdc++.h>
using namespace std;
#define V 500
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    int rGraph[V][V]; 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
    int parent[V];
    int max_flow = 0; 
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    ios_base::sync_with_stdio(false);//Make cin and cout Run Faster... :)
    while(true) {
        int n,e,m,t,c;cin>>n>>e>>m>>t>>c;
        if(n == 0 and e == 0 and m == 0 and t == 0 and c == 0 ){
            break;
        }
        int graph[V][V] = {{0}};
        for(int i = 0 ; i < e ; i++){
            int a, b;cin>>a>>b;
            a--;
            b--;
            graph[a][b]++;
        }
        m--;t--;
        int cu = fordFulkerson(graph, m, t);
        //cout<<cu<<endl;
        long long c1 = c/cu;
        long long c2 = c%cu;
        long long c3 = cu-c2;
        cout<<c3*c1*c1*c1 + c2*(c1+1)*(c1+1)*(c1+1)<<endl;
    }
    return 0;
}
