#include <cstdio>
#include <algorithm>
using namespace std;
class Node
{
public:
	int Addr,Key;
};
bool operator <(Node A,Node B)
{
	return A.Key < B.Key;
}
Node all[100005];
int nx[100005],key[100005];
int main()
{
	int i,n,head,a,b,c,tot = 0;
	scanf("%d%d",&n,&head);
	for (i = 0;i < n;++i) {
		scanf("%d%d%d",&a,&b,&c);
		nx[a] = c; key[a] = b;
	}
	for (;head != -1;head = nx[head]) {
		all[tot].Addr = head;
		all[tot].Key = key[head];
		++tot;
	}
	sort(all,all + tot);
	if (tot == 0)
		puts("0 -1");
	else
		printf("%d %05d\n",tot,all[0].Addr);
	for (i = 0;i < tot;++i)
		if (i != tot - 1)
			printf("%05d %d %05d\n",all[i].Addr,all[i].Key,all[i + 1].Addr);
		else
			printf("%05d %d -1\n",all[i].Addr,all[i].Key);
	return 0;
}

