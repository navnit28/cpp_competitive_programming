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
int main()
{
    cp();
    //sieve();
    w(x)
    {
        de(r);
        de(w);
        char a[r][w];
        re(i,r)
        {
            re(j,w)
            cin>>a[i][j];
        }
        ll r1=-1;
        char q1;
        re(i,r)
        {
            re(j,w)
            {
                if(a[i][j]!='.')
                {
                    q1=a[i][j];
                    r1=(i+j)%2;
                    break;
                }
            }
        }
        char q2;
        if(r1==-1)
        {
            r1=0;
            q1='R';
        }
        if(q1=='R')
        q2='W';
        else{
            q2='R';
        }
        bool f=0;
        re(i,r)
        {
            re(j,w)
            {
                if(a[i][j]=='.')
                {
                    if((i+j)%2==r1)
                    {
                        a[i][j]=q1;
                    }
                    else{
                        a[i][j]=q2;
                    }
                }
                else
                {
                    if((i+j)%2==r1)
                    {
                        if(a[i][j]!=q1)
                        f=1;
                    }
                    else{
                        if(a[i][j]!=q2)
                        {
                            f=1;
                        }
                    }
                }
            }
        }
        if(f)
        cout<<"NO\n";
        else{
            cout<<"YES\n";
            re(i,r)
            {
                re(j,w)
                cout<<a[i][j];
                nl;
            }
        }
    }
}
