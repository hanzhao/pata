#include <stdio.h>
#include <string.h>
int ls[1005], tr[1000005], nx[1000005], s = 0;
int c[1005], ans = 0;
int q[1005], qh = 1, qt = 0;
void add(int fr, int to)
{
	nx[++s] = ls[fr];
	tr[s] = to;
	ls[fr] = s;
}
int main()
{
	int i, j, n, m, k, fr, to, x, t;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d", &fr, &to);
		add(fr, to);
		add(to, fr);
	}
	for (i = 0;i < k; ++i)
	{
		ans = 0;
		qh = 1;
		qt = 0;
		scanf("%d", &x);
		memset(c, 0, sizeof(c));
		for (j = 1; j <= n; ++j)
			if (!c[j] && j != x)
			{
				c[j] = ++ans;
				for (q[++qt] = j; qh <= qt; ++qh)
					for (t = ls[q[qh]]; t; t = nx[t])
						if (!c[tr[t]] && tr[t] != x)
						{
							c[tr[t]] = ans;
							q[++qt] = tr[t];
						}
			}
		printf("%d\n", ans - 1);
	}
	return 0;
}

