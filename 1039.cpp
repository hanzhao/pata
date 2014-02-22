#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> stu[300005];
inline int calc(char s[])
{
	return (s[0] - 'A') * 9408 + (s[1] - 'A') * 336 + (s[2] - 'A') * 12 + s[3] - '0';
}
int main()
{
	int i,j,n,m,id,s;
	char name[10];
	vector<int>::iterator it;
	scanf("%d%d",&n,&m);
	for (i = 0;i < m;++i) {
		scanf("%d%d\n",&id,&s);
		for (j = 0;j < s;++j) {
			scanf("%s",name);
			stu[calc(name)].push_back(id);
		}
	}
	for (i = 0;i < n;++i) {
		scanf("%s",name);
		s = calc(name);
		printf("%s %d",name,(int)stu[s].size());
		if (stu[s].size() != 0) {
			sort(stu[s].begin(), stu[s].end());
			for (it = stu[s].begin();it != stu[s].end();++it)
				printf(" %d",*it);
		}
		printf("\n");
	}
	return 0;
}

