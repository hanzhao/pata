#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
using std::min;
class Customer
{
public:
	int arh,arm,ars,p,ari;
	bool vip;
};
bool operator <(Customer A,Customer B) { return A.ari < B.ari; }
Customer all[10005];
bool viptable[105];
int serving[105],end[105],tot[105],vipid[105];
int q[10005],qh,qt,vipq[10005],vipqh,vipqt;
int main()
{
	memset(serving,-1,sizeof(serving));
	int i,n,k,m,t,now,tvip,tcus,turn = 0;
	scanf("%d",&n);
	for (i = 0;i < n;++i) {
		scanf("%d:%d:%d %d %d",&all[i].arh,&all[i].arm,&all[i].ars,&all[i].p,&tvip);
		all[i].p = min(all[i].p,120);
		all[i].vip = tvip == 1;
		all[i].ari = all[i].arh * 3600 + all[i].arm * 60 + all[i].ars;
	}
	sort(all,all + n);
	scanf("%d%d",&k,&m);
	for (i = 0;i < m;++i) {
		scanf("%d",&t);
		vipid[i] = t;
		viptable[t] = true;
	}
	now = 8 * 3600;
	qh = 1; qt = 0; vipqh = 1; vipqt = 0;
	while (true) {
		for (;all[turn].ari == now;++turn)
			if (all[turn].vip)
				vipq[++vipqt] = turn;
			else
				q[++qt] = turn;
		for (i = 1;i <= k;++i)
			if (serving[i] != -1 && end[i] == now)
				serving[i] = -1;
		for (i = 0;i < m;++i)
			if (serving[vipid[i]] == -1 && vipqt - vipqh + 1 > 0) {
				serving[vipid[i]] = vipq[vipqh++];
				if (now < 21 * 3600) {
					++tot[vipid[i]];
					Customer tt = all[serving[vipid[i]]];
					end[vipid[i]] = now + tt.p * 60;
					int a1,a2,a3,b1,b2,b3;
					a1 = tt.arh; a2 = tt.arm; a3 = tt.ars;
					b1 = now / 3600; b2 = (now - b1 * 3600) / 60; b3 = now - b1 * 3600 - b2 * 60;
					printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",a1,a2,a3,b1,b2,b3,(int)round((float)(now - tt.ari) / (float)60));
				}
				else {
					serving[vipid[i]] = -1;
					--i;
				}
			}
		for (i = 1;i <= k;++i) {
			if (serving[i] == -1) {
				if (viptable[i]) {
					if (vipqt - vipqh + 1 > 0)
						serving[i] = vipq[vipqh++];
					else if (qt - qh + 1 > 0)
						serving[i] = q[qh++];
				}
				else {
					tvip = tcus = 1000000000;
					if (vipqt - vipqh + 1 > 0)
						tvip = all[vipq[vipqh]].ari;
					if (qt - qh + 1 > 0)
						tcus = all[q[qh]].ari;
					if (tvip < 1000000000 || tcus < 1000000000) {
						if (tvip < tcus)
							serving[i] = vipq[vipqh++];
						else
							serving[i] = q[qh++];
					}
				}
				if (serving[i] != -1) {
					if (now < 21 * 3600) {
						int a1,a2,a3,b1,b2,b3;
						a1 = all[serving[i]].arh;
						a2 = all[serving[i]].arm;
						a3 = all[serving[i]].ars;
						b1 = now / 3600;
						b2 = (now - 3600 * b1) / 60;
						b3 = now - 3600 * b1 - 60 * b2;	
						printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",a1,a2,a3,b1,b2,b3,(int)round((float)(now - all[serving[i]].ari) / (float)60));
						end[i] = now + all[serving[i]].p * 60;
						++tot[i];
					}
					else {
						serving[i] = -1;
						--i;
					}
				}
			}
		}
		int next = 1000000001;
		if (turn < n) next = all[turn].ari;
		for (i = 1;i <= k;++i)
			if (serving[i] != -1)
				next = min(next,end[i]);
		if (next > 1000000000) break;
		now = next;
	}
	for (i = 1;i <= k;++i)
		printf(i == k ? "%d\n" : "%d ",tot[i]);
	return 0;
}

