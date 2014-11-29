#include <bits/stdc++.h>
using namespace std;
vector<int> E[100005];
queue<int> Q;
double Dist[100005];
inline bool gt(double a, double b) {
    return a - b > 1e-7;
}
inline bool eql(double a, double b) {
    return fabs(a - b) <= 1e-7;
}
int main() {
    int n, s, cnt = 0;
    double p, r, mx = -1;
    scanf("%d%lf%lf", &n, &p, &r);
    r = 1.00 + r / 100.0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s);
        ++s;
        E[s].push_back(i);
    }
    Dist[0] = p / r;
    for (Q.push(0); !Q.empty(); Q.pop())
        for (int i = 0; i < (int)E[Q.front()].size(); ++i) {
            Dist[E[Q.front()][i]] = Dist[Q.front()] * r;
            Q.push(E[Q.front()][i]);
        }
    for (int i = 1; i <= n; ++i)
        if (gt(Dist[i], mx)) {
            mx = Dist[i];
            cnt = 1;
        } else if (eql(Dist[i], mx))
            cnt += 1;
    printf("%.2lf %d\n", mx, cnt);
    return 0;
}
