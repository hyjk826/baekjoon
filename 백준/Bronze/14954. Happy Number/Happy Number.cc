// 2022-11-13
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

int main() {
	fastio;
    int n;
    cin >> n;
    set<int> st;
    while(1){
        int sum{0};
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if(sum == 1){
            cout << "HAPPY";
            return 0;
        }
        if(st.count(sum)){
            cout << "UNHAPPY";
            return 0;
        }
        else st.insert(sum);
        n = sum;
    }
}
	

