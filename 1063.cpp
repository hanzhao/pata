#include <cstdio>
#include <algorithm>
using std::sort;
int s[55],set[55][10005],same[55];
int main()
{
	int i,j,k,n,a,b,h1,h2,share;
	scanf("%d",&n);
	for (i = 1;i <= n;++i) {
		scanf("%d",&s[i]);
		for (j = 0;j < s[i];++j)
			scanf("%d",&set[i][j]);
		sort(set[i],set[i] + s[i]);
		for (j = 1;j < s[i];++j)
			if (set[i][j] == set[i][j - 1])
				++same[i];
	}
	scanf("%d",&k);
	for (i = 0;i < k;++i) {
		scanf("%d%d",&a,&b);
		h1 = h2 = 0;
		share = 0;
		for (;h1 < s[a];++h1) {
			if (h1 > 0 && set[a][h1] == set[a][h1 - 1])
				continue;
			for (;h2 < s[b] && set[b][h2] < set[a][h1];++h2);
			if (set[a][h1] == set[b][h2])
				++share;
		}
		printf("%.1f%%\n",(float)share / (s[a] + s[b] - same[a] - same[b] - share) * 100);
	}
	return 0;
}

