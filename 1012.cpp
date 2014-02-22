#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string id[2005];
string op[4] = { "A", "C", "M", "E" };
int s[2005][4];
int main()
{
	int i, j, n, m;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		cin >> id[i] >> s[i][1] >> s[i][2] >> s[i][3];
		s[i][0] = s[i][1] + s[i][2] + s[i][3];
	}
	for (j = 0; j < m; ++j) {
		string now;
		cin >> now;
		int score[4];
		bool flag = false;
		for (i = 0; i < n; ++i)
			if (id[i] == now)
			{
				memcpy(score, s[i], sizeof(s[i]));
				flag = true;
				break;
			}
		if (!flag)
		{
			cout << "N/A" << endl;
			continue;
		}
		int rank[4] = { 1, 1, 1, 1 };
		for (i = 0; i < n; ++i)
			for (int k = 0; k < 4; ++k)
				if (s[i][k] > score[k])
					++rank[k];
		int res = 2005;
		string sel = "";
		for (int k = 0; k < 4; ++k)
			if (res > rank[k])
			{
				res = rank[k];
				sel = op[k];
			}
		cout << res << " " << sel << endl;
	}
	return 0;
}

