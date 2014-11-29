#include <bits/stdc++.h>
using namespace std;
int n;
int arr[105], a[105], b[105];
bool check() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}
bool insertSort() {
    bool stop = false;
    memcpy(a, arr, sizeof(arr));
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j > 1; --j)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        if (stop && !check()) break;
        if (check()) stop = true;
    }
    if (stop) {
        puts("Insertion Sort");
        return true;
    } else
        return false;
}
bool mergeSort() {
    bool stop = false;
    memcpy(a, arr, sizeof(arr));
    for (int i = 1; i <= n; i <<= 1) {
        for (int j = 1; j <= n; j += 2 * i)
            sort(a + j, a + min(n + 1, j + 2 * i));
        if (stop && !check()) break;
        if (check()) stop = true;
    }
    if (stop) {
        puts("Merge Sort");
        return true;
    } else
        return false;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    if (!insertSort())
        mergeSort();
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}
