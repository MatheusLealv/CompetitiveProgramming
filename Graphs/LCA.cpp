//Menor Ancestral Comum
// O(log(N)) por consulta

#include <bits/stdc++.h>
#define N 50050
#define M 25
using namespace std;

long long int n, ok[N], par[N], pai[N], nivel[N], ancestral[N][M];
vector<int> grafo[N];

void dfs(long long int x)
{
    for(int i = 0; i<grafo[x].size();i++)
    {
        long long int v = grafo[x][i];
        if(nivel[v] == -1)
        {
            nivel[v] = nivel[x] + 1;
            pai[v] = x;
            dfs(v);
        }
    }
}

long long int LCA(int u, int v)
{
    if(nivel[v] > nivel[u]) swap(u, v);

    for(int i = M - 1; i>=0; i--)
        if(nivel[u] - (1<<i) >= nivel[v]) u = ancestral[u][i];

    if(u == v) return u;

    for(int i = M - 1; i>=0; i--)
    if(ancestral[u][i] != -1 & ancestral[u][i] != ancestral[v][i])
    {
       u = ancestral[u][i];
       v = ancestral[v][i];
    }

    return ancestral[u][0];
}
int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        int k;
        cin>>k;
        if(ok[k] != 0)
        {
            par[i] = ok[k];
            par[ok[k]] = i;
        }
        ok[k] = i;
    }
   // for(int i = 1; i<=n; i++)
    //cout<<i<<" "<<par[i]<<"\n";

  for(int i = 1; i<n; i++)
  {
      int a, b;
      cin>>a>>b;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
  }

  for(int i = 0; i<N;i++)
  {
      pai[i] = nivel[i] = -1;

      for(int j = 0; j<M;j++)
        ancestral[i][j] = -1;
  }

    pai[1] = 1;
    nivel[1] = 0;
    dfs(1);

    for(int i = 1; i<=n; i++) ancestral[i][0] = pai[i];

    for(int j = 1; j<M; j++)
        for(int i = 1; i<=n; i++)
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

    long long int T = 0;

    for(int i = 1; i<=n; i++)
    {
        T += nivel[i] + nivel[par[i]] - 2* nivel[LCA(i, par[i])];
        //cout<<nivel[i]<<" "<<nivel[par[i]]<<" "<<nivel[LCA(i, par[i])]<<endl;
    }

    cout<<T/2<<endl;

}
