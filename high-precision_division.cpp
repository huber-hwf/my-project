#include<iostream>
#include<string>
using namespace std;
const int N=100010;
int A[N];
void mydiv(int A[], int B, int &Asize, int &r){
    int t=0;
    for(int i=Asize-1; i>=0; i--){
        t=r*10+A[i];
        A[i]=t/B;
        r=t%B;
    }
    while(Asize>1&&!A[Asize-1]) Asize--;
}
int main(){
    string a;
    int B;
    while(cin>>a>>B){
        int Asize=a.size();
        for(int i=Asize-1, j=0; i>=0; i--) A[j++]=a[i]-'0';
        int r=0;
        mydiv(A, B, Asize, r);
        for(int i=Asize-1; i>=0; i--) cout<<A[i];
        cout<<"\n"<<r<<"\n";
    }
    return 0;
}