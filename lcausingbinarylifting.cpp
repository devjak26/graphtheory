#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll N = 10000;
vector<ll> adj[N];
bool vis[N];
ll par[N], level[N];
 

void dfs(ll node)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            par[it] = node;
            level[it]=level[node]+1;
            dfs(it);
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = 0;
        par[i] = -1;
        level[i]=0;
    }

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    ll mxdiffval = log2(n);
    ll rootnode = 1;

    ll sparsetable[mxdiffval+ 1][n + 1];

    memset(sparsetable, -1, sizeof(sparsetable));

    for (int i = 0; i <= mxdiffval; i++)
    {
        for (int j = 2; j <= n; j++)
        {
        
                if (i == 0)
                    sparsetable[i][j] = par[j];

                else
                {
                    // cout<<i<<" "<<j<<" "<<sparsetable[i][j]<<endl;
                    if (sparsetable[i - 1][j] != -1)
                    {
                        sparsetable[i][j] = sparsetable[i - 1][sparsetable[i - 1][j]];
                    }

                    else
                        sparsetable[i][j] = -1;
                }
            

            // cout << sparsetable[i][j] << " ";
        }
        // cout << endl;
    }

    ll Q;
    cin>>Q;

    while(Q--)
    {
        ll x,y;
        cin>>x>>y;

        if(level[y]<level[x])
            swap(x,y);

        ll leveldiff=level[y]-level[x];

        while(leveldiff>0)
        {
            ll val=log2(leveldiff);
            leveldiff-=(1<<val);

            y=sparsetable[val][y];
        }

        // cout<<x<<" "<<y<<endl;

        if(x==y)
        {
            cout<<x<<endl;
            continue;
        }

        while(par[x]!=par[y])
        {
            for(int i=0;i<=mxdiffval;i++)
            {
                ll tempx=sparsetable[i][x];
                ll tempy=sparsetable[i][y];

                if(tempx!=-1 && tempy!=-1 && tempx!=tempy)
                {
                    x=tempx;
                    y=tempy;
                }
            }
        }

        cout<<par[x]<<endl;
    }

    return 0;
}

/*

12 11
1 2
1 3
2 4
2 5
5 6
5 7
5 8
7 9
4 10
4 11
11 12
*/

