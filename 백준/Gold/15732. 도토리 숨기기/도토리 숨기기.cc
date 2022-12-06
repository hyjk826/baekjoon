// 2022-12-07
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

struct st{
    int a, b, c;
};

int main() {
	fastio;
	int n, k, d;
    cin >> n >> k >> d;
    vector<st> vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    int l{1}, r{n};
    int ans{0};
    while(l <= r){
        int mid{(l + r) / 2};
        ll sum{0};
        for(int i{0}; i < k; ++i){
            if(mid >= vec[i].a) sum += (min(mid, vec[i].b) - vec[i].a) / vec[i].c + 1;
        }
        if(sum >= d){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
	
