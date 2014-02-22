#include <stdio.h>
int f[100005],a[100005];
int find(int x)
{
	return f[x] == x ? x : (f[x] = find(f[x]));
}
int main()
{
	int i,n,noswap = 0,circle = 0;
	scanf("%d",&n);
	for (i = 0;i < n;++i) {
		scanf("%d",&a[i]);
		f[i] = i;
		if (i == a[i]) ++noswap;
	}
	for (i = 0;i < n;++i)
		if (i != a[i] && find(i) != find(a[i]))
			f[find(i)] = find(a[i]);
	for (i = 0;i < n;++i)
		if (i != a[i] && find(i) == i)
			++circle;
	printf("%d\n",n - noswap + circle - 2 * (a[0] != 0));
	return 0;
}

