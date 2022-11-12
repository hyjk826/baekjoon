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
    vi prime((int)1e7 + 1);
    prime[1] = 1;
    for(int i{2}; i <= (int)1e7; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= (int)1e7; j += i){
                prime[j] = 1;
            }
        }
    }
    set<int> s;
    for(int i{1}; i <= n; ++i){
        if(prime[i]) continue;
        int sum = i;
        set<int> st;
        bool flag = false;
        vi A;
        while(1){
            int a = sum;
            sum = 0;
            while(a){
                sum += (a % 10) * (a % 10);
                a /= 10;
            }
            if(s.count(sum) || sum == 1){
                flag = true;
                break;
            }
            if(st.count(sum)) break;
            st.insert(sum);
            A.push_back(sum);
        }
        if(flag){
            for(auto& i : A) s.insert(i);
            cout << i << "\n";
        }
    }
}
	

