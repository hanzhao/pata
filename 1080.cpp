#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Student
{
public:
	int e,i,tot,id;
	int c[10];
};
bool operator <(Student A,Student B)
{
	if (A.tot == B.tot)
		return A.e > B.e;
	return A.tot > B.tot;
}
Student all[40005];
int quota[105],admit[40005];
vector<int> s[105];
int main()
{
	memset(admit,-1,sizeof(admit));
	int i,j,n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (i = 0;i < m;++i)
		scanf("%d",&quota[i]);
	for (i = 0;i < n;++i)
	{
		scanf("%d%d",&all[i].e,&all[i].i);
		all[i].tot = all[i].e + all[i].i;
		all[i].id = i;
		for (j = 0;j < k;++j)
			scanf("%d",&all[i].c[j]);
	}
	sort(all,all + n);
	for (i = 0;i < n;++i)
		for (j = 0;j < k;++j)
			if (quota[all[i].c[j]] > 0 || (i > 0 && admit[i - 1] == all[i].c[j] && all[i].tot == all[i - 1].tot && all[i].e == all[i - 1].e))
			{
				admit[i] = all[i].c[j];
				s[all[i].c[j]].push_back(all[i].id);
				--quota[all[i].c[j]];
				break;
			}
	int now;
	for (i = 0;i < m;++i)
	{
		if (s[i].size() == 0)
		{
			puts("");
			continue;
		}
		now = 0;
		sort(s[i].begin(),s[i].end());
		for (vector<int>::iterator it = s[i].begin();it != s[i].end();++it)
			printf(++now == s[i].size() ? "%d\n" : "%d ",*it);
	}
	return 0;
}

