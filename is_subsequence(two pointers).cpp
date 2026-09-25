#include<iostream>
using namespace std;
const int N=100010;
int A[N], B[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<m; i++) cin>>B[i];
        int i, j;
        for(i=0, j=0; i<n&&j<m; ){
            if(A[i]==B[j]) {i++; j++;}
            else j++;
        }
        if(i==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}