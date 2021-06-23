#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ss second
#define ff first
#define w(x) ll x; cin>>x; while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define fo(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define re(i, j) fo(i, 0, j, 1)
#define pi acos(-1)
#define all(cont) cont.begin(), cont.end()
#define countbit(x) __builtin_popcount(x)
#define de(n) ll n;cin>>n;
#define def(a,n) ll n;cin>>n;ll a[n];re(i,n){cin>>a[i];}
#define defi(a,n,k) ll n;cin>>n; ll k;cin>>k;ll a[n];re(i,n){cin>>a[i];}
#define deb(x) cout<<#x<<"="<<x<<endl;
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define nl cout<<endl;
using namespace std;
//912B 1009B 1350C 20C 1333C 1234D 1327C 1305B 1304B (or in matrix) 1216-C(26) 21
const long long  mod=1e9 + 7;
const long long  mod2=static_cast <ll>(mod) * mod;
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

struct Matrix
{
    vector<vector<ll>> mat;
    ll n_rows,n_cols;
    Matrix() {}
    Matrix( vector<vector<ll> > values): mat(values),n_rows(values.size()),
    n_cols(values[0].size()) {}

    static Matrix identity_matrix(ll n)
    {
        vector<vector<ll>> values(n,vector<ll> (n,0));
        for(ll i=0;i<n;i++)
        values[i][i]=1;
        return values;
    }
    Matrix operator*(const Matrix &other) const
    {
        ll n=n_rows,m=other.n_cols;
        vector<vector<ll>> result(n_rows,vector<ll>(n_cols,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll tmp=0;
                for(ll k=0;k<n_cols;k++)
                {
                    tmp+=mat[i][k]* 1ll *other.mat[k][j];
                    while(tmp>=mod2)
                    tmp-=mod2;
                }
                result[i][j]=tmp%mod;
            }
        }
        return move(Matrix(move(result)));
    }
    inline bool is_square() const
    {
        return n_cols==n_rows;
    }
};
Matrix pw(Matrix a,ll p)
{
    Matrix result=Matrix::identity_matrix(a.n_cols);
    while(p>0)
    {
        if(p&1)
            result=a*result;
        a=a*a;
        p>>=1;
    }
    return result;
}
ll nt[105]={0};
void solve()
{
    ll n,b,k,x;
    cin>>n>>b>>k>>x;
    re(i,n)
    {
        ll z;
        cin>>z;
        nt[z%x]++;
    }
    vector<vector<ll>> m(x,vector<ll>(x,0));
    re(i,x)
    {
        re(j,x)
        {
            ll tmp=((i-10*j)%x+x)%x;
            m[i][j]=nt[tmp];
        }
    }
    vector<vector<ll>> col(x,vector<ll>(1,0));
    col[0][0]=1;
    Matrix ans = pw(m,b) * col;
    cout<<ans.mat[k][0];
}
int main()
{
   cp();
    //sieve();
    //w(x)
    {
        solve();
    }
}