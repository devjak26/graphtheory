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

struct edge{
     ll u;
     ll v;
     ll w;
};

bool comp(edge a,edge b)
{

    if(a.w<b.w) return true;

    else return false;

}
edge arr[200002];
ll par[200002];

ll find(ll a)
{
    if(par[a]==-1) return a;

    else return par[a]=find(par[a]);
}

void merge(ll a,ll b)
{
    par[a]=b;
}

int main()
{
    fast_io
  
     ll n,m ;
     cin>>n>>m;
     
      lp(i,0,n+1) par[i]=-1;

     lp(i,0,m)
     {
         cin>>arr[i].u>>arr[i].v>>arr[i].w;
 
     }

    sort(arr,arr+m,comp);

    lp(i,0,m)
    {
        ll  a=find(arr[i].u);
         ll b=find(arr[i].v);
        
        if(a!=b)
        { 
            merge(a,b);
        }
    }
     
    return 0 ;
}