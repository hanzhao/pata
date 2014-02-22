#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
int Left[25],Right[25],Value[25],Dep[25],Total = 0,Root = 0;
void Lrotate(int &r)
{
//	puts("L Rotate!!!");
	int t = Right[r];
	Right[r] = Left[t];
	Left[t] = r;
	Dep[r] = max(Dep[Left[r]],Dep[Right[r]]) + 1;
	Dep[t] = max(Dep[Left[t]],Dep[Right[t]]) + 1;
	r = t;
}
void Rrotate(int &r)
{
//	puts("R Rotate!!!");
	int t = Left[r];
	Left[r] = Right[t];
	Right[t] = r;
	Dep[r] = max(Dep[Left[r]],Dep[Right[r]]) + 1;
	Dep[t] = max(Dep[Left[t]],Dep[Right[t]]) + 1;
	r = t;
}
void Insert(int &r,int v)
{
	if (!r)
	{
		Value[r = ++Total] = v;
		Dep[r] = 1;
		return;
	}
	if (v < Value[r])
	{
		Insert(Left[r],v);
		Dep[r] = max(Dep[Left[r]],Dep[Right[r]]) + 1;
		if (Dep[Left[r]] > Dep[Right[r]] + 1)
		{
//			printf("%d %d %d\n",r,Dep[Left[r]],Dep[Right[r]]);
			if (v < Value[Left[r]])
				Rrotate(r);
			else
			{
				Lrotate(Left[r]);
				Rrotate(r);
			}
		}
	}
	else
	{
		Insert(Right[r],v);
		Dep[r] = max(Dep[Left[r]],Dep[Right[r]]) + 1;
		if (Dep[Right[r]] > Dep[Left[r]] + 1)
		{
//			printf("~%d %d\n",Dep[Left[r]],Dep[Right[r]]);
			if (v > Value[Right[r]])
				Lrotate(r);
			else
			{
				Rrotate(Right[r]);
				Lrotate(r);
			}
		}
	}
	return;
}
int main()
{
	int i,n,now;
	scanf("%d",&n);
	for (i = 0;i < n;++i)
	{
		scanf("%d",&now);
		Insert(Root,now);
//		for (int j = 1;j <= Total;++j)
//			printf("%d %d %d Val:%d Dep:%d\n",j,Left[j],Right[j],Value[j],Dep[j]);
	}
	printf("%d\n",Value[Root]);
	return 0;
}

