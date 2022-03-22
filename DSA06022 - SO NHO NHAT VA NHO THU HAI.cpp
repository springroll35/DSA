#include <bits/stdc++.h>

using namespace std;

#define ll long long

typedef pair<int,int> II;

const int maxn = 1e6+1;

int n;
int a[maxn];

void process() {
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++) {
		if (a[0] != a[i]) {
			cout << a[0] <<  " " << a[i] << endl;
			return;
		}
	}
	cout << "-1\n";

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





