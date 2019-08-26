#include <cstdio>
#include <algorithm>
#define MAXN 700
#define MAXM 150000
using namespace std;

// ---------------------
struct t_aresta
{
    int dist, x, y;
};

bool comp(t_aresta a, t_aresta b)
{
    return a.dist<b.dist;
}

//-------------------

int pai[MAXN], peso[MAXN], n, m, soma;
t_aresta aresta [MAXM];

//------------------
// DSU begin
int achar(int u)
{
    if(pai[u] == u) return u;
    return pai[u] = achar(pai[u]);
}

void join(int u, int v)
{
    u = achar(u);
    v = achar(v);

    if( u == v) return;

    if(peso[u]>peso[v])  pai[v] = u;

    if(peso[u]<peso[v])  pai[u] = v;

    if(peso[v] == peso[u])
    {
        pai[u] = v;
        peso[v] ++;
    }

}

// DSU end
int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 1; i<= m; i++)
        scanf("%d %d %d", &aresta[i].x, &aresta[i].y, &aresta[i].dist);

    for(int i = 1; i<= n; i++) pai[i] = i;

    sort(aresta+1, aresta + m+1, comp);

    for(int i = 1; i<= m;i++)
    {
        if(achar(aresta[i].x) != achar(aresta[i].y))
        {
            join(aresta[i].x, aresta[i].y);
            soma += aresta[i].dist;
        }
    }

    printf("%d\n", soma);

    return 0;
}
