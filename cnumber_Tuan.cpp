#include <bits/stdc++.h>
using namespace std;

long long n,Max=INT_MIN;
vector<long long> res;
long long a[101];
//------------
long long lcm(long long a,long long b)
{
    return a*b/__gcd(a,b);
}
//-------------
void check(long long sum)
{
    if (sum<n) return;
    long long s=1;
    for (long long i=1;i<=31;i++)
        {
            if (a[i])
                s=lcm(s,i);
        }
    Max=max(Max,s);
}
//-------------
void Try(long long i,long long sum)
{
    for (int j=0;j<=1;j++)
    {
        if (sum+i*j>n) continue;
        sum+=i*j;
		a[i]=j;
        if (i==31) check(sum);
            else Try(i+1,sum);
        sum-=i*j;
	a[i]=0;
    }
}
//-------------
int main()
{
    freopen("cnumber.inp","r",stdin);
    freopen("cnumber.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    Try(1,0);
    cout<<Max<<"\n";
    return 0;
}
