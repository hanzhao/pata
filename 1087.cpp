/*
 * File: 1087.cpp
 * Author: Magica
 * Date: 2014.09.06
 ****************************************/
#include <bits/stdc++.h>
using namespace std;
map<string, int> M;
int Dist[305], Happy[305];
string Name[305];
double AdverageHappy;
int TotalHappy, Ans, Total, Depth;
bool FindAns = false;
int nx[200005], ls[200005], tr[200005], w[200005], Q[2000005], Qh = 1, Qt = 0, tot = 0;
int AnsLine[305], NowLine[305];
bool inQ[305];
void AddEdge(int s, int t, int tw)
{
    nx[++tot] = ls[s]; ls[s] = tot; tr[tot] = t; w[tot] = tw;
}
void DFS(int s, int depth, int happy)
{
    NowLine[depth] = s;
    if (Name[s] == "ROM") {
        ++Total;
        Ans = Dist[s];
        if (!FindAns || happy > TotalHappy || (happy == TotalHappy && ((double)happy / (depth - 1) > AdverageHappy))) {
            FindAns = true;
            Depth = depth;
            TotalHappy = happy;
            AdverageHappy = (double)happy / (depth - 1);
            memcpy(AnsLine, NowLine, sizeof(NowLine));
        }
        return;
    }
    for (int i = ls[s]; i; i = nx[i])
        if (Dist[tr[i]] == Dist[s] + w[i])
            DFS(tr[i], depth + 1, happy + Happy[tr[i]]);
    return;
}
int main()
{
    int i, n, m, tw;
    string s, t;
    cin >> n >> m >> s;
    M[s] = 1; Name[1] = s;
    for (i = 2; i <= n; ++i) {
        cin >> s >> Happy[i];
        M[s] = i;
        Name[i] = s;
    }
    for (i = 1; i <= m; ++i) {
        cin >> s >> t >> tw;
        AddEdge(M[s], M[t], tw);
        AddEdge(M[t], M[s], tw);
    }
    memset(Dist, 60, sizeof(Dist));
    Dist[1] = 0;
    inQ[Q[++Qt] = 1] = true;
    for (; Qh <= Qt; inQ[Q[Qh++]] = false)
        for (i = ls[Q[Qh]]; i; i = nx[i])
            if (Dist[tr[i]] > Dist[Q[Qh]] + w[i]) {
                Dist[tr[i]] = Dist[Q[Qh]] + w[i];
                if (!inQ[tr[i]])
                    inQ[Q[++Qt] = tr[i]] = true;
            }
    DFS(1, 1, 0);
    printf("%d %d %d %d\n", Total, Ans, TotalHappy, (int)AdverageHappy);
    for (i = 1; i <= Depth; ++i)
        if (i == Depth)
            cout << Name[AnsLine[i]] << endl;
        else
            cout << Name[AnsLine[i]] << "->";
    return 0;
}
