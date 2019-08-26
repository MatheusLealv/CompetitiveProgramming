//Breaking Strings
#include <bits/stdc++.h>
#define N 1030
#define int long long
using namespace std;

int n, m, v[N], dp[N][N], opt[N][N], T;

main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    while(cin>>n>>m)
    {
        for(int i = 2; i <= m + 1; i++) cin>>v[i];

        v[1] = 0, v[m + 2] = n;

       for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) dp[i][j] = 3000000000000000;

        for(int s = 0; s <= m + 3; s++)
        {
            for(int l = 0; l + s <= m + 3; l++)
            {
                int r = l + s;

                if(s <= 1)
                {
                    dp[l][r] = 0;

                    opt[l][r] = l;

                    continue;
                }

                int esq = opt[l][r - 1], dir = opt[l + 1][r];

                for(int k = esq; k <= dir; k++)
                {
                    if(dp[l][r] >= dp[l][k] + dp[k][r] + v[r] - v[l])
                    {
                        dp[l][r] = dp[l][k] + dp[k][r] + v[r] - v[l];

                        opt[l][r] = k;
                    }
                }
            }
        }

        cout<<dp[1][m+2]<<"\n";
    }
}
