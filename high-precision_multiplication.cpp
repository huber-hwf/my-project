#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> mul(vector<int> A, int b){
    vector<int> C;
    int temp=0;
    for(int i=0; i<A.size(); i++){
        temp+=A[i]*b;
        C.push_back(temp%10);
        temp/=10;
    }
    if(temp) C.push_back(temp);
    while(C.size()>1&&!C.back()) C.pop_back();
    return C;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    vector<int> A;
    int b;
    cin>>a>>b;
    for(int i=a.size()-1; i>=0; i--) A.push_back(a[i]-'0');
    auto C=mul(A, b);
    for(int i=C.size()-1; i>=0; i--) cout<<C[i];
    cout<<"\n";
    return 0;
}