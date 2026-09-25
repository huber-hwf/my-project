#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cstring>
using namespace std;
const int N=300010;
int a[N], s[N];
vector<int> alls;
typedef pair<int, int> PII;
vector<PII> add, query;
int find(int x){
    int l=-1, r=alls.size();
    while(l+1!=r){
        int mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid;
    }
    return r+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        alls.clear();
        add.clear();
        query.clear();
        for(int i=0; i<n; i++){
            int x, c;
            cin>>x>>c;
            alls.push_back(x);
            add.push_back({x, c});
        }
        for(int i=0; i<m; i++){
            int l, r;
            cin>>l>>r;
            alls.push_back(l);
            alls.push_back(r);
            query.push_back({l, r});
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        for(auto item: add){
            int x=find(item.first);
            a[x]+=item.second;
        }
        for(int i=1; i<=alls.size(); i++) s[i]=s[i-1]+a[i];
        for(auto item: query){
            int l=find(item.first);
            int r=find(item.second);
            cout<<s[r]-s[l-1]<<"\n";
        }
    }
    return 0;
}