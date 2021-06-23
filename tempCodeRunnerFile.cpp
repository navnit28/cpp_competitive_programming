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