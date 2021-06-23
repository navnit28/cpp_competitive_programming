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
ll N=200005;
class union_find
{
	ll n;
	vector<ll> par;
	vector<ll> sz;
public:
	union_find(ll nval)
	{
		n = nval;
		par.resize(n + 1);
		sz.resize(n + 1);

		for (ll i = 1; i <= n; ++i)
			par[i] = i, sz[i] = 1;
	}

	//O(1) ammortized
	ll root(ll x)
	{
		/*while(x!=par[x])
			x=par[x];
		return x;*/

		if (x == par[x])
			return x;

		return par[x] = root(par[x]);
	}

	//O(1) ammortized
	bool find(ll a,ll b)
	{
		return root(a) == root(b);
	}

	//O(1) ammortized
	void un(ll a,ll b)
	{
		ll ra = root(a);
		ll rb = root(b);
		if (ra == rb)
			return;

		if (sz[ra] > sz[rb])
			swap(ra, rb);

		par[ra] = rb;
		sz[rb] += sz[ra];
		sz[ra]=0;
	}
    ll sq()
    {
        ll k=0;
        for(ll i=1;i<=n;i++)
        {
            if(sz[i]!=0)
            k+=(sz[i]-1);
        }
        return k;
    }
	
};
int main()
{
   cp();
    //sieve();
    //w(x)
    {
        de(n);
        ll a[n];
        union_find dsu(N);
        re(i,n)
        cin>>a[i];
        for(ll i=0;i< (n/2) ;i++)
        {
            dsu.un(a[i],a[n-1-i]);
        }
        cout<<dsu.sq();
    }

}