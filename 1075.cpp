#include <cstdio>
#include <algorithm>
using std::sort;
using std::max;
class Student
{
public:
	bool subed[10],CE[10];
	int ID,score[10],total,perfect;
};
Student all[100005];
int p[10],Mapto[100005],rank[100005];
bool operator <(Student A,Student B)
{
	if (A.total != B.total)
		return A.total > B.total;
	if (A.perfect != B.perfect)
		return A.perfect > B.perfect;
	return A.ID < B.ID;
}
int main()
{
	int i,j,n,k,m,stu,pro,score,tot = 0;
	scanf("%d%d%d",&n,&k,&m);
	for (i = 1;i <= k;++i)
		scanf("%d",&p[i]);
	for (i = 0;i < m;++i)
	{
		scanf("%d%d%d",&stu,&pro,&score);
		if (!Mapto[stu])
			Mapto[stu] = ++tot;
		if (score == -1)
			all[Mapto[stu]].CE[pro] = true;
		else
			all[Mapto[stu]].CE[pro] = false;
		all[Mapto[stu]].ID = stu;
		all[Mapto[stu]].subed[pro] = true;
		all[Mapto[stu]].score[pro] = max(all[Mapto[stu]].score[pro],score);
	}
	for (i = 1;i <= tot;++i)
		for (j = 1;j <= k;++j)
		{
			all[i].total += all[i].score[j];
			all[i].perfect += all[i].score[j] == p[j];
		}
	int rankt = 0,lastscore = -1,lastrank = -1;
	sort(all + 1,all + tot + 1);
	for (i = 1;i <= tot;++i)
	{
		int thissub = 0, thisce = 0;
		for (j = 1;j <= k;++j)
		{
			thissub += all[i].subed[j];
			thisce += all[i].CE[j];
		}
		if (thissub == thisce)
			continue;
		++rankt;
		if (all[i].total == lastscore && i != 1)
			rank[i] = lastrank;
		else
			rank[i] = rankt;
		printf("%d %05d %d",rank[i],all[i].ID,all[i].total);
		for (j = 1;j <= k;++j)
			if (!all[i].subed[j])
				printf(" -");
			else
				printf(" %d",all[i].score[j]);
		printf("\n");
		lastscore = all[i].total;
		lastrank = rank[i];
	}
	return 0;
}
