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
    vi vec(n);
    double sum{0};
    int mm{0};
    map<int, int> mp;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
        mp[vec[i]]++;
        mm = max(mm, mp[vec[i]]);
    }
    sort(vec.begin(), vec.end());
    cout << (int)round(sum / n) << "\n";
    cout << vec[n / 2] << "\n";
    vi A;
    for(auto& i : mp){
        if(i.second == mm) A.push_back(i.first);
    }
    sort(A.begin(), A.end());
    if(A.size() == 1) cout << A[0] << "\n";
    else cout << A[1] << "\n";
    cout << vec.back() - vec.front();
}