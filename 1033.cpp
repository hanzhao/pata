#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
class Stop
{
public:
	double pos,price;
};
bool operator <(Stop A,Stop B) { return A.pos < B.pos; }
Stop s[505];
int main()
{
	int i,j,n;
	double c,d,davg;
	double nowc = 0.0,nowpos = 0.0,ans = 0.0;
	scanf("%lf%lf%lf%d",&c,&d,&davg,&n);
	for (i = 0;i < n;++i)
		scanf("%lf%lf",&s[i].price,&s[i].pos);
	s[n].pos = d;
	sort(s,s + n + 1);
	for (i = 0;i <= n;++i) {
		bool flag1 = false,flag2 = false;
		if (s[i].pos - nowpos > nowc * davg) {
			printf("The maximum travel distance = %.2lf\n",nowpos + davg * nowc);
			return 0;
		}
		if (i) nowc -= (s[i].pos - s[i - 1].pos) / davg;
		nowpos = s[i].pos;
		/* #1 Don't need to */
		for (j = i + 1;j <= n && s[j].pos - nowpos <= nowc * davg;++j)
			if (s[j].price < s[i].price) {
				flag1 = true;
				break;
			}
		if (flag1) continue;
		/* #2 Fill to Next */
		for (j = i + 1;j <= n && s[j].pos - nowpos <= c * davg;++j)
			if (s[j].price < s[i].price) {
				ans += ((s[j].pos - nowpos) / davg - nowc) * s[i].price;
				nowc = (s[j].pos - nowpos) / davg;
				flag2 = true;
				break;
			}
		if (flag2) continue;
		/* #3 Fill to Full */
		ans += (c - nowc) * s[i].price;
		nowc = c;
		
	}
	printf("%.2f\n",ans);
	return 0;
}

