#include <cstdio>
class Number
{
public:
	int b,b17,b29;
	Number(int x,int y,int z)
	{ b = x;b17 = y;b29 = z; }
	void Output() { printf("%d.%d.%d\n",b,b17,b29); }
	Number& operator +=(Number Other)
	{
		b29 += Other.b29; b17 += Other.b17; b += Other.b;
		if (b29 > 28) { b29 -= 29; ++b17; }
		if (b17 > 16) { b17 -= 17; ++b; }
		return *this;
	}
};
int main()
{
	int a,b,c,d,e,f;
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
	(Number(a,b,c) += Number(d,e,f)).Output();
	return 0;
}

