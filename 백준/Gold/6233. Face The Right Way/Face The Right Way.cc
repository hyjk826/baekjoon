// 2022-11-16
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        char c;
        cin >> c;
        if(c == 'B') vec[i] = 1;
    }
    vi ch(n + 1, MAX);
    for(int i{1}; i <= n; ++i){
        vi A(n + 1);
        int cnt{0};
        for(int j{0}; j <= n - i; ++j){
            if(j) A[j] += A[j - 1];
            if(((A[j] % 2) ^ vec[j]) == 0) continue;
            A[j]++;
            A[j + i]--;            
            cnt++;
        }
        bool flag = true;
        for(int j{n - i + 1}; j < n; ++j){
            A[j] += A[j - 1];
            flag &= (((A[j] % 2) ^ vec[j]) == 0);
        }
        if(flag){
            ch[i] = cnt;
        }
    }
    int mn = *min_element(ch.begin(), ch.end());
    for(int i{1}; i <= n; ++i){
        if(ch[i] == mn){
            cout << i << " " << mn;
            return 0;
        }
    }
}
	

