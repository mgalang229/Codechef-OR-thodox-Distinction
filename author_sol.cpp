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
		long long arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n > 60) {
			// if 'n' is greater than 60, then it is guaranteed that there will be 
			// non-distinct pairwise values in the sequence since the 'long long' data type
			// will not be able to handle the next value after 2 ^ 60
			cout << "NO";
		} else {
			// otherwise, brute-force the sets of elements to find if the values are distinct
			set<long long> uniq;
			for (int i = 0; i < n; i++) {
				long long ord = 0;
				for (int j = i; j < n; j++) {
					// find the OR-result
					ord = ord | arr[j];
					// insert the value that was produced above
					uniq.insert(ord);
				}
			}
			// check if the size of the set is equal to this equation (total number of pairs)
			if ((int) uniq.size() == (n * (n + 1)) / 2) {
				cout << "YES";
			} else {
				cout << "NO";
			}
		}
		cout << '\n';
	}
	return 0;
}
