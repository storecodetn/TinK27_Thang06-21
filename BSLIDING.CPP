#include <bits/stdc++.h>

using namespace std;
FILE *fi = freopen("B028_SLIDING.INP","r",stdin);
FILE *fo = freopen("B028_SLIDING.OUT","w",stdout);
int a[1000001],n,k;
//--------------------------------------------------
void nhap()
{
    scanf("%d%d",&n,&k);
    for(int i =1; i<=n; ++i)
        scanf("%d",&a[i]);
}
//----------------------------------------------------
//Dung deque truot cua so de tim max cua doan con lien tiep k phan tu
void printKMax()
{
    //Tao mot Deque d chua chi so phan tu cua mang. Hang doi se luu giu chi so cua
    //cac phan tu lon nhat trong moi cua so truot.
    std::deque<int> d;

    //xu ly k phan tu dau (cua so truot dau tien)
    for (int i = 1; i <= k; ++i) {
        //voi moi phan tu i, thi cac phan tu nho hon hoac bang truoc do trong d la vo
        //ich nen ta xoa chung di
        while ((!d.empty()) && a[i] >= a[d.back()])
            d.pop_back(); // Xoa phan tu cuoi
        //Them vao cuoi
        d.push_back(i);
    }
    // Xu ly truot cua so tren cac phan con lai tu a[2] to a[n]
    for (int i=k+1; i <= n; ++i) {
        //Phan tu dau dau hang doi la phan tu lon nhat cua cua so truot truoc do
        //nen ta in no ra, sau do xoa no di.
        cout << a[d.front()] << " ";
        //Xoa cac phan tu phia dau hang doi nam ngoai pham vi doan k pt moi, nghia
        //la d.front() <= i - k
        while ((!d.empty()) && d.front() <= i-k)
            d.pop_front(); // Xoa dau
        //Lai xoa cac phan tu nho hon a[i] vo ich o cuoi hang doi.
        while ((!d.empty()) && a[i] >= a[d.back()])
            d.pop_back();
        //Them i vao cuoi hang doi
        d.push_back(i);
    }
    //phan tu lon nhat cua cua so truot cuoi cung
    cout << a[d.front()];
}
   //-------------------------------------------//
int main()
{
    nhap();
    printKMax();
    return 0;
}
