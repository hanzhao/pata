#include <cstdio>
#include <cstring>
void swap(char &a,char &b)
{
	char t = a; a = b; b = t;
}
int n;
class Translator
{
public:
	char s[205];
	bool zeroflag;
	int p;
	void work()
	{
		zeroflag = false;
		bool meet = false;
		int i,fir = -1,dot = -1;
		for (i = 0;s[i];++i)
			if (s[i] == '.')
			{ dot = i; break; }
		if (dot == -1) { s[i] = '.'; s[i + 1] = 0; dot = i; }
		for (i = 0;s[i];++i)
			if (s[i] != '.' && s[i] != '0')
			{ fir = i; break; }
		if (fir == -1) { zeroflag = true; return; }
		if (dot > fir)
		{
			p = dot - fir;
			for (i = dot;i > fir;--i)
				swap(s[i],s[i - 1]);
		}
		else
		{
			p = dot + 1 - fir;
			for (i = dot;i < fir - 1;++i)
				swap(s[i],s[i + 1]);
		}
		return;
	}
	void op()
	{
		printf("0");
		if (zeroflag) { printf("."); for (int i = 0;i < n;++i) printf("0"); printf("*10^0"); return;}
		int i,t;
		bool ole = false;
		for (i = 0;s[i] != '.';++i);
		for (t = 0;t <= n;++t)
		{
			if (s[i] == 0)
				ole = true;
			if (ole)
				printf("0");
			else
				printf("%c",s[i]);
			++i;
		}
		printf("*10^%d",p);
		return;
	}
};
bool operator ==(Translator a,Translator b)
{
	if (a.zeroflag || b.zeroflag)
	{
		if (a.zeroflag ^ b.zeroflag) return false;
		return true;
	}
	if (a.p != b.p) return false;
	int i,j,cmp;
	for (i = 0;a.s[i] != '.';++i);
	for (j = 0;b.s[j] != '.';++j);
	for (cmp = 0;cmp < n;++cmp)
	{
		++i; ++j;
		if (a.s[i] != b.s[j]) return false;
	}
	return true;
}
int main()
{
	Translator a,b;
	scanf("%d %s %s",&n,a.s,b.s);
	a.work(); b.work();
	if (a == b)
	{
		printf("YES ");
		a.op(); printf("\n");
	}
	else
	{
		printf("NO ");
		a.op(); printf(" ");
		b.op(); printf("\n");
	}
	return 0;
}

