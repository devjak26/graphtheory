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
#define endL cout << "\n"
#define endl "\n"
#define setBit(x) __builtin_popcount(x)
#define ss second
#define ff first
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>

ll adj[100][100];
ll INF = 1e11;

void fun(ll n)
{
    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (adj[i][k] != INF && adj[k][j] != INF)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main()
{
    // fast_io
    // cout << "Enter Number of nodes and edges:" << endl;

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        // cout << "Enter all edges: " << endl;

        lp(i, 0, n + 1)
        {
            lp(j, 0, n + 1)
            {
                if (i == j)
                    adj[i][j] = 0;

                else
                    adj[i][j] = INF;
            }
        }

        lp(i, 0, m)
        {
            ll x, y, wt;
            cin >> x >> y >> wt;

            adj[x][y] = wt;
        }

        fun(n);

        // cout << "Distance matrix: " endl;
        bool bb = 1;

        lp(i, 1, n + 1)
        {
            lp(j, 1, n + 1)
            {
                if (i == j)
                {
                    if (adj[i][j] < 0)
                        bb = 0;
                }
            }
        }

        bb==0 ? cout << "True" : cout << "False";
        endL;
    }

    return 0;
}

/*
5 9
5 1 3
5 4 -4
4 3 6
3 2 -5
3 5 2
5 2 8
2 1 4
1 3 1
1 4 7

*/