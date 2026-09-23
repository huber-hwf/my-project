#include<iostream>
#include<string>
using namespace std;
const int N=100010;
int a[N], b[N];
bool cmp(int a[], int b[], int alen, int blen){
    if(alen!=blen) return alen>blen;
    else{
        for(int i=alen-1; i>=0; i--){
            if(a[i]!=b[i]) return a[i]>b[i];
        }
    }
}
void sub(int bg[], int sm[], int &bglen, int &smlen){
    int temp=0, down=0;
    for(int i=0; i<bglen; i++){
        temp=bg[i]-down;
        if(i<smlen) temp-=sm[i];
        bg[i]=(temp+10)%10;
        down=temp<0?1:0;
    }
    while(bglen>1&&!bg[bglen-1]) bglen--;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string sa, sb;
    while(cin>>sa>>sb){
        int alen=sa.size(), blen=sb.size();
        for(int i=alen-1, j=0; i>=0; i--) a[j++]=sa[i]-'0';
        for(int i=blen-1, j=0; i>=0; i--) b[j++]=sb[i]-'0';
        if(cmp(a, b, alen, blen)){
            sub(a, b, alen, blen);
            for(int i=alen-1; i>=0; i--) cout<<a[i];
            cout<<"\n";
        }else{
            sub(b, a, blen, alen);
            cout<<'-';
            for(int i=blen-1; i>=0; i--) cout<<b[i];
            cout<<"\n";
        }
    }
    return 0;
}