#include <cstdio>
#include <cstring>
int a[100005];
inline int min(int a,int b) { return a < b ? a : b; }
int main()
{
	bool solve = false;
	int i,n,m,h = 1,t = 1,sum = 0,minm = 0x7FFFFFFF;
	scanf("%d%d",&n,&m);
	for (i = 1;i <= n;++i)
		scanf("%d",&a[i]);
loop:
	for (;t <= n;++t) {
		sum += a[t];
		if (sum > m) 
			for (;sum > m && h <= t;++h) {
				minm = min(minm,sum);
				sum -= a[h];
			}
		if (sum == m) {
			printf("%d-%d\n",h,t);
			solve = true;
		}
	}
	if (solve) return 0;
	m = minm;
	sum = 0;
	h = t = 1;
	goto loop;
	return 0;
}

