#include<iostream>
#include<vector>
using namespace std;
vector<int> pre;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre.push_back(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        pre.push_back(pre[i-1]+x);
    }
    while(m--){
        int l, r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
    }
    return 0;
}