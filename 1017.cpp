#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Person
{
public:
	int t, time;
	Person() {}
	Person(int h, int m, int s, int tt)
	{
		time = tt;
		t = h * 3600 + m * 60 + s;
	}
};
bool operator <(Person A, Person B)
{
	return A.t < B.t;
}
Person a[10005];
int win[105], etime[105], use[105], ut = -1, wait[10005], wh = 1, wt = 0;
int main()
{
	memset(win, -1, sizeof(win));
	memset(etime, -1, sizeof(etime));
	int i, n, m, hh, mm, ss, tt;
	int secs = 0, ansn = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
	{
		scanf("%d:%d:%d%d", &hh, &mm, &ss, &tt);
		a[i] = Person(hh, mm, ss, tt);
	}
	sort(a, a + n);
	for (i = 0; i < n; ++i)
	{
		if (a[i].t < 28800)
		{
			secs += 28800 - a[i].t;
			a[i].t = 28800;
		}
		if (a[i].t <= 61200)
			++ansn;
	}
	int now = 28800;
	int at = 0;
	int last = 61200;
	while (now <= last)
	{
		ut = 0;	
		for (int i = 0; i < m; ++i)
		{
			if (win[i] != -1 && etime[i] == now)
				win[i] = -1;
			if (win[i] == -1)
				use[ut++] = i;
		}
		while (at < ansn && a[at].t == now)
		{
			wait[++wt] = at;
			++at;
		}
		for (int i = 0;i < ut; ++i)
		{
			if (wh > wt)
				break;
			win[use[i]] = wait[wh];
			etime[use[i]] = a[wait[wh]].time * 60 + now;
			if (etime[use[i]] > last)
				last = etime[use[i]];
			++wh;
		}
		++now;
		secs += wt - wh + 1;
	}
	if (ansn != 0)
		printf("%.1lf\n", secs / 60.0 / ansn);
	else
		printf("0.0\n");
	return 0;
}

