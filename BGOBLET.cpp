#include <bits/stdc++.h>
using namespace std;
queue<int> q[10];
deque<int> p;
int n;
int main()
{
    freopen("BGOBLET.inp","r",stdin);
    freopen("BGOBLET.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        char x;
        cin>>x;
        if(x=='E')
        {
            int a,b;
            cin>>a>>b;
            if(q[a].empty())
                p.push_back(a);
            q[a].push(b);
        }
        else
        {
            cout<<p.front()<<" "<<q[p.front()].front()<<"\n";
            q[p.front()].pop();
            if(q[p.front()].empty())
                p.pop_front();
        }
    }
}
