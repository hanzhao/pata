/*
 * File: 1085.cpp
 * Author: Magica
 * Date: 2014.09.06
 ****************************************/
#include <bits/stdc++.h>
using namespace std;
long long A[100005];
int main()
{
    int i, n, p, tail = 1, Ans = 0;
    scanf("%d%d", &n, &p);
    for (i = 1; i <= n; ++i)
        scanf("%lld", &A[i]);
    sort(A + 1, A + n + 1);
    for (i = 1; i <= n; ++i) {
        for (; tail <= n && A[tail] <= p * A[i]; ++tail);
        --tail;
        Ans = max(Ans, tail - i + 1);
    }
    printf("%d\n", Ans);
    return 0;
}
