// 2022-06-28
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;


double f1(pair<double, double> A, pair<double, double> B){
    return (A.second - B.second) / (A.first - B.first);
}

bool f2(int a, int b, int c){
    double x = f1({-a/sqrt(2.0), a / sqrt(2.0)}, {0, b});
    double y = f1({0, b}, {c / sqrt(2.0), c / sqrt(2.0)});
    if(x >= y) return true;
    return false;
}

int main(){
    fastio;
    vi vec(8);
    vi p = {0,1,2,3,4,5,6,7};
    for(int i{0}; i < 8; ++i){
        cin >> vec[i];
    }
    int ans{0};
    do{
        bool flag = true;
        for(int i{0}; i < 8; ++i){
            flag &= f2(vec[p[i]], vec[p[(i + 1) % 8]], vec[p[(i + 2) % 8]]);
        }
        if(flag) ans++;
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << "\n";
}
