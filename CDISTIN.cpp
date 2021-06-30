#include <bits/stdc++.h>
using namespace std;
bitset<5001> sta[500000],stb[500000],rong,res;
int n,q;
void add(bitset<5001> st[] ,int id,int l,int r,int val,int pos)
{
    if(pos<l || pos>r)
        return;
    if(l==r)
    {
        st[id].set(val,1);
        return;
    }
    st[id].set(val,1);
    int mid=(l+r)/2;
    add(st,id*2,l,mid,val,pos);
    add(st,id*2+1,mid+1,r,val,pos);
}
bitset<5001> get(bitset<5001> st[] ,int id,int l,int r,int L,int R)
{
    if(L>r || R<l)
        return rong;
    if(l>=L && r<=R)
        return st[id];
    int mid=(l+r)/2;
    return (get(st,id*2,l,mid,L,R) | get(st,id*2+1,mid+1,r,L,R));
}
int main()
{
    freopen("CDISTIN.inp","r",stdin);
    freopen("CDISTIN.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        add(sta,1,1,n,x,i);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        add(stb,1,1,n,x,i);
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        res=(get(sta,1,1,n,a,b) | get(stb,1,1,n,c,d));
        cout<<res.count()<<"\n";
    }
}
