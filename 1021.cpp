#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int ls[20005],tr[20005],nx[20005],dep[20005],newdep[20005],tot = 0;
bool inAns[20005];
int color[20005];
int atail = 0,Ans[20005];
void Add(int a,int b)
{
	nx[++tot] = ls[a];
	ls[a] = tot;
	tr[tot] = b;
}
queue<int> q;
int main()
{
	int i,j,n,a,b,t,cs = 0,longest = 0,longest2 = 0;
	scanf("%d",&n);
	for (i = 1;i < n;++i)
	{
		scanf("%d%d",&a,&b);
		Add(a,b); Add(b,a);
	}
	for (i = 1;i <= n;++i)
		if (!color[i])
		{
			color[i] = ++cs;
			q.push(i);
			while (!q.empty())
			{
				t = q.front(); q.pop();
				for (j = ls[t];j;j = nx[j])
					if (!color[tr[j]])
					{
						color[tr[j]] = cs;
						dep[tr[j]] = dep[t] + 1;
						longest = longest > dep[tr[j]] ? longest : dep[tr[j]];
						q.push(tr[j]);
					}
			}
		}
	if (cs > 1)
	{
		printf("Error: %d components\n", cs);
		return 0;
	}
	for (i = 1;i <= n;++i)
		if (dep[i] == longest)
		{
			if (!inAns[i])
			{
				Ans[++atail] = i;
				inAns[i] = true;
			}
			memset(newdep, -1, sizeof(newdep));
			q.push(i);
			newdep[i] = 0;
			while (!q.empty())
			{
				t = q.front(); q.pop();
				for (j = ls[t];j;j = nx[j])
					if (newdep[tr[j]] == -1)
					{
						newdep[tr[j]] = newdep[t] + 1;
						longest2 = longest2 > newdep[tr[j]] ? longest2 : newdep[tr[j]];
						q.push(tr[j]);
					}
			}
			for (j = 1;j <= n;++j)
				if (newdep[j] == longest2 && !inAns[j])
				{
					Ans[++atail] = j;
					inAns[j] = true;
				}
		}
	sort(Ans + 1,Ans + atail + 1);
	for (i = 1;i <= atail;++i)
		printf("%d\n",Ans[i]);
	return 0;
}

