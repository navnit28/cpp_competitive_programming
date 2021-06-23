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
ll const N=1e6+5;
ll m[N],lp[N];
void sieve(){
	m[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) for (int j = i; j < N; j += i)
            if (!lp[j]) lp[j] = i;
        m[i] = [](int x) {
            int cnt = 0;
            while (x > 1) {
                int k = 0, d = lp[x];
                while (x % d == 0) {
                    x /= d;
                    ++k;
                    if (k > 1) return 0;
                }
                ++cnt;
            }
            if (cnt & 1) return -1;
            return 1;
        }(i);
    }
}
 
int mob(int x){
	return m[x];
}
 
void solve(){
	int l,r;
	cin >> l >> r;
	if(l == 1) l++;
	
	
	int ans = 0;
    for(ll g=2;g<N;g++)
    {
		int cnt = r / g - (l - 1) / g;
		ans -= mob(g) * cnt * cnt;
	}
    for(ll i=l;i<r+1;i++)
    {
		for(int j = i; j <= r; j+=i){
			ans--;
			if(i != j) ans--;
		}
	}
	
	cout << ans;
}
int main()
{
   cp();
    sieve();
    //w(x)
    {
        de(l);
        de(r);
        if(l==1)
        l++;
        ll ans=0;
        for(ll g=2;g<N;g++)
        {
            ll cnt = r /g - (l - 1) / g;
           // deb(cnt);
		    ans -= mob(g) * cnt * cnt;
            //deb(ans);
        }
        for(ll i=l;i<=r;i++)
        {
            for(ll j=i;j<=r;j+=i)
            {
                ans--;
                if(i!=j)
                ans--;
            }
        }
        cout<<ans;
    }

}
