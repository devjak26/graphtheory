#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define lp(i, a, b) for (int i = a; i < b; i++)
#define lp1(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define pb1 pop_back
#define ss second
#define ff first
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
const ll N = 1e4;

ll dis[N];

vector<pair<ll, ll>> adj[N];

int main()
{
    // fast_io

    ll n, m;
    cout << "number of vertex and edges: ";
    cin >> n >> m;

    lp(i, 0, n + 1)
        dis[i] = INT_MAX;

    ll a, b, w;

    lp(i, 0, m)
    {
        cin >> a >> b >> w;

        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    // priority_queue<ll> q;
    cout << "Root Node: ";
    int st;
    cin >> st;

    pq.push({st, 0});

    dis[st] = 0;

    while (!pq.empty())
    {
        ll x = pq.top().first;
        ll y = pq.top().ss;
        pq.pop();

        for (auto child : adj[x])
        {
            if (dis[child.ff] > (y + child.ss))
            {
                dis[child.ff] = (y + child.ss);
                pq.push({child.ff, dis[child.ff]});
            }
        }
    }
    
    cout << "Target Node: ";
    int tar;
    cin >> tar;

    cout << dis[tar] << endl;
    //  lp(i,1,n+1)
    //     cout<<dis[i]<<" ";

    return 0;
}

// 1 2 2
// 1 3 4
// 1 4 4
// 1 5 5
// 1 6 1
// 1 7 2
// 2 4 13
// 2 5 10
// 3 4 4
// 4 5 11
// 6 7 6
// 4 6 3
// 4 7 4
// 5 7 11
