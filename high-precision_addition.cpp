#include<iostream>
#include<string>
using namespace std;
const int N=100010;
int a[N], b[N];
void myplus(int a[], int b[], int &alen, int &blen){
    int temp=0, up=0;
    int i;
    for(i=0; i<alen||i<blen; i++){
        if(i<alen){
            if(i<blen)
            temp=a[i]+b[i]+up;
            else temp=a[i]+up;
        }
        else temp=b[i]+up;
        a[i]=temp%10;
        up=temp/10;
    }
    if(up){a[i]=up; i++;}
    alen=i;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string sa, sb;
    while(cin>>sa>>sb){
        int alen=sa.size(), blen=sb.size();
        for(int i=sa.size()-1, j=0; i>=0; i--) a[j++]=sa[i]-'0';
        for(int i=sb.size()-1, j=0; i>=0; i--) b[j++]=sb[i]-'0';
        myplus(a, b, alen, blen);
        for(int i=alen-1; i>=0; i--) cout<<a[i];
        cout<<"\n";
    }
    return 0;
}