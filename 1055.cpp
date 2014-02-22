#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
class Rich
{
public:
	char name[10];
	int age,worth;
	void puts()
	{ printf("%s %d %d\n",name,age,worth); }
};
bool cmp1(Rich A,Rich B)
{
	if (A.age == B.age) {
		if (A.worth == B.worth)
			return strcmp(A.name,B.name) < 0;
		return A.worth > B.worth;
	}
	return A.age < B.age;
}
bool cmp2(Rich A,Rich B)
{
	if (A.worth == B.worth) {
		if (A.age == B.age)
			return strcmp(A.name,B.name) < 0;
		return A.age < B.age;
	}
	return A.worth > B.worth;
}
Rich all[100005],sel[100005];
int sum[205];
int main()
{
	int i,j,n,m,lim,amin,amax,os,tot = 0;
	scanf("%d%d",&n,&m);
	for (i = 0;i < n;++i)
		scanf("\n%s%d%d",all[i].name,&all[i].age,&all[i].worth);
	sort(all,all + n,cmp1);
	for (i = 0;i < n;++i)
		if (++sum[all[i].age] <= 100)
			sel[tot++] = all[i];
	sort(sel,sel + tot,cmp2);
	for (i = 1;i <= m;++i) {
		scanf("%d%d%d",&lim,&amin,&amax);
		printf("Case #%d:\n",i);
		os = 0;
		for (j = 0;j < tot && os < lim;++j)
			if (sel[j].age >= amin && sel[j].age <= amax) {
				sel[j].puts();
				++os;
			}
		if (os == 0)
			puts("None");
	}
	return 0;
}

