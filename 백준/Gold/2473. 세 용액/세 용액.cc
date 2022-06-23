#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAX 3000000000
using namespace std;

vector<ll> vec;
int n;
ll mn{ MAX };
ll r1, r2, r3;

void asd(int i) {
	int s = 0;
	int e = n - 1;
	while (s < e) {
		if (abs(mn) > abs(vec[s] + vec[e] + vec[i])) {
			r1 = vec[s];
			r2 = vec[e];
			r3 = vec[i];
			mn = vec[s] + vec[e] + vec[i];
		}
		if (vec[s] + vec[e] + vec[i] < 0) {
			s++;
			if (s == i) {
				s++;
			}
		}
		else if (vec[s]+vec[e]+vec[i] > 0) {
			e--;
			if (e == i) {
				e--;
			}
		}
		else {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		ll a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	for (int i{ 1 }; i < n-1; ++i) {
		asd(i);
	}
	vector<ll> ans;
	ans.push_back(r1);
	ans.push_back(r2);
	ans.push_back(r3);
	sort(ans.begin(), ans.end());
	for (int i{ 0 }; i < 3; ++i) {
		cout << ans[i] << " ";
	}
}