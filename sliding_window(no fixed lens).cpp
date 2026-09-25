#include<iostream>
using namespace std;
const int N=100010;
int A[N], S[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n){
        S[N]={0};
        int res=0;
        for(int i=1, j=1; i<=n; i++){
            int x;
            cin>>x;
            A[i]=x;
            S[x]++;
            while(j<i&&S[x]>1) S[A[j++]]--;
            res=max(res, i-j+1);
        }
        cout<<res<<"\n";
    }
    return 0;
}