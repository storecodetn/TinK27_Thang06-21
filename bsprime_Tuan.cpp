#include <bits/stdc++.h>
using namespace std;

const int nmax=3e6+1;
int t,s[nmax];
bool f[nmax];
//---------
int Count(int x)
{
    int res=0;
    while (x>0)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
//------------
void init()
{
    for (int i=2;i*i<=nmax;i++)
    {
        if (!f[i])
        {
            for (int j=i*i;j<=nmax;j+=i)
                f[j]=true;
        }
    }
    int dem=0;
    for (int i=1;i<=nmax;i++)
    {
        if (!f[i] && Count(i)%5==0) dem++;
        s[i]=dem;
    }
}
//------------
int main()
{
    freopen("bsprime.inp","r",stdin);
    freopen("bsprime.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin>>t;
    while (t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<"\n";
    }
    return 0;
}
