// 2022-05-28
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

struct st{
    int a, b, c, num;
    bool operator< (const st& s) const{
        if(a == s.a){
            if(b == s.b){
                return c < s.c;
            }
            else return b < s.b;
        }
        else return a > s.a;
    }
};

int main(){
    fastio;
	int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
        vec[i].num = i + 1;
    }
    sort(vec.begin(), vec.end());
    cout << vec.front().num;
}