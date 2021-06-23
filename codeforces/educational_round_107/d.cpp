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
    //w(x)
    {
        de(n);
        de(k);
        ll arr[k][k];
        re(i,k)
        {
            re(j,k)
            arr[i][j]=0;
        }
        if(n==1)
        {
            cout<<"a";
        }
        else{
            string a="aa";
            arr[0][0]=1;
            ll sum=0;
            ll index=1;
            re(i,n-2)
            {
                char prev=a[index];
                ll number =prev-'a';
                ll index1=0;
                re(j,k)
                {
                    if(arr[number][index1]>arr[number][j])
                    {
                        index1=j;
                    }
                    else if(arr[number][index1]==arr[number][j])
                    {
                        ll min1=1e7,min2=1e7;
                        re(f,k)
                        {
                            min1=min(min1,arr[index1][f]);
                            min2=min(min2,arr[j][f]);
                        }
                        if(min2<min1)
                        index1=j;
                    }
                }
                index++;
                a+=(index1+'a');
                arr[number][index1]+=1;
            }
            cout<<a;
        }
    }
}
