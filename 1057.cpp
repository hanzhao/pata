#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#define ROOT 0
int Intree = 0,PopValue = 0;
int Stack[100005],Tail = 0;
unsigned Key[100005];
int Left[100005],Right[100005],Value[100005],Size[100005],Root = 0,Total = 0;
void Lrotate(int &r)
{
	int t = Right[r];
	Right[r] = Left[t];
	Left[t] = r;
	Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
	Size[t] = Size[Left[t]] + Size[Right[t]] + 1;
	r = t;
}
void Rrotate(int &r)
{
	int t = Left[r];
	Left[r] = Right[t];
	Right[t] = r;
	Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
	Size[t] = Size[Left[t]] + Size[Right[t]] + 1;
	r = t;
}
int Insert(int &r,int v)
{
	if (!r)
	{
		++Intree;
		r = ++Total;
		Size[r] = 1;
		Value[r] = v;
		return Key[r] = rand();
	}
	if (v < Value[r])
	{
		if (Insert(Left[r],v) < Key[r])
			Rrotate(r);
		Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
	}
	else
	{
		if (Insert(Right[r],v) < Key[r])
			Lrotate(r);
		Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
	}
	return Key[r];
}
void Delete(int &r,int v)
{
	if (!Left[r] && !Right[r])
	{
		--Intree;
		r = Left[r] = Right[r] = Value[r] = Key[r] = Size[r] = 0;
		return;
	}
	if (v < Value[r])
	{
		Delete(Left[r],v);
		Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
		return;
	}
	if (v > Value[r])
	{
		Delete(Right[r],v);
		Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
		return;
	}
	if (Key[Left[r]] > Key[Right[r]])
	{
		Lrotate(r);
		Delete(Left[r],v);
		Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
		return;
	}
	else
	{
		Rrotate(r);
		Delete(Right[r],v);
		Size[r] = Size[Left[r]] + Size[Right[r]] + 1;
		return;
	}
}
int Peek(int r,int k)
{
	while (1)
	{
		if (k == Size[Left[r]] + 1)
			return Value[r];
		if (k <= Size[Left[r]])
			r = Left[r];
		else
		{
			k -= Size[Left[r]] + 1;
			r = Right[r];
		}
	}
}
int main()
{
	srand(time(0));
	Key[0] = 0xFFFFFFFF;
	char op[20];
	int i,n,t;
	scanf("%d",&n);
	for (i = 0;i < n;++i)
	{
		scanf("\n%s",op);
		if (op[1] == 'o')
		{
			if (Intree > 0)
			{
				Delete(Root,Stack[--Tail]);
				printf("%d\n",Stack[Tail]);
			}
			else puts ("Invalid");
		}
		else if (op[1] == 'e')
		{
			if (Intree > 0)
				printf("%d\n",Peek(Root,(Intree + 1) / 2));
			else puts ("Invalid");
		}
		else if (op[1] == 'u')
		{
			scanf("%d",&t);
			Insert(Root,Stack[Tail++] = t);
		}
	}
	return 0;
}

