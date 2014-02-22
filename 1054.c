#include <stdio.h>
int a[20000005];
int main()
{
	int i,m,n,now,half;
	scanf("%d%d",&m,&n);
	n *= m;
	half = (n + 1) / 2;
	for (i = 0;i < n;++i) {
		scanf("%d",&now);
		if (++a[now] >= half) {
			printf("%d\n",now);
			break;
		}
	}
	return 0;
}

