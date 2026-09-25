#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
vector<PII> res;
int st=-2e9, ed=-2e9;
void merge(vector<PII> &segs){
    sort(segs.begin(), segs.end());
    for(auto seg: segs){
        if(ed<seg.first){
            if(st!=-2e9) res.push_back({st, ed});
            st=seg.first, ed=seg.second;
        }
        else ed=max(ed, seg.second);
    }
    if(st!=-2e9) res.push_back({st, ed});
    segs=res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<PII> segs;
    cin>>n;
    while(n--){
        int l, r;
        cin>>l>>r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout<<segs.size()<<endl;
    return 0;
}