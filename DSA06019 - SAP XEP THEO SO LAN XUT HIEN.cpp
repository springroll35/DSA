#include <bits/stdc++.h>

using namespace std;

#define ll long long

typedef pair<int,int> II;

const int maxn = 1e5+1;

int n;
int a[maxn],d[maxn];

bool cmp(int x,int y) {
    return (d[x] > d[y] || (d[x] == d[y] && x < y));
}

void process() {
	cin >> n;
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++) cin >> a[i], d[a[i]]++;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout << a[i] << " ";
	cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    return 0;
}





