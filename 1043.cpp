#include <cstdio>
#include <cstring>
int a[1005],l[1005],r[1005];
int solve(int left,int right)
{
	if (left > right) return -1;
	if (left == right) return left;
	int i,split,mid = a[left];
	for (i = left + 1;i <= right;++i)
		if (a[i] >= mid)
		{
			split = i;
			break;
		}
	if (i <= right) {
		for (i = split;i <= right;++i)
			if (a[i] < mid)
				return -2;
		l[left] = solve(left + 1,split - 1);
		r[left] = solve(split, right);
		if (l[left] == -2 || r[left] == -2)
			return -2;
	}
	else {
		l[left] = solve(left + 1,right);
		if (l[left] == -2)
			return -2;
	}
	return left;
}
int solve2(int left,int right)
{
	if (left > right) return -1;
	if (left == right) return left;
	int i,split,mid = a[left];
	for (i = left + 1;i <= right;++i)
		if (a[i] < mid)
		{
			split = i;
			break;
		}
	if (i <= right) {
		for (i = split;i <= right;++i)
			if (a[i] >= mid)
				return -2;
		l[left] = solve2(left + 1,split - 1);
		r[left] = solve2(split, right);
		if (l[left] == -2 || r[left] == -2)
			return -2;
	}
	else {
		l[left] = solve2(left + 1,right);
		if (l[left] == -2)
			return -2;
	}
	return left;
}
void op(int root)
{
	if (l[root] != -1) op(l[root]);
	if (r[root] != -1) op(r[root]);
	printf(root == 0 ? "%d\n" : "%d ",a[root]);
}
int main()
{
	int i,n,root;
	scanf("%d",&n);
	for (i = 0;i < n;++i)
		scanf("%d",&a[i]);
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	root = solve(0,n - 1);
	if (root == -2) {
		memset(l,-1,sizeof(l));
		memset(r,-1,sizeof(r));
		root = solve2(0,n - 1);
	}
	if (root != -2) {
		puts("YES");
		op(root);
	}
	else
		puts("NO");
	return 0;
}

