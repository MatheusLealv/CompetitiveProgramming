#include <bits/stdc++.h>
#define N 8005
using namespace std;
typedef long long ll;

ll dp[N][805], opt[N][805], C[N], n, G, pref[N];

inline ll custo(int i, int j)
{
    return (pref[i] - pref[j - 1])*(i - j + 1);
}

void solve(int l1, int r1, int l2, int r2, int k)
{
    if(l2 > r2) return;

    int mid = (l2 + r2)/2;

    for(int i = l1; i <= min(mid, r1); i++)
    {
        if(dp[mid][k] > dp[i - 1][k - 1] + custo(mid, i))
        {
            opt[mid][k] = i;

            dp[mid][k] = dp[i - 1][k - 1] + custo(mid, i);
        }
    }

    solve(l1, opt[mid][k], l2, mid - 1, k), solve(opt[mid][k], r1, mid + 1, r2, k);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>G;

    for(int i = 1; i <= n; i++)
    {
        cin>>C[i];

        pref[i] = pref[i - 1] + C[i];
    }

    memset(dp, 0x3f3f3f3f, sizeof dp);

    dp[0][0] = 0;

    for(int k = 1; k <= G; k++) solve(1, n, 1, n, k);

    cout<<dp[n][G]<<"\n";
}