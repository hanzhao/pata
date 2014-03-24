#include <cstdio>
bool NoPrime[20005],ed[20005];
int Prime[20005];
int main()
{
	NoPrime[0] = NoPrime[1] = true;
	int i,j,s,n,t,Psum;
	scanf("%d%d",&s,&n);
	for (i = 2;i <= 20000;++i)
	{
		if (!NoPrime[i])
			Prime[++Psum] = i;
		for (j = 1;j <= Psum && i * Prime[j] <= 20000;++j)
		{
			NoPrime[i * Prime[j]] = true;
			if (i % Prime[j] == 0)
				break;
		}
	}
	if (NoPrime[s])
	{
		for (i = 1;i <= Psum && Prime[i] <= s;++i);
		s = Prime[i];
	}
	for (i = 1;i <= n;++i)
	{
		scanf("%d",&t);
		for (j = 0;j < s;++j)
			if (!ed[(t + j * j) % s])
			{
				ed[(t + j * j) % s] = true;
				printf("%d",(t + j * j) % s);
				break;
			}
		if (j == s)
			printf("-");
		printf(i == n ? "\n" : " ");
	}
	return 0;
}
