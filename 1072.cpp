#include <cstdio>
#include <cstring>
int n,m;
int q[1000005],qh,qt;
bool inq[30005];
int ls[30005],tr[30005],nx[30005],w[30005],dis[30005],tot = 0;
void add(int s,int t,int d)
{
	nx[++tot] = ls[s];
	ls[s] = tot;
	tr[tot] = t;
	w[tot] = d;
}
int calc(char s[10])
{
	int res;
	if (s[0] == 'G') {
		sscanf(s + 1,"%d",&res);
		res += n;
	}
	else
		sscanf(s,"%d",&res);
	return res;
}
int main()
{
	char ta[10],tb[10];
	int i,k,a,b,c,d,ans = -1,anstotal = 0,choose = -1;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for (i = 0;i < k;++i) {
		scanf("\n%s %s %d",ta,tb,&c);
		a = calc(ta); b = calc(tb);
		add(a,b,c); add(b,a,c);
	}
	for (int s = n + 1;s <= n + m;++s) {
		memset(dis,60,sizeof(dis));
		memset(inq,0,sizeof(inq));
		qh = 1; qt = 0;
		dis[s] = 0;
		q[++qt] = s; inq[s] = true;
		for (;qh <= qt;++qh) {
			for (i = ls[q[qh]];i;i = nx[i])
				if (dis[tr[i]] > dis[q[qh]] + w[i]) {
					dis[tr[i]] = dis[q[qh]] + w[i];
					if (!inq[tr[i]]) {
						q[++qt] = tr[i];
						inq[tr[i]] = true;
					}
				}
			inq[q[qh]] = false;
		}
		bool flag = true;
		int mind = 1234567890,total = 0;
		for (i = 1;i <= n;++i) {
			if (dis[i] > d) {
				flag = false;
				break;
			}
			if (mind > dis[i])
				mind = dis[i];
			total += dis[i];
		}
		if (flag && (mind > ans || mind == ans && anstotal > total)) {
			ans = mind;
			choose = s - n;
			anstotal = total;
		}
	}
	if (choose == -1)
		puts("No Solution");
	else
		printf("G%d\n%.1f %.1lf\n",choose,(float)ans,(double)(anstotal + 0.005) / (double)n);
	return 0;
}

