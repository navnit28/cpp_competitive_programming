#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ss second
#define ff first
#define mod 1000000007
#define w(x) ll x; cin>>x; while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define fo(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define re(i, j) fo(i, 0, j, 1)
#define pi acos(-1)
#define all(cont) cont.begin(), cont.end()
#define countbit(x) __builtin_popcount(x)
#define mod 1000000007
#define de(n) ll n;cin>>n;
#define def(a,n) ll n;cin>>n;ll a[n];re(i,n){cin>>a[i];}
#define defi(a,n,k) ll n;cin>>n; ll k;cin>>k;ll a[n];re(i,n){cin>>a[i];}
#define deb(x) cout<<#x<<"="<<x<<endl;
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define nl cout<<endl;
using namespace std;
//912B 1009B 1350C 20C 1333C 1234D 1327C 1305B 1304B (or in matrix) 1216-C(26) 21
void cp()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const ll N=100005;
vector<ll> adj[N];
ll lo[N];
ll hi[N];
pair<ll,ll> dfs(ll a,ll par)
{
    ll one=0;
    ll two=0;
    for(auto b:adj[a])
    {
        if(b==par)
        {
            continue;
        }
        pair<ll,ll> ch=dfs(b,a);
        one+=max(ch.first+abs(lo[a]-lo[b]),ch.second+abs(lo[a]-hi[b]));
        two+=max(ch.first+abs(hi[a]-lo[b]),ch.second+abs(hi[a]-hi[b]));
    }
    return {one,two};
}
int main()
{
   cp();
    //sieve();
    w(x)
    {
        de(n);
        for(ll i=1;i<=n;i++)
        {
            cin>>lo[i]>>hi[i];
        }
        for(ll i=1;i<=(n-1);i++)
        {
            de(xx);
            de(yy);
            adj[xx].push_back(yy);
            adj[yy].push_back(xx);
        }
        pair<ll,ll>p=dfs(1,-1);
        cout<<max(p.first,p.second);
        nl;
        for(ll i=0;i<=n;i++)
        {
            adj[i].clear();
        }
    }

}
