// 2022-07-28
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

int lengthOfLIS(vector<int>& nums) {
    multiset<int> s;
    for(auto& num:nums)
    {
        s.insert(num);
        auto it = s.find(num);
        ++it;
        if(it != s.end())
        {
            s.erase(it);
        }
    }
    
    return s.size();
}

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    cout << lengthOfLIS(vec);
}

