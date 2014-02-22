#include <cstdio>
int nx[100005],l1[100005],l2[100005];
char data[100005];
int main()
{
	int i,now,s1,s2,n,a,b,l1s = 0,l2s = 0;
	char c;
	scanf("%d%d%d",&s1,&s2,&n);
	for (i = 1;i <= n;++i) {
		scanf("%d %c %d",&a,&c,&b);
		data[a] = c;
		nx[a] = b;
	}
	for (now = s1;now != -1;now = nx[now])
		l1[++l1s] = now;
	for (now = s2;now != -1;now = nx[now])
		l2[++l2s] = now;
	int ans = -1;
	for (;l1s > 0 && l2s > 0;--l1s,--l2s)
		if (l1[l1s] == l2[l2s])
			ans = l1[l1s];
		else
			break;
	if (ans != -1)
		printf("%05d\n",ans);
	else
		printf("-1\n");
	return 0;
}

