#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
bool ed[30005];
char in[30005][4];
int f[30005],s[30005],fmx[30005],fans[30005],size[30005],ans[30005],check[30005];
int calc(char p[4])
{
	return (p[0] - 'A') * 28 * 28 + (p[1] - 'A') * 28 + p[2] - 'A';
}
int find(int x)
{
	return f[x] == x ? x : (f[x] = find(f[x]));
}
int main()
{
	char ta[4],tb[4];
	int i,n,m,t,a,b,tot = 0;
	scanf("%d%d",&n,&m);
	m <<= 1;
	for (i = 0;i < 30000;++i)
		f[i] = i;
	for (i = 0;i < n;++i) {
		scanf("\n%s %s %d",ta,tb,&t);
		a = calc(ta);
		b = calc(tb);
		strcpy(in[a],ta);
		strcpy(in[b],tb);
		if (find(a) != find(b))
			f[find(a)] = find(b);
		s[a] += t; s[b] += t;
		ed[a] = ed[b] = true;
	}
	for (i = 0;i < 30000;++i)
		if (ed[i]) {
			++size[find(i)];
			check[find(i)] += s[i];
			if (s[i] > fmx[find(i)]) {
				fmx[find(i)] = s[i];
				fans[find(i)] = i;
			}
		}
	for (i = 0;i < 30000;++i)
		if (ed[i] && find(i) == i && size[i] > 2 && check[i] > m)
			ans[tot++] = fans[i];
	printf("%d\n",tot);
	sort(ans,ans + tot);
	for (i = 0;i < tot;++i)
		printf("%s %d\n",in[ans[i]],size[find(ans[i])]);
	return 0;
}

