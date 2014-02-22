#include <cstdio>
#include <cstring>
char a[85][85], in[85];
int main()
{
	memset(a,' ',sizeof(a));
	int i,j,n,m,t = -1;
	gets(in);
	n = (strlen(in) + 2) / 3;
	m = strlen(in) + 2 - 2 * n;
	for (i = 0;i < n;++i)
		a[i][0] = in[++t];
	for (--i,j = 1;j < m;++j)
		a[i][j] = in[++t];
	a[i][j] = 0;
	for (--j,--i;i > -1;--i)
	{
		a[i][j] = in[++t];
		a[i][j + 1] = 0;
	}
	for (i = 0;i < n;++i)
		puts(a[i]);
	return 0;
}

