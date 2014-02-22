#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
class Student
{
public:
	char id[10];
	int virtue,talent,total;
	void puts() { printf("%s %d %d\n",id,virtue,talent); }
};
bool operator <(Student A,Student B)
{
	if (A.total != B.total)
		return A.total > B.total;
	if (A.virtue != B.virtue)
		return A.virtue > B.virtue;
	return strcmp(A.id,B.id) < 0;
}
int tot[4];
Student rank[4][100005];
int main()
{
	Student now;
	int i,j,n,l,h,ans = 0;
	scanf("%d%d%d",&n,&l,&h);
	for (i = 0;i < n;++i) {
		scanf("\n%s %d %d",now.id,&now.virtue,&now.talent);
		if (now.virtue < l || now.talent < l)
			continue;
		++ans;
		now.total = now.virtue + now.talent;
		if (now.virtue >= h && now.talent >= h)
			rank[0][tot[0]++] = now;
		else if (now.virtue >= h)
			rank[1][tot[1]++] = now;
		else if (now.virtue >= now.talent)
			rank[2][tot[2]++] = now;
		else
			rank[3][tot[3]++] = now;
	}
	printf("%d\n",ans);
	for (i = 0;i < 4;++i) {
		sort(rank[i],rank[i] + tot[i]);
		for (j = 0;j < tot[i];++j)
			rank[i][j].puts();
	}
	return 0;
}

