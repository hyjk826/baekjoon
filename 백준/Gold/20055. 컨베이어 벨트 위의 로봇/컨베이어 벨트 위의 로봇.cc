// 2022-07-27
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vi A(n * 2);
    vi R;
    for (int i{ 0 }; i < n * 2; ++i) {
        cin >> A[i];
    }
    int Level{ 1 };
    int cnt{ 0 };
    while (1) {
        rotate(A.rbegin(), A.rbegin() + 1, A.rend());
        for (auto& i : R) {
            i++;
        }
        while(!R.empty() && R.back() == n - 1) R.pop_back();
        for(int i{(int)R.size() - 1}; i >= 0; --i){
            if(R[i] == n - 2 && A[n - 1] != 0){
                A[n - 1]--;
                R[i]++;
                continue;
            }
            int next = R[i] + 1;
            auto it = find(R.begin(), R.end(), next);
            if(it == R.end() && A[next] != 0){
                R[i] = next;
                A[next]--;
            }
        }
        while(!R.empty() && R.back() == n - 1) R.pop_back();
        if (A[0] != 0) {
            R.insert(R.begin(), 0);
            A[0]--;
        } 
        if (count(A.begin(), A.end(), 0) >= k) {
            cout << Level;
            return 0;
        }
        Level++;
    }
}

