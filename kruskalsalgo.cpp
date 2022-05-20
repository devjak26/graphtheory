#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lp(i, a, b) for (int i = a; i < b; i++)
#define lp1(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define pb1 pop_back
#define endL cout << "\n"
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define setBit(x) __builtin_popcount(x)
#define ss second
#define ff first
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define all(x) x.begin(), x.end()
const ll N = 1e4;
ll par[N], si[N];

bool comp(const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b)
{
    return (get<2>(a) < get<2>(b));
}

ll find(ll a)
{
    if (par[a] == a)
        return a;

    return par[a] = find(par[a]);
}

void Union(ll a, ll b)
{
    if (si[a] < si[b])
        swap(a, b);

    par[b] = a;
    si[a] += si[b];
}

int main()
{

    ll test = 1;
    // cin>>test;

    while (test--)
    {
        ll n, m;
        cin >> n >> m;

        vector<tuple<ll, ll, ll>> vt;
        vector<tuple<ll, ll, ll>> ans;

        lp(i, 0, m)
        {
            ll a, b, w;
            cin >> a >> b >> w;

            vt.pb(make_tuple(a, b, w));
        }

        lp(i, 0, n + 1)
        {
            si[i] = 1;
            par[i] = i;
        }

        sort(vt.begin(), vt.end(), comp);

        for (auto it : vt)
        {
            if (ans.size() == (n - 1))
                break;

            ll a = find(get<0>(it));
            ll b = find(get<1>(it));

            if (a != b)
            {
                ans.pb(it);
                Union(a, b);
            }
        }

        ll sum = 0;

        for (auto it : ans)
        {
            cout << get<0>(it) << "-->" << get<1>(it) << "   " << get<2>(it) << endl;
            sum += get<2>(it);
        }

        cout << "Total mst sum: " << sum << endl;
    }

    return 0;
}