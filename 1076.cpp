#include <cstdio>
#include <cstring>
int Ans[1005],Q[100005],Dep[1005],Qh,Qt,tot = 0;
int nx[1000005],ls[1000005],tr[1000005];
bool Visit[1005];
void add(int a,int b)
{
	nx[++tot] = ls[a];
	ls[a] = tot;
	tr[tot] = b;
}
int BFS(int s,int dep)
{
	memset(Visit,0,sizeof(Visit));
	memset(Dep,-1,sizeof(Dep));
	Dep[s] = 0;
	Qh = 1;Qt = 0;
	Q[++Qt] = s;
	Visit[s] = true;
	int i, Res = 0;
	for (;Qh <= Qt && Dep[Q[Qh]] <= dep;++Qh)
	{
		for (i = ls[Q[Qh]];i;i = nx[i])
			if (!Visit[tr[i]])
			{
				Dep[tr[i]] = Dep[Q[Qh]] + 1;
				Visit[tr[i]] = true;
				if (Dep[tr[i]] <= dep)
				{
					++Res;
					Q[++Qt] = tr[i];
				}
			}
	}
	return Res;
}
int main()
{
	memset(Ans,-1,sizeof(Ans));
	int i,j,n,l,sum,t,TCase,Now;
	scanf("%d%d",&n,&l);
	for (i = 1;i <= n;++i)
	{
		scanf("%d",&sum);
		for (j = 1;j <= sum;++j)
		{
			scanf("%d",&t);
			add(t,i);
		}
	}
	for (scanf("%d",&TCase);TCase;--TCase)
	{
		scanf("%d",&Now);
		if (Ans[Now] == -1)
			Ans[Now] = BFS(Now,l);
		printf("%d\n",Ans[Now]);
	}
	return 0;
}
