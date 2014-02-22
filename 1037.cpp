#include <cstdio>
#include <algorithm>
using std::sort;
int a[100005],b[100005];
int main()
{
	int i,n,m;
	long long ans = 0;
	scanf("%d",&n);
	for (i = 0;i < n;++i) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (i = 0;i < m;++i) scanf("%d",&b[i]);
	sort(a,a + n); sort(b,b + m);
	for (i = 0;i < n && i < m;++i)
		if (a[i] < 0 && b[i] < 0)
			ans += (long long)a[i] * b[i];
		else
			break;
	for (i = 1;i <= n && i <= m;++i)
		if (a[n - i] > 0 && b[m - i] > 0)
			ans += (long long)a[n - i] * b[m - i];
		else
			break;
	printf("%lld\n",ans);
	return 0;
}

