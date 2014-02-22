#include <cstdio>
#include <algorithm>
using std::sort;
int goal,w[105],ls[105],tr[105],nx[105],path[105],now = 0,tot = 0;
bool cmp(int A,int B) { return w[A] < w[B]; }
void add(int s,int t)
{
	nx[++tot] = ls[s];
	ls[s] = tot;
	tr[tot] = t;
}
void dfs(int r,int total)
{
	if (total > goal) return;
	path[now++] = w[r];
	if (total == goal) {
		if (ls[r] == 0)
			for (int i = 0;i < now;++i)
				printf(i == now - 1 ? "%d\n" : "%d ", path[i]);
	}
	else {
		for (int i = ls[r];i;i = nx[i])
			dfs(tr[i],total + w[tr[i]]);
	}
	--now;
	return;
}
int main()
{
	int i,j,n,m,r,k,t,last;
	scanf("%d%d%d",&n,&m,&goal);
	for (i = 0;i < n;++i) scanf("%d",&w[i]);
	for (i = 0;i < m;++i) {
		scanf("%d%d",&r,&k);
		last = tot + 1;
		for (j = 0;j < k;++j) {
			scanf("%d",&t);
			add(r,t);
		}
		sort(tr + last,tr + tot + 1,cmp);
	}
	dfs(0,w[0]);
	return 0;
}

