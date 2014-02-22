#include <stdio.h>
int s[1005];
int main()
{
	int i,m,n,c,t,num,now,flag;
	scanf("%d%d%d",&m,&n,&c);
	while (c--) {
		t = num = 0;
		flag = 1;
		for (i = 0;i < n;++i) {
			scanf("%d",&now);
			while (flag && s[t] != now && t < m)
				s[++t] = ++num;
			if (s[t] != now)
				flag = 0;
			else
				--t;
		}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

