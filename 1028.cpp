#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c = 0;
class Student
{
public:
	char rec[3][12];
	Student() {}
	Student(char x[],char y[],char z[])
	{ memcpy(rec[0],x,sizeof(x)); memcpy(rec[1],y,sizeof(y)); memcpy(rec[2],z,sizeof(z)); }
};
bool operator <(Student A,Student B)
{
	if (strcmp(A.rec[c],B.rec[c]) == 0)
		return strcmp(A.rec[0],B.rec[0]) < 0;
	return strcmp(A.rec[c],B.rec[c]) < 0;
}
Student all[100005];
int main()
{
	int i,n;
	char x[15], y[15], z[15];
	scanf("%d%d",&n,&c);
	c--;
	for (i = 0;i < n;++i)
	{
		scanf("\n%s %s %s",x,y,z);
		all[i] = Student(x,y,z);
	}
	sort(all,all + n);
	for (i = 0;i < n;++i)
		printf("%s %s %s\n",all[i].rec[0],all[i].rec[1],all[i].rec[2]);
	return 0;
}

