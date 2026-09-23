#include<cstdio>
using namespace std;
const int N=100010;
int q[N], temp[N];
long long mergesort(int q[], int l, int r){
    if(l>=r) return 0;
    int mid=l+r>>1;
    int i=l, j=mid+1;
    long long num=0;
    num+=mergesort(q, l, mid); num+=mergesort(q, mid+1, r);
    int k=0;
    while(i<=mid&&j<=r){
        if(q[j]<q[i]){temp[k++]=q[j++]; num+=mid-i+1;}
        else temp[k++]=q[i++];
    }
    while(i<=mid) temp[k++]=q[i++];
    while(j<=r) temp[k++]=q[j++];
    for(i=l, j=0; i<=r; ) q[i++]=temp[j++];
    return num;
}
int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i<n; i++) scanf("%d", &q[i]);
        printf("%lld\n", mergesort(q, 0, n-1));
    }
    return 0;
}