#include<iostream>
using namespace std;
const int N=100010;
int e[N], pre[N], ne[N];
int idx, head, tail;
void init(){
    e[0]=0;
    e[1]=0;
    idx=2;
    head=0;
    tail=1;
    ne[head]=tail;
    pre[tail]=head;
}
void add(int k, int x){
    e[idx]=x;
    ne[idx]=ne[k];
    pre[ne[k]]=idx;
    pre[idx]=k;
    ne[k]=idx++;
}
void del(int k){
    ne[pre[k]]=ne[k];
    pre[ne[k]]=pre[k];//维护反向指针
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int M;
    while(cin>>M){
        init();
        string op;//char 在c里面一次只能读取一个字符， c++里一次只能读取一个非空白字符
        int k;
        int x;
        while(M--){
            cin>>op;
            if(op=="L"){
                cin>>x;
                add(0, x);
            }
            if(op=="R"){
                cin>>x;
                add(pre[1], x);
            }
            if(op=="D"){
                cin>>k;
                del(k+1);
            }
            if(op=="IL"){
                cin>>k>>x;
                add(pre[k+1], x);
            }
            if(op=="IR"){
                cin>>k>>x;
                add(k+1, x);
            }
        }
        for(int i=ne[head]; i!=1; i=ne[i]) cout<<e[i]<<" ";
    }
    return 0;
}