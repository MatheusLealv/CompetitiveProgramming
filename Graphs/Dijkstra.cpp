#include <bits/stdc++.h>
using namespace std;
const int N = 1500;
vector< pair<int, int> > grafo[N];
priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > >pq;
int dist[N];
int dijkstra(int s)
{
    pq.push(make_pair(0, 0));
    
    while(!pq.empty())
    {
        int x = pq.top().second;
        
        int d = pq.top().first;
        
        pq.pop();
        
        if(d > dist[x]) continue;
        
        for(int i = 0; i< grafo[x].size(); i++)
        {
            int v = grafo[x][i].first;
            
            int custo = grafo[x][i].second;
            
            if(dist[v] > d + custo)
            {
                dist[v] = custo + d;
                
                pq.push(make_pair(d+custo, v));
            }
        }
    }
    return dist[s];
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i<=m; i++)
    {
        int x, y, p;
        scanf("%d %d %d", &x, &y, &p);
        
        grafo[x].push_back(make_pair(y, p));
        
        grafo[y].push_back(make_pair(x, p));
    }
    
    for(int i = 0; i<=n+1; i++) dist[i] = 999999999;
    
    printf("%d\n", dijkstra(n+1));
}
