#include<bits/stdc++.h>
using namespace std;
FILE *fi = freopen("BBINTREE.INP","r",stdin);
FILE *fo = freopen("BBINTREE.OUT","w",stdout);
const int mx=500001;
int tree[4*mx];
int arr[mx];
void construct_segment_tree(int root_index,int b,int e)
{
    if(b==e)
    {
        tree[root_index]=(arr[b]);
        return ;
    }
    int left=root_index*2;
    int right=(root_index*2)+1;
    int mid=(b+e)/2;
    construct_segment_tree(left,b,mid);
    construct_segment_tree(right,mid+1,e);
    tree[root_index]=(tree[left]+tree[right]);
}
 
int query_sum(int root_index,int b,int e,int i,int j)
{
    if(i>e||j<b)
    {
        return 0;
    }
    if(i<=b&&e<=j)
    {
        return tree[root_index];
    }
    int left=2*root_index;
    int right=(2*root_index+1);
    int mid=(b+e)/2;
    int l1=query_sum(left,b,mid,i,j);
    int r1=query_sum(right,mid+1,e,i,j);
    return (l1+r1);
}
 
void update(int root_index,int b,int e,int i)
{
     if(i>e||i<b)
    {
        return;
    }
    if(i==b&&i==e)
    {
        tree[root_index]=(arr[i]);
        return;
    }
    int left=(2*root_index);
    int right=(2*root_index)+1;
    int mid=(b+e)/2;
    update(left,b,mid,i);
    update(right,mid+1,e,i);
    tree[root_index]=(tree[left]+tree[right]);
}
 
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        arr[i]=0;
    }
   construct_segment_tree(1,1,n);
   int l,r;
   int c;
 
   while(q--){
   scanf("%d",&c);
   if(c==1||c==2) {
        scanf("%d",&l);
        if(c==1) arr[l]=arr[l]+1;
        else {
                if(arr[l]) arr[l] =arr[l]-1;
            }
        update(1,1,n,l);
   }
   else {
        scanf("%d %d",&l,&r);
   printf("%d\n",query_sum(1,1,n,l,r));}
   }
return 0;
}