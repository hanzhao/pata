#define SPLITINT 10000000
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
long long map[505][505],dis[505];
int pre[505],ans[505],at = 0;
bool in[505];
int main()
{
	memset(pre,-1,sizeof(pre));
	memset(dis,60,sizeof(dis));
	memset(map,60,sizeof(map));
	int i,j,n,m,s,t,l,sel,a,b,cost,di;
	long long max;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (i = 0;i < m;++i) {
		scanf("%d%d%d%d",&a,&b,&di,&cost);
		map[a][b] = map[b][a] = min(map[a][b],(long long)di * SPLITINT + cost);
	}
	dis[s] = 0;
	in[s] = true;
	l = s;
	while (true) {
		max = (long long)1 << 60;
		sel = -1;
		for (i = 0;i < n;++i)
			if (!in[i]) {
				if(dis[i] > dis[l] + map[l][i]) {
					dis[i] = dis[l] + map[l][i];
					pre[i] = l;
				}
				if (max > dis[i]) {
					max = dis[i];
					sel = i;
				}
			}
		if (sel == -1)
			break;
		in[sel] = true;
		l = sel;
	}
	for (ans[++at] = t;pre[ans[at]] != -1;++at)
		ans[at + 1] = pre[ans[at]];
	for (i = at;i > 0;--i) printf("%d ",ans[i]);
	printf("%lld %lld\n",dis[t] / SPLITINT,dis[t] % SPLITINT);
	return 0;
}

