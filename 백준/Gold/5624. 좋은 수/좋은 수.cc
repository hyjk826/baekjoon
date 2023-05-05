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

int ch[400001];

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        vec[i] += 100000;
    }
    ch[vec[0] + vec[0]]++;
    int ans{0};
    for(int i{1}; i < n; ++i){
        int k = vec[i] + 200000;
        for(int j{i - 1}; j >= 0; --j){
            if(k - vec[j] >= 0 && k - vec[j] <= 400000 && ch[k - vec[j]]) {
                ans++; break;
            }
        }
        for(int j{i}; j >= 0; --j){
            ch[vec[i] + vec[j]] = 1;
        }
    }
    cout << ans;
}
