#include<bits/stdc++.h> 
using namespace std; 
FILE *fi = freopen("HEAP_A_MINSUM.INP","r",stdin);
FILE *fo = freopen("HEAP_A_MINSUM.OUT","w",stdout);
int a,n;
long long sum;
priority_queue<int, vector<int>, greater<int> > pq; 
//-----------------------------------------
void nhap()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        pq.push(x);
    }
}
//------------------------------------------
// Function to return the minimized sum 
int getMinSum() 
{     
    
    while (pq.size() > 1)  
    {  
        
        int min = pq.top();   
        pq.pop(); 
  
        
        int secondMin = pq.top();           
        pq.pop(); 
  
        sum += (min + secondMin);  
        
        pq.push(min + secondMin); 
    }  

    return sum; 
} 
//---------------------------------
int main() 
{   
    nhap();
    cout << getMinSum(); 
    return 0;
} 