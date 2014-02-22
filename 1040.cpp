#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1005][1005];
int main()
{
	int i,j,ans = 0;
	string s,s2;
	getline(cin,s);
	s2.assign(s.rbegin(),s.rend());
	for (i = 0;i < s.length();++i)
		for (j = 0;j < s2.length();++j)
			if (s[i] == s2[j])
			{
				if (i == 0 || j == 0)
					f[i][j] = 1;
				else
					f[i][j] = f[i - 1][j - 1] + 1;
				ans = max(f[i][j],ans);
			}
	cout << ans << endl;
	return 0;
}

