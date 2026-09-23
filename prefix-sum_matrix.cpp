#include<iostream>
using namespace std;
const int N=1010;
int pre[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+x;
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]<<"\n";
    }
    return 0;
}