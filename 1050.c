#include <stdio.h>
int r[305];
char a[10005],b[10005];
int main()
{
	int i;
	gets(a);
	gets(b);
	for (i = 0;b[i];++i)
		r[b[i]] = 1;
	for (i = 0;a[i];++i)
		if (!r[a[i]])
			putchar(a[i]);
	putchar('\n');
	return 0;
}

