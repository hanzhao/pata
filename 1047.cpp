#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Student
{
public:
	char Name[7];
	int Csum,Course[25];
};
Student s[40005];
bool operator <(Student A,Student B)
{
	return strcmp(A.Name,B.Name) < 0;
}
vector<char*> each[2505];
int main()
{
	int i,j,n,m;
	vector<char*>::iterator it;
	scanf("%d%d",&n,&m);
	for (i = 0;i < n;++i) {
		scanf("\n%s%d",s[i].Name,&s[i].Csum);
		for (j = 0;j < s[i].Csum;++j)
			scanf("%d",&s[i].Course[j]);
	}
	sort(s,s + n);
	for (i = 0;i < n;++i)
		for (j = 0;j < s[i].Csum;++j)
			each[s[i].Course[j]].push_back(s[i].Name);
	for (i = 1;i <= m;++i)
	{
		printf("%d %d\n",i,(int)each[i].size());
		if (each[i].size() != 0)
			for (it = each[i].begin();it != each[i].end();++it)
				puts(*it);
	}
	return 0;
}

