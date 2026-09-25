#include<cstdio>
using namespace std;
const int N=100010;
int A[N], B[N];
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m)!=EOF){
        for(int i=1; i<=n; i++){
            scanf("%d", &A[i]);
            B[i]=A[i]-A[i-1];
        }
        while(m--){
            int l ,r, c;
            scanf("%d %d %d", &l, &r, &c);
            B[l]+=c, B[r+1]-=c;
        }
        for(int i=1; i<=n; i++){
            B[i]+=B[i-1];
            printf("%d ", B[i]);
        }
        printf("\n");
    }
    return 0;
}