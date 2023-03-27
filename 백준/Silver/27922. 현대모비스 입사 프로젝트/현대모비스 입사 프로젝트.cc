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

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vector<st> vec(n);
    int ans{0};
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.a + x.b > y.a + y.b;
    });
    for(int i{0}; i < k; ++i){
        sum += vec[i].a + vec[i].b;
    }
    ans = max(ans, sum);
    sum = 0;
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.a + x.c > y.a + y.c;
    });
    for(int i{0}; i < k; ++i){
        sum += vec[i].a + vec[i].c;
    }
    ans = max(ans, sum);
    sum = 0;
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.b + x.c > y.b + y.c;
    });
    for(int i{0}; i < k; ++i){
        sum += vec[i].b + vec[i].c;
    }
    ans = max(ans, sum);
    cout << ans;
}
