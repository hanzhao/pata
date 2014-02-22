#include <stdio.h>
int s[100005], f[100005];
inline int min(int a,int b) { return a < b ? a : b; }
int main()
{
	int i,n,m,a,b,t;
	scanf("%d",&n);
	for (i = 1;i <= n;++i) {
		scanf("%d",&s[i]);
		f[i + 1] = f[i] + s[i];
	}
	scanf("%d",&m);
	for (i = 1;i <= m;++i) {
		scanf("%d%d",&a,&b);
		if (a > b) { t = a;a = b;b = t; }
		printf("%d\n",min(f[b] - f[a],f[n + 1] - f[b] + f[a]));
	}
	return 0;
}

