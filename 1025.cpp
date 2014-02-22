#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,int> lrank;
class Testee
{
public:
	string id;
	int local, score;
	Testee() {}
	Testee(string i,int l,int s)
	{ id = i; local = l; score = s; }
};
bool operator <(Testee A, Testee B)
{
	if (A.score == B.score)
		return A.id < B.id;
	return B.score < A.score;
}
Testee local[105][305], all[30005];
int lsum[105];
int main()
{
	cin.sync_with_stdio(0);
	string stuid,lastid = "0";
	int i,j,n,m,score,tot = 0,lasts = -1000,lastrk = -1,t;
	cin >> n;
	for (i = 1;i <= n;++i)
	{
		cin >> lsum[i];
		for (j = 1;j <= lsum[i];++j)
		{
			cin >> stuid >> score;
			local[i][j] = Testee(stuid,i,score);
			all[++tot] = Testee(stuid,i,score);
		}
		sort(local[i] + 1,local[i] + lsum[i] + 1);
		for (j = 1;j <= lsum[i];++j)
		{
			if (local[i][j].score == lasts)
				lrank[local[i][j].id] = lrank[lastid];
			else
				lrank[local[i][j].id] = j;
			lasts = local[i][j].score;
			lastid = local[i][j].id;
		}
	}
	sort(all + 1, all + tot + 1);
	cout << tot << endl;
	lasts = -1000;
	for (i = 1;i <= tot;++i)
	{
		cout << all[i].id << " ";
		cout << (t = (all[i].score == lasts ? lastrk : i)) << " ";
		cout << all[i].local << " ";
		cout << lrank[all[i].id] << endl;
		lasts = all[i].score; lastrk = t;
	}
	return 0;
}

