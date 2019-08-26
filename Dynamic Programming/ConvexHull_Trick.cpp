 
#include <bits/stdc++.h>
#define N 100050
#define llg int
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, x[N], c[N], dp[N], p, r, T;

bool bad(pii A, pii B, pii C)
{
    return (ll)(B.s - A.s)*(A.f - C.f) > (ll)(C.s - A.s)*(A.f - B.f);
}

ll f(pii r, ll x)
{
    return r.f*x + r.s;
}

vector<pii> func;

void addline(pii r)
{
    while(func.size() >= 2 && bad(func[func.size() - 2], func[func.size() - 1], r))  func.pop_back();

    func.push_back(r);
}

ll query(ll x)
{
    if(p >= func.size()) p = func.size() - 1;

    while(p < func.size() - 1 && f(func[p], x) < f(func[p + 1], x)) p++;

    return f(func[p], x);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>T;

    while(T--)
    {
        cin>>n;

        for(int i = 1; i <= n; i++) cin>>x[i]>>c[i];

        dp[1] = r = 0, func.clear();

        addline(pii(x[1], -c[1] - (x[1]*x[1])));

        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(0LL, query(x[i]));

            addline(pii(x[i], dp[i] - x[i]*x[i] - c[i]));
        }

        if(dp[n] - c[n] > 0)cout<<"Ganha "<<dp[n] - c[n]<<"\n";
        else cout<<"Perde "<<c[n] - dp[n]<<"\n";
    }
}
