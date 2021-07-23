#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		set<long long> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// store all the elements in a set
			s.emplace(a[i]);
		}
		// sort the sequence in non-increasing order
		sort(a.rbegin(), a.rend());
		// set 'res' to the first element
		long long res = a[0];
		bool checker = true;
		// start the loop from the second element
		for (int i = 1; i < n; i++) {
			// find the OR result of every element
			res |= a[i];
			// check if the current OR-result is already present in the set
			if (s.find(res) != s.end()) {
				// if yes, then set checker to false and break the loop
				checker = false;
				break;
			}
			// otherwise, store the current OR-result in the set
			s.emplace(res);
		}
		cout << (checker ? "YES" : "NO") << '\n';
	}
	return 0;
}
