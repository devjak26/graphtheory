
// O(E*logN) solution using min priority queue


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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define setBit(x) __builtin_popcount(x)
#define ss second
#define ff first
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define all(x) x.begin(), x.end()

const ll N = 1e4;

vector<pair<ll, ll>> adj[N];

int main()
{

    ll n, m;
    cout << "number of vertex and edges: ";
    cin >> n >> m;
    int vis[n + 1] = {0};
    vector<pair<ll, ll>> par(n+1);

    lp(i, 0, n + 1)
    {
        vis[i] = 0;
        par[i]={-1,INT_MAX};
    }

    ll a, b, w;

    lp(i, 0, m)
    {
        cin >> a >> b >> w;

        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    int s = 0;

    par[0] = {-1, 0};

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, s});

    while (!pq.empty())
    {
        int dis = pq.top().ff;
        int node = pq.top().ss;
        vis[node] = 1;
        pq.pop();

        for (auto ch : adj[node])
        {
            if (vis[ch.first] == 0 && par[ch.first].second > ch.second)
            {
                pq.push({ch.second, ch.first});
                par[ch.first] = {node, ch.second};
            }
        }
    }

    lp(i, 0, n)
    {
        cout << i << "->" << par[i].ff << " " << par[i].ss << endl;
    }

    return 0;
}



// O(N*N) solution 
// if we have given adjacent matrix or a dense graph then use this algo

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
#define fast_io  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lp(i,a,b) for(int i=a;i<b;i++)
#define lp1(i,a,b) for(int i=a-1;i>=b;i--)
#define pb push_back
#define pb1 pop_back
#define endL cout<<"\n"
#define endl "\n" 
#define yes cout<<"YES"<<endl 
#define no cout<<"NO"<<endl 
#define setBit(x) __builtin_popcount(x)
#define ss second
#define ff first
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >
#define all(x) x.begin(), x.end()

 
int main()
{
    fast_io
 
    ll test=1;
    // cin>>test;
 
    while(test--)
    {
        ll n,m;
        cin>>n>>m;

        ll adj[n][n];

        lp(i,0,n)
        {
            lp(j,0,n)
               {
                    adj[i][j]=INT_MAX;
               }
        }

        lp(i,0,m)
        {
            ll a,b,w;
            cin>>a>>b>>w;

            adj[a][b]=w;
            adj[b][a]=w;
        }

        ll s=0;
        bool vis[n]={0};
        ll dis[n];
        ll par[n];
        memset(dis,INT_MAX,n);

        dis[s]=0;

        
        lp(i,0,n-1)
        {
            ll md=INT_MAX, dest=0;

            lp(j,0,n)
            {
                if(dis[j]<md && vis[j]==0)
                {
                    md=dis[j];
                    dest=j;
                }
            }

            vis[dest]=1;

            lp(j,0,n)
            {
                if(dis[j]> adj[dest][j] && vis[j]==0)
                    {
                        dis[j]=adj[dest][j];
                        par[j]=dest;
                    }
            }
        }

        lp(i,1,n)
            cout<<i<<" -> "<<par[i]<<"  "<<dis[i]<<endl;

    }
 
    return 0 ;
}



/*
5 7
 0 1 5
 1 2 2
 1 3 2
 2 3 3
 3 4 3
 2 4 2
 0 2 4
*/