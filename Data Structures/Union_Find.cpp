#include <bits/stdc++.h>

int pai[100500], peso[100500], ponto[100500], cont = 0;

int Find(int u)
{
    if(u == pai[u]) return u;

    return pai[u] = Find(pai[u]);
}

void Join(int u, int v)
{
    u = Find(u);

    v = Find(v);

    if(u == v) return;

    if(peso[u] > peso[v]) pai[v] = u;

  	else if(peso[u] < peso[v])pai[u] = v;

    else if(peso[u] == peso[v])
    {
        pai[v] = u;

        peso[v] ++;
    }
}

int main()
{
}