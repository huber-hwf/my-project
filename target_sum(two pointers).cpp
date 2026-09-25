#include<iostream>
using namespace std;
const int N=100010;
int A[N], B[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    long long x;
    while(cin>>n>>m>>x){
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<m; i++) cin>>B[i];
        for(int i=0, j=m-1; i<n&&j>=0; ){
                if(A[i]+B[j]==x) {cout<<i<<" "<<j<<"\n"; break;}
                if(A[i]+B[j]<x) i++;
                if(A[i]+B[j]>x) j--;
        }
    }
    return 0;
}