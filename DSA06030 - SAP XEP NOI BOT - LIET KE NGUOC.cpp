#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		stack<vector<int>> s;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - 1; i++) {
			bool ok = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j+1]) {
					swap(a[j], a[j+1]);
					ok = true;
				}
			}
			if (ok == false) break;
			s.push(a);
		}
		int sz = s.size();
		while (s.size()) {
			a = s.top();
			s.pop();
			cout << "Buoc " << sz-- << ": ";
			for (int j = 0; j < n; j++) {
				cout << a[j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}