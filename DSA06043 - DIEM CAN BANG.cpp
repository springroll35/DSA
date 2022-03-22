#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn=1e5+5;
const ll mod=1e9+7;

int n;
int a[maxn];

void process() {
    int s[maxn];
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if (i == 0) s[i]=a[i];
        else s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<n-1;i++) {
        if (s[i-1] == s[n-1]-s[i]) {
            cout << i+1 << endl;
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
