#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> v;
char in[1100005];
int main()
{
	string ans;
	vector<string>::iterator it;
	int i,now,h = -1,times = 0;
	gets(in);
	for (i = 0;;++i) {
		if (isalpha(in[i]) || isdigit(in[i])) {
			if (h == -1) h = i;
			in[i] = tolower(in[i]);
		}
		else if (h != -1) {
			v.push_back(string(in + h,i - h));
			h = -1;
		}
		if (in[i] == 0) break;
	}
	sort(v.begin(),v.end());
	for (it = v.begin();it != v.end();++it) {
		if (it == v.begin() || *it != *(it -1))
			now = 1;
		else
			++now;
		if (times < now || times == now && ans > *it) {
			times = now;
			ans = *it;
		}
	}
	cout << ans << ' ' << times << endl;
	return 0;
}

