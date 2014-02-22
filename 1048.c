#include <stdio.h>
int exist[505];
inline int min(int a,int b) { return a < b ? a : b; }
int main()
{
	int i,n,m,t,ans = 1000;
	scanf("%d%d",&n,&m);
	for (i = 0;i < n;++i) {
		scanf("%d",&t);
		if (t < m && exist[m - t] && (t < ans || m - t < ans))
			ans = min(t,m - t);
		exist[t] = 1;
	}
	if (ans < 1000)
		printf("%d %d\n",ans,m - ans);
	else
		puts("No Solution");
	return 0;
}

