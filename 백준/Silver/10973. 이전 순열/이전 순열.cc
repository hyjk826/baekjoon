// 2022-07-24
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi v;
    v.push_back(vec.back());
    for(int i{n - 2}; i >= 0; --i){
        v.push_back(vec[i]);
        if(vec[i] > vec[i + 1]){
            for(int j{0}; j < i; ++j){
                cout << vec[j] << " ";
            }
            int k = vec[i] - 1;
            while(1){
                auto it = find(v.begin(), v.end(), k);
                if(it != v.end()){
                    cout << k << " ";
                    v.erase(it);
                    break;
                }
                else k--;
            }
            sort(v.rbegin(), v.rend());
            for(auto& j : v){
                cout << j << " ";
            }
            return 0;
        }
    }
    cout << -1;

}

