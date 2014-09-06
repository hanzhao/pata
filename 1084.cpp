/*
 * File: 1084.cpp
 * Author: Magica
 * Date: 2014.09.06
 ****************************************/
#include <bits/stdc++.h>
using namespace std;
char s[1005], t[1005];
set<char> S;
int main()
{
    int i, tail = 1;
    scanf("%s%s", s + 1, t + 1);
    for (i = 1; i <= (int)strlen(s + 1); ++i)
        if (toupper(s[i]) != toupper(t[tail])) {
            if (S.find(toupper(s[i])) == S.end()) {
                S.insert(toupper(s[i]));
                printf("%c", toupper(s[i]));
            }
        }
        else
            ++tail;
    printf("\n");
    return 0;
}
