#include<iostream>
#include<vector>
using namespace std;
double mycube(double n){
    if(n<0) {n=-n; printf("-");}
    double l=0;
    double r=n>1?n:1;
    while(r-l>=1e-8){
        double mid=(l+r)/2;
        if(mid*mid<=n/mid) l=mid;
        else r=mid;
    }
    return l;
}
int main(){
    double n;
    scanf("%lf", &n);
    printf("%.6f", mycube(n));
    return 0;
}