#include<bits/stdc++.h>
using namespace std;

FILE *fi=freopen("B031_TOWER.INP","r",stdin);
FILE *fo=freopen("B031_TOWER.OUT","w",stdout);

int n,a[1000001];
priority_queue<int>q1,q2;
//-------------------------------
void nhap()
{
	cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        q1.push(a[i]);
    }
}
//-------------------------------
void xuly()
{
	for(int i=1;i<=n;i++)
    {
        q2.push(a[i]);
        while(!q1.empty() && !q2.empty() && q2.top()>=q1.top())
        {
            cout<<q2.top()<<" ";
            q2.pop();
            q1.pop();
        }
        cout<<"\n";
    }
}
//--------------------------------
int main()
{     
   nhap();
   xuly();
   return 0;
}