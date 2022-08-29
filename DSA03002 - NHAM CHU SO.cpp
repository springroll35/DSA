#include<bits/stdc++.h>

using namespace std;

int t;
long long m,n;
long long lt[20];

long long check(long long n) {
long long m=n,sum=0;
int dem=0;
while(m>0) {
long long dv=m%10;
if (dv==6) dv=5;
sum+=dv*lt[dem++];
m/=10;
}
return sum;
}

long long check2(long long n) {
long long m=n,sum=0;
int dem=0;
while(m>0) {
long long dv=m%10;
if (dv==5) dv=6;
sum+=dv*lt[dem++];
m/=10;
}
return sum;
}


void solve() {
scanf("%lld%lld",&m,&n);
printf("%lld %lld\n",check(m)+check(n),check2(m)+check2(n));
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

lt[0]=1;
for(int i=1;i<=18;i++) lt[i]=lt[i-1]*10;
solve();

return 0;
}