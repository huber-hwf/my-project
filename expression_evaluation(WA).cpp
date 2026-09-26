#include<iostream>
using namespace std;
const int N=100010;
char op[N];
int tt;
long long stk[N];
int t1;
void init(){
    op[0]='&';
    tt=1;
}
long long binary_exponentiation(int exponent, int base){
    long long res=1;
    long long pow=base;
    while(exponent>0){
        if(exponent%2==1) res*=pow;
        pow*=pow;
        exponent/=2;
    }
    return res;
}
long long convert(int tt){
    for(int i=tt-2; op[i]!='('&&op[i]!='&'; i--){
            int exponent=tt-2-i;
            x+=(op[i]-'0')*binary_exponentiation(exponent, 10);
        }
        return x;
}
void sum(long long &res){
    for(int i=1; i<t1; i++){
            res+=stk[i];
        }
        t1=1;
        
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long res=0;
    init();
    int Ispos=1;
    int Ismul=0;
    t1=1;
    while(cin>>op[tt++]){
        if(op[tt-1]=='+'||op[tt-1]=='-'){
            long long x=conver(tt);
            stk[t1++]=Ispos==1?x:-x;
            Ispos=op[tt-1]=='+'?1:2;
            Ismul=0;
            init();
        }
        if(op[tt-1]=='*'||op[tt-1]=='/'){
            long long x=convert(tt);
            if(Ismul){
                stk[t1-1]=Ismul==1?stk[t1-1]*x:stk[t1-1]/x;
            }
            else stk[t1++]=x;
        }
        if(op[tt-1]==')'){
            long long x=convert(tt);
            if(Ismul){
                stk[t1-1]=Ismul==1?stk[t1-1]*x:stk[t1-1]/x;
            }
            else stk[t1++]=Ispos==1?x:-x;
            sum(res);
        }
    }
    return 0;
}