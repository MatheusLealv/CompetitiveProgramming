#include <bits/stdc++.h>
#define N 500050
using namespace std;
int bit[N];

void upd(int x, int v)
{
    for(int i = x; i < N; i += (i&-i)) bit[i] += v;
}

int query(int x)
{
    int sum = 0;

    for(int i = x; i > 0; i -= (i&-i)) sum += bit[i];

    return sum;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
}