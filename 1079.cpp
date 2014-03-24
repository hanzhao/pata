#include <cstdio>
double p[200005];
int nx[200005],ls[200005],tr[200005],tot;
double sell[200005];
bool retailer[200005];
int q[200005],qh = 1,qt = 0;
void add(int s,int t)
{
	nx[++tot] = ls[s];
	ls[s] = tot;
	tr[tot] = t;
}
int main()
{
	int i,j,m,n,t;
	double up,ans = 0.0;
	scanf("%d%lf%lf",&n,&p[0],&up);
	up = up / 100.0 + 1.00;
	for (i = 0;i < n;++i)
	{
		scanf("%d",&m);
		for (j = 0;j < m;++j)
		{
			scanf("%d",&t);
			add(i,t);
		}
		if (m == 0)
		{
			retailer[i] = true;
			scanf("%lf",&sell[i]);
		}
	}
	for (q[++qt] = 0;qh <= qt;++qh)
	{
		if (retailer[q[qh]])
			ans += sell[q[qh]] * p[q[qh]];
		for (i = ls[q[qh]];i;i = nx[i])
		{
			p[tr[i]] = p[q[qh]] * up;
			q[++qt] = tr[i];
		}
	}
	printf("%.1lf\n",ans);
	return 0;
}

