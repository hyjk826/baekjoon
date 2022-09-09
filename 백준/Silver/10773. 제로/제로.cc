// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n;
    cin >> n;
    vi vec;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a == 0) vec.pop_back();
        else vec.push_back(a);
    }
    cout << accumulate(vec.begin(), vec.end(), 0);
}