 #include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
#define fast_io  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lp(i,a,b) for(int i=a;i<b;i++)
#define lp1(i,a,b) for(int i=a-1;i>=b;i--)
#define pb push_back
#define pb1 pop_back
#define ss second
#define ff first
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >

const ll N=1000;
vll v[N];
ll vis[N];
ll in[N],low[N];
ll timer;

void dfs(ll node,ll par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;

   for(ll child:v[node])
   {
       if(child==par)
            continue;

       else if(vis[child]==1)
            low[node]=min(in[child],low[node]);
       

       else
       {
           dfs(child,node);

           if(low[child]>in[node])
            cout<<node<<"->> "<<child<<" bride"<<endl;

            low[node]=min(low[child],low[node]);

       }

   }
   
}

int main()
{
    fast_io

    ll n,m;
    cin>>n>>m;

    ll a,b;

    lp(i,0,m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }  

    dfs(1,-1);

    return 0 ;
}

// 4 4
// 1 2
// 2 3
// 2 4
// 3 4
