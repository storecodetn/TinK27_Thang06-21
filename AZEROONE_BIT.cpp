#include <bits/stdc++.h>
using namespace std;
int n,bit[10000001],k,q,a[1000001];
void add(int x,int val)
{
    while(x<=n)
    {
        bit[x]+=val;
        x+=x&(-x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=bit[x];
        x-=x&(-x);
    }
    return ans;
}
int query(int x)
{
    int l=1,r=n,mid,kq=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        int s=sum(mid);
        if(s==x)
            kq=mid;
        if(s<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return kq;
}
int main()
{
    freopen("AZEROONE.inp","r",stdin);
    freopen("AZEROONE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        add(i,1);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==0)
            {
                if(a[y]==0)
                    add(y,-1);
                a[y]=1;
            }
        else
            cout<<query(y)<<"\n";
    }
}
