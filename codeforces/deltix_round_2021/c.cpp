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
void print(vector<ll>a)
{
    cout<<a[0];
    for(ll i=1;i<a.size();i++)
    {
        cout<<"."<<a[i];
    }
    nl;
}
int main()
{
   cp();
    //sieve();
    w(x)
    {
        de(n);
        vector<vector<ll>>a;
        a.push_back({});
        while (n--)
        {
            /* code */
            de(x);
            if(x==1)
            {
                vector<ll>temp=a.back();
                ll jj=1;
                temp.push_back(jj);
                a.push_back(temp);
                print(temp);
            }
            else
            {
                while(a.back().back()!=x-1)
                {
                    a.pop_back();
                }
                a.back().back()++;
                print(a.back());

            }
        }
    }
}
