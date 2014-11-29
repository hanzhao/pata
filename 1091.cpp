#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0, 0, 0},
          dy[] = {0, 0, -1, 1, 0, 0},
          dz[] = {0, 0, 0, 0, -1, 1};
struct Tuple {
    int x, y, z;
    Tuple(int x, int y, int z) : x(x), y(y), z(z) { }
};
bool mat[62][1289][131];
bool mark[62][1289][131];
queue<Tuple> Q;
int main() {
    int m, n, l, t, tmp, x, y, z, ans = 0;
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= n; ++k) {
                scanf("%d", &tmp);
                mat[i][j][k] = (tmp == 1);
            }
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= n; ++k)
                if (mat[i][j][k] && !mark[i][j][k]) {
                    tmp = 1;
                    mark[i][j][k] = true;
                    for (Q.push(Tuple(i, j, k)); !Q.empty(); Q.pop())
                        for (int d = 0; d < 6; ++d) {
                            x = Q.front().x + dx[d];
                            y = Q.front().y + dy[d];
                            z = Q.front().z + dz[d];
                            if (mat[x][y][z] && !mark[x][y][z]) {
                                tmp += 1;
                                mark[x][y][z] = true;
                                Q.push(Tuple(x, y, z));
                            }
                        }
                    if (tmp >= t)
                        ans += tmp;
                }
    printf("%d\n", ans);
    return 0;
}
