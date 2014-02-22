#include <stdio.h>
int a[1000005], b[1000005];
int main()
{
	int i, n, m, t, choose, mid, t1 = 0, t2 = 0, tot = 0;
	scanf("%d",&n);
	for (i = 0;i < n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (i = 0;i < m;++i)
		scanf("%d",&b[i]);
	mid = (n + m + 1) >> 1;
	while (tot < mid)
	{
		if (t1 < n)
		{
			if (t2 < m)
			{
				if (a[t1] < b[t2])
					t = a[t1++];
				else
					t = b[t2++];
			}
			else
				t = a[t1++];
		}
		else
			t = b[t2++];
		++tot;
	}
	printf("%d\n",t);
	return 0;
}

