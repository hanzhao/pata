#include <cstdio>
#include <cstring>
int nx[100005],w[100005],all[100005],addr[100005];
void swap(int& a,int& b)
{
	int t = a;
	a = b;
	b = t;
}
int main()
{
	int s,i,l,r,n,per,ad,tot = 0;
	scanf("%d%d%d",&s,&n,&per);
	for (i = 0;i < n;++i)
	{
		scanf("%d",&ad);
		scanf("%d%d",&w[ad],&nx[ad]);
	}
	for (i = s;i != -1; i = nx[i])
	{
		all[++tot] = w[i];
		addr[tot] = i;
	}
	for (i = 1;i <= tot;i += per)
	{
		l = i;
		r = i + per - 1;
		if (r > tot)
			continue;
		while (l < r)
		{
			swap(all[l],all[r]);
			swap(addr[l],addr[r]);
			++l;
			--r;
		}
	}
	for (i = 1;i <= tot;++i)
		if (i == tot)
			printf("%05d %d -1\n",addr[i],all[i]);
		else
			printf("%05d %d %05d\n",addr[i],all[i],addr[i + 1]);
	if (tot == 0)
		printf("-1\n");
	return 0;
}
