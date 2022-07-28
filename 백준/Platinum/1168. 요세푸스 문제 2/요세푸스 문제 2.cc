// 2022-07-18
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

template <typename T>
struct binary_indexed_tree {
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N) : N(N), BIT(N + 1, 0) {
    }
    void add(int i, T x) {
        i++;
        while (i <= N) {
            BIT[i] += x;
            i += i & -i;
        }
    }
    T sum(int i) {
        T ans = 0;
        while (i > 0) {
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }
    T f(int a, int b) {
        if (a > b) return 0;
        if (a == 0) return sum(b + 1);
        else return sum(b + 1) - sum(a);
    }
};

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    binary_indexed_tree<int> BIT(2 * n);
    for (int i{ 1 }; i <= n; ++i) {
        BIT.add(i, 1);
    }
    cout << "<";
    int index{ 0 };
    for (int i{ 0 }; i < n; ++i) {
        int c = k;
        c %= (n - i);
        if (c == 0) c = n - i;
        int s = BIT.f(index + 1, n);
        int ans{ MAX };
        if (s < c) {
            c -= s;
            int l{ 1 }, r{ index - 1 };
            while (l <= r) {
                int m{ (l + r) / 2 };
                if (BIT.f(0, m) < c) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                    ans = min(ans, m);
                }
            }
        }
        else {
            int l{ index + 1 }, r{ n };
            while (l <= r) {
                int m{ (l + r) / 2 };
                if (BIT.f(index + 1, m) < c) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                    ans = min(ans, m);
                }
            }
        }
        if(i < n - 1){
            cout << ans << ", ";
        }
        else{
            cout << ans << ">";
        }
        index = ans;
        BIT.add(ans, -1);
    }
}
