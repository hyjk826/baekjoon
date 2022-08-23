// 2022-08-23
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

struct st{
    int a, b, c;
};

int main() {
	fastio;
    int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    sort(vec.begin(), vec.end(), [&](st x, st y){
        return x.c > y.c;
    });
    for(int i{0}; i < 3; ++i){
        if(i < 2) cout << vec[i].a << " " << vec[i].b << "\n";
        else{
            if(vec[i].a == vec[i - 1].a && vec[i].a == vec[i - 2].a){
                while(vec[i].a == vec[0].a) i++;
            }
            cout << vec[i].a << " " << vec[i].b << "\n";
        }
    }
}

