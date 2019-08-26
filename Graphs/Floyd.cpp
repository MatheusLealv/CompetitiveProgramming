#include <bits/stdc++.h>
using namespace std;
int n, m, mat[150][150];

int main()
{
    cin>>n>>m;

    for(int i =0; i<=n; i++)
        for(int j = 0; j<=n; j++) mat[i][j] = 99999999;

    for(int i = 1; i<=m; i++)
    {
        int x, y ,v;
        
        cin>>x>>y>>v;
        
        x++; y++;
        
        mat[x][y] = v;
        
        mat[y][x] = v;
    }

    int maior = 99999999, ans = 0;

    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for(int i = 1; i<=n; i++)
    {
        ans = 0;
        for(int j = 1; j<=n; j++)
        {
            ans = max(ans, mat[i][j]);
        }
        maior = min(ans, maior);
    }

    cout<<maior<<endl;
}
