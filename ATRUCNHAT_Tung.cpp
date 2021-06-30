#include <bits/stdc++.h>
using namespace std;
long long a[1000],n,res;
long long gcd(long long x,long long y)
{
    if(x%y==0)
        return y;
    return gcd(y,x%y);
}
int main()
{
    freopen("ATRUCNHAT.inp","r",stdin);
    freopen("ATRUCNHAT.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    res=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        res=res*a[i]/gcd(res,a[i]);
    }
    cout<<res<<"\n";
    for(int i=1;i<=n;i++)
        cout<<res/a[i]<<" ";

}
