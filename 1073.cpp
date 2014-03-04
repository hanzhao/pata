#include <cstdio>
#include <cstring>
char s[100005];
char ans[100005];
void swap(char& _a,char& _b)
{
	int t = _a; _a = _b; _b = t;
}
int main()
{
	memset(ans,'*',sizeof(ans));
	int i,p,dot = -1;
	bool below,dotnoneed = false;
	gets(s);
	if (s[0] == '-')
		below = true;
	else
		below = false;
	s[0] = '0';
	for (i = 0;i < strlen(s);++i)
		if (s[i] == 'E')
		{
			sscanf(s + i + 1,"%d",&p);
			s[i] = 0;
			break;
		}
		else if (s[i] == '.')
			dot = i;
	if (dot == -1)
	{
		dot = i;
		s[dot] = '.';
		s[dot + 1] = 0;
	}
	int BEGIN = 40000;
	strcpy(ans + BEGIN,s);
	if (p > 0)
	{
		int SWAP = BEGIN + dot;
		for (i = 0;i < p;++i)
		{
			if (ans[SWAP + 1] == 0)
			{
				ans[SWAP + 1] = '0';
				ans[SWAP + 2] = 0;
				dotnoneed = true;
			}
			swap(ans[SWAP],ans[SWAP + 1]);
			++SWAP;
		}
	}
	else if (p < 0)
	{
		p = -p;
		int SWAP = BEGIN + dot;
		for (i = 0;i < p;++i)
		{
			if (ans[SWAP - 1] == '*')
			{
				ans[SWAP - 1] = '0';
			}
			swap(ans[SWAP],ans[SWAP - 1]);
			--SWAP;
		}
	}
	if (below)
		printf("-");
	int taila = strlen(s) - 1,tailb = strlen(ans) - 1,repzero = 0,cnta = 0,cntb = 0;
	bool isbegin = false,neverdot = true;
	int beginpos = 0;
	for (beginpos = 0; ans[beginpos] == '*' && ans[beginpos + 1] != '.'; ++beginpos);
	for (; ans[beginpos] == '0' && ans[beginpos + 1] != '.'; ++beginpos);
	for (;(s[taila] == '0' || s[taila] == '.') && taila > 0;--taila)
		if (s[taila] == '0')
			++cnta;
	for (;ans[tailb] == '0' || ans[tailb] == '.' && tailb >= beginpos;--tailb)
		if (ans[tailb] == '0')
			++cntb;
	if (cnta > cntb)
		repzero = cnta - cntb;
	for (i = beginpos;ans[i];++i)
	{
		if (ans[i] == '.')
		{
			if (dotnoneed || ans[i + 1] == 0)
				continue;
			neverdot = false;
		}
		putchar(ans[i] == '*' ? '0' : ans[i]);
	}
	for (i = 0;i < repzero;++i) {
		if (i == 0 && !neverdot)
			putchar('.');
		putchar('0');
	}
	printf("\n");
	return 0;
}
