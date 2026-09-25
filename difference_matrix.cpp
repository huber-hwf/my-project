#include<iostream>
using namespace std;
const int N=1010;
int A[N][N];
void insert(int x1, int y1, int x2, int y2, int c){
    A[x1][y1]+=c;
    A[x1][y2+1]-=c;
    A[x2+1][y1]-=c;
    A[x2+1][y2+1]+=c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, q;
    while(cin>>n>>m>>q){//括号位置不对可能会错误处理输入从而导致段错误；
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int x;
                cin>>x;
                insert(i, j, i, j, x);
            }
        }
    while(q--){
        int x1, y1, x2, y2, c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1, y1, x2, y2, c);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            A[i][j]+=A[i-1][j]+A[i][j-1]-A[i-1][j-1];
            cout<<A[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}