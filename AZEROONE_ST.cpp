#include<iostream>
using namespace std;
FILE *fi = freopen("AZEROONE.INP","r",stdin);
FILE *fo = freopen("AZEROONE.OUT","w",stdout);
int tree[5000000];
void update(int node,int start,int end, int ind,int val)
{
    if(start == end)
       {
           tree[node]=val;
           return;
       }
    int mid=(start + end)/2;
    if(ind <= mid)
        update((2*node), start, mid, ind, val);
    else
        update((2*node)+1,mid+1,end,ind,val);
       
    tree[node] = tree[(node*2)] + tree[(node*2) + 1 ];
    return;
}
int find(int node, int start ,int end, int k)
{
    if(start == end)
    {
        return start;
    }
    int  mid=(start + end)/2;
    if(tree[2*node]>=k)
    {
        return find(2*node, start, mid, k);
    }
    else
    {
        return find((node*2)+1, mid+1, end, k - tree[2*node] );
    }  
}
int main()
{
   
    int n,t,a,b;
    cin>>n;
    int n1=1,n2=n;
   
    for(int i=0;i<5000000;i++)
    tree[i]=0;
    for(int i=0;i<n2;i++)
    {
        update(1,1,n,i+1,1);
    }
    cin>>t;
    while(t--)
    {
        cin >> a>> b;
        if(a==0)
        {
            update(1,1,n,b,0);
        }
        else
        {
            if(b>tree[1])
            cout << "-1\n";
            else
            cout<<find(1,1,n,b)<<"\n";
        }
    }
    return 0;
   
}