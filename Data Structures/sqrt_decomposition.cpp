#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;

int n, q, v[MAXN], Bucket[MAXN], raiz = 330;

int a, b, x;

const int INF = 0x3f3f3f3f;

void update(int i, int x)
{
    Bucket[i/raiz] = min(Bucket[i/raiz],v[i]);
}
 
int query(int i,int j)
{
    x = INF;

    while(i % raiz !=0 && i <= j) x = min(x,v[i]),i++;
 
    while(i + raiz- 1 <= j) x = min(x,Bucket[i/raiz]),i+=raiz;
 
    while(i <= j) x = min(x,v[i]), i++;
 
    return x;
}
 
int main()
{
}