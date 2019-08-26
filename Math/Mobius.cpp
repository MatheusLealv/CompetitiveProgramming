struct MFunction
{
    ll menorfat[N], nprimo[N], ans[N], mi[N];

    vector<ll> primes;

    inline void build(ll n = N)
    {   
        mi[1] = 1;

        for(ll i = 0; i < N; i++) menorfat[i] = 1000000000;

        for(ll i = 2; i < n; i++)
        {
            if(!nprimo[i])
            {
                primes.push_back(i);

                menorfat[i] = i;
            }

            for(ll j = 0; j < primes.size() and i*primes[j] < n; j++)
            {
                nprimo[i*primes[j]] = 1;

                menorfat[i*primes[j]] = min(menorfat[i*primes[j]],primes[j]);

                if(!nprimo[i]) menorfat[i*primes[j]] = min(menorfat[i*primes[j]], (ll)i);

                if(!(i % primes[j])) break;
            }
        }
    }

    inline ll solve(ll n)
    {
        ll davez = menorfat[n], qnt = menorfat[n];

        ll resp = 1LL, resp2 = 1LL;

        while(n > 1)
        {
            n /= menorfat[n];

            if(davez != menorfat[n])
            {
                resp *= ans[qnt];

                resp2 *= mi[qnt];

                qnt = menorfat[n];
            }

            else qnt *= menorfat[n];

            davez = menorfat[n];
        }

        return resp2;
    }
} F;

void preprocess()
{
    for(ll i = 0; i < F.primes.size(); i++)
    {
        ll p = F.primes[i];

        ll t = 1;

        F.mi[p] = (t == 0) - (t == 1);

        ll q = p;

        while(p < N)
        {
            if(p > N/q) break;

            p *= q, t ++;

            F.mi[p] = (t == 0) - (t == 1);
        }
    }   
}
