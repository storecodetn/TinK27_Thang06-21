#include <bits/stdc++.h>
using namespace std;
int t,n,l,r,p[10000000],d[4000000];
bool chuyen(int x)
{
    int dem=0;
    while(x>0)
    {
        dem+=x%10;
        x=x/10;
    }
    if(dem%5==0)
        return true;
    return false;

}
int main()
{
    freopen("BSPRIME.inp","r",stdin);
    freopen("BSPRIME.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(long long i=2;i<=3000000;i++)
    {
        if(p[i]==0)
        {
            d[i]=d[i-1]+chuyen(i);
            for(long long j=i*i;j<=3000000;j+=i)
                p[j]=1;
        }
        else
            d[i]=d[i-1];
    }
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<d[r]-d[l-1]<<"\n";
    }
}
