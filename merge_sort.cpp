#include <iostream>
void merge_sort (long long q[], int l, int r) {
    if (l>=r) return;
    int mid = (r + l) >> 1;
    int i = l, j = mid + 1;
    merge_sort (q, l, mid); merge_sort (q, mid+1, r);
    int k = 0; long long temp[r+1];
    while (i<=mid && j <=r) {
        if (q[i]<=q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    }
    while (i<=mid) temp[k++] = q[i++];
    while (j<=r) temp[k++] = q[j++];
    for (int i=l, j=0; i<=r; i++, j++) q[i] = temp[j];
}
int main () {
    int n;
    long long q[100000];
    while (scanf("%d", &n)!=EOF) {
        for (int i=0; i<n; i++) scanf ("%lld", &q[i]);
        merge_sort (q, 0, n-1);
        for (int i=0; i<n; i++) printf ("%lld ", q[i]);
    }
    return 0;
}