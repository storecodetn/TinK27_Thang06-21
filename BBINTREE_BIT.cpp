#include <bits/stdc++.h>
using namespace std;
int n,q,bit[10000000],a[1000000];
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
int main()
{
    freopen("BBINTREE.inp","r",stdin);
    freopen("BBINTREE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        int x,l,r;
        cin>>x;
        if(x==1)
        {
            cin>>l;
            a[l]++;
            add(l,1);
        }
        if(x==2)
        {
            cin>>l;
            if(a[l]>0)
                {
                    add(l,-1);
                    a[l]--;
                }
        }
        if(x==3)
        {
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<"\n";
        }
    }
}
