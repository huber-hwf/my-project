#include<iostream>
using namespace std;
const int N=100010;
int e[N], ne[N];
int idx, head;
void init(){
    idx=0;
    head=-1;
}
void add_to_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void remove(int k){
    ne[k]=ne[ne[k]];
}
void insert(int k, int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int M;
    while(cin>>M){
        init();
        char op;
        int x, k;
        while(M--){
            cin>>op;
            if(op=='H'){
                cin>>x;
                add_to_head(x);
            }
            if(op=='D'){
                cin>>k;
                if(k==0) head=ne[head];/*链表元素关系非线性，不能用head++，
                k==0表示删除头结点， 不能直接用remove， 不然会remove（-1）*/
                else remove(k-1);
            }
            if(op=='I'){
                cin>>k>>x;
                insert(k-1, x);
            }
        }
        for(int i=head; i!=-1; i=ne[i]) cout<<e[i]<<" ";
        cout<<endl;
    }
    return 0;
}