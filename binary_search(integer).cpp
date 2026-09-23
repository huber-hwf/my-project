#include<iostream>
#include<vector>
using namespace std;
void bsearch(vector<int> arr, int x){
    int l=-1, r=arr.size();
    int ret=-1;
    int mid;
    while(l+1!=r){
        mid=(l+r)/2;
        if(arr[mid]>=x) r=mid;
        else l=mid;
    }
    if(arr[r]!=x) printf("-1 -1\n");
    else{
        ret=r; l=r-1; r=arr.size();
        while(l+1!=r){
            mid=(l+r)/2;
            if(arr[mid]<=x) l=mid;
            else r=mid;
        }
        printf("%d %d\n", ret, l);
    }
}
int main(){
    int n, q;
    int x;
    vector<int> arr;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++) {scanf("%d", &x); arr.push_back(x);}
    for(int i=0; i<q; i++) {scanf("%d", &x); bsearch(arr, x);}
    return 0;
}