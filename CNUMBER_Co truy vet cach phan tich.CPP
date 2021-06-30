#include <bits/stdc++.h>
using namespace std;
int n,i,j,j1,k,ans,trace;
static int b[101][101],f[101][101];

int LCM(int a,int b)
{
    int m=a, n=b;
    while (n!=0)
    {
        int r=m%n;
        m=n;
        n=r;
    }
    return (long long) a*b/m;
}
void Tracing(int i,int j)
{
    if (i==0||j==0) return;
    Tracing(i-b[i][j],j-1);
    cout<<b[i][j]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CNUMBER.INP","r",stdin);
    freopen("CNUMBER.OUT","w",stdout);
    cin>>n;
    for (i=1;i<=n;++i) f[i][1]=i, b[i][1]=i;
    for (i=1;i<=n;++i)
        for (j=2;j<=n;++j)
            for (k=1,j1=j-1;k<i;++k)
            {
                int &x=f[i][j];
                int t=LCM(f[i-k][j1],k);
                if (x<t)
                {
                    x=t;
                    b[i][j]=k;
                }
            }
    ans=n; trace=1;
    for (j=2;j<=n;++j)
    {
        k=f[n][j];
        if (ans<k) ans=k, trace=j;
    }
    cout<<ans<<"\n";
    Tracing(n,trace);
}
}
