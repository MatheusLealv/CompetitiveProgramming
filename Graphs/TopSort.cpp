#include <bits/stdc++.h>
#define N 50100
using namespace std;
int grau[N];
vector<int> grafo[N], lista;
priority_queue < int, vector<int>, greater<int> > heap;

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i<m; i++)
    {
        int a, b;
        
        scanf("%d %d", &a, &b);
        
        grafo[a].push_back(b);
        
        grau[b]++;
    }
    for(int i = 0; i<n; i++) if(!grau[i]) heap.push(i);

    while(!heap.empty())
    {
        int k = heap.top();
        
        heap.pop();
        
        for(int i = 0; i<grafo[k].size(); i++)
        {
            int v = grafo[k][i];
            
            grau[v]--;
            
            if(grau[v] == 0)
            {
                heap.push(v);
            }
        }
        lista.push_back(k);
    }

    if(lista.size() < n) printf("*\n");
    else
    {
        for(int i = 0; i<lista.size(); i++)
        {
            printf("%d\n", lista[i]);
        }
    }

}
