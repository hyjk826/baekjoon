// 2022-12-04
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
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        map<int, int> mp;
        mp[0] = 1;
        for(int i{0}; i < n; ++i){
            vi A;
            for(int j{1}; j * j <= vec[i]; ++j){
                if(vec[i] % j == 0){
                    if(j * j == vec[i]) A.push_back(j);
                    else{
                        A.push_back(j);
                        A.push_back(vec[i] / j);
                    }
                }
            }
            sort(A.begin(), A.end());
            map<int, int> mp2;
            for(int j{0}; j < (int)A.size(); ++j){
                auto it = mp.upper_bound(A[j]);
                if(it == mp.begin()) continue;
                it--;
                mp2[A[j]] += it->second;
            }
            int pre = 0;
            for(auto j{mp2.begin()}; j != mp2.end(); ++j){
                j->second += pre;
                j->second %= MOD;
                pre = j->second;
            }
            swap(mp, mp2);
        }
        cout << prev(mp.end())->second << "\n";
    }
}
	
