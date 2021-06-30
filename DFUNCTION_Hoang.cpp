#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("DFUNCTION.inp", "r", stdin);
FILE *fo = freopen("DFUNCTION.out", "w", stdout);
const int M = 1e9 + 7;
long long power(long long x, long long n)
{
    if(n == 0) return 1;
    if(n % 2 == 0) return power(x*x % M, n/2)%M;
    else return (x*power(x*x % M, (n - 1)/2))%M;
}
int main()
{
    long long a, b, n, x;
    cin >> a >> b >> n >> x;
    long long res = (power(a, n)*x)%M;
    if(a > 1)
        res = (res + b*((power(a, n) - 1)%M * power(a - 1, M - 2)%M))%M;
    else
    {
        res = (res + b*(n%M))%M;
    }
    cout << res%M;
    return 0;
}
