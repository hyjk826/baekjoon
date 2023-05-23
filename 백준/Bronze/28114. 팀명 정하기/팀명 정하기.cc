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
    int a, b;
    string str;
};

int main(){
	fastio;
    vector<st> vec(3);
    for(int i{0}; i < 3; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].str;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.b % 100 < y.b % 100;
    });
    for(auto& i : vec){
        cout << i.b % 100;
    }
    cout << "\n";
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.a > y.a;
    });
    for(auto& i : vec){
        cout << i.str[0];
    }
}
