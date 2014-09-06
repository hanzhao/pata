/*
 * File: 1086.cpp
 * Author: Magica
 * Date: 2014.09.06
 ****************************************/
#include <bits/stdc++.h>
using namespace std;
int Data[10005];
char str[10005];
bool First = true;
void DFS(int s)
{
    int idx;
    if (scanf("%s", str) != EOF && strcmp(str, "Push") == 0) {
        scanf("%d", &idx);
        Data[s] = idx;
        DFS(s << 1);
        DFS(s << 1 | 1);
    }
}
void Output(int s)
{
    if (Data[s]) {
        Output(s << 1);
        Output(s << 1 | 1);
        printf(First ? "%d" : " %d", Data[s]);
        First = false;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    DFS(1);
    Output(1);
    printf("\n");
    return 0;
}
