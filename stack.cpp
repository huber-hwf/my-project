#include<iostream>
using namespace std;
const int N=100010;
int stk[N];
int tt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int M;
    while(cin>>M){
    while(M--){
        string op;
        cin>>op;
        if(op=="push"){
            cin>>stk[tt++];
        }
        if(op=="pop"){
            tt--;
        }
        if(op=="empty"){
            string res=tt==0?"YES":"NO";
            cout<<res<<"\n";
        }
        if(op=="query"){
            cout<<stk[tt-1]<<"\n";//栈顶是tt-1
        }
    }
    }
    return 0;
}