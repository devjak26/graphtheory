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
 
 const ll N=10003;
 vll v[N];
 vll out;
 ll in[N];

 void kahn(ll n)
 {
     priority_queue<ll,vector<ll>,greater<ll> > q;
     lp(i,1,n+1)
     {
         if(in[i]==0) q.push(i);
     }
     while(!q.empty())
     {
         ll x=q.top();

         out.pb(x);

         q.pop();

         for(ll ch:v[x])
         {
             in[ch]--;
             if(in[ch]==0) q.push(ch);
         }

     }

    bool ff=0;

    lp(i,1,n+1)
    {
        if(in[i]>0) ff=1;
    }

    if(ff==1) cout<<"Sandro fails.";
    else
    {
         lp(i,0,n)
        cout<<out[i]<<" ";
    }
 }

int main()
{
    fast_io
 
    ll n,m;
    cin>>n>>m;

    lp(i,0,m)
    {
         ll a,b;
         cin>>a>>b;

         v[a].pb(b);
         in[b]++;

    }
    kahn(n);

    return 0 ;
}