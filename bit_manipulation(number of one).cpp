#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x;
        int res=0;
        scanf("%d", &x);
        while(x>0){
            if(x%2==1)
            res++;
            x>>=1;//要用>>=， x值不变会死循环
        }
        printf("%d ", res);
    }
    printf("\n");
    return 0;
}