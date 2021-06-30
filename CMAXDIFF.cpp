#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],k,x,y,d,b[maxn],res=INT_MAX;
deque<int>s;
void xl()
{
    n--;
    For(i,1,n) b[i]=a[i+1]-a[i];
   // For(i,1,n) cout<<b[i]<<" ";cout<<'\n';
    k=n-k;
    For(i,1,n)
    {
        while(!s.empty()&&s.front()<i-k+1) s.pop_front();
        while(!s.empty()&&b[s.back()]<b[i]) s.pop_back();
        s.push_back(i);
        if(i>=k)
        {
            res=min(res,b[s.front()]);
            //cout<<b[s.front()]<<" ";
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
   	freopen("CMaxDiff.inp","r",stdin);
   	freopen("CMaxDiff.out","w",stdout);
    cin>>n>>k;
    For(i,1,n) cin>>a[i];
    xl();
}
