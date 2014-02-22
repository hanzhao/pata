#include <cstdio>
#include <cstring>
int p[15],tail = 0;
int main()
{
	int i,n,t,now,ans = 0,w = 1;
	scanf("%d",&n);
	for (now = n;now;now /= 10)
	{
		t = now % 10;
		ans += (now / 10 + 1 - (t <= 1)) * w;
		if (t == 1) ans += n % w + 1;
		w *= 10;
	}
	printf("%d\n",ans);
	return 0;
}

