// 2022-08-15
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int> A;
        priority_queue<int, vi, greater<int> > B;
        vi ans;
        for(int i{0}; i < n; ++i){
            int k;
            cin >> k;
            if(A.size() > B.size()) B.push(k);
            else A.push(k);
            if(!A.empty() && !B.empty()){
                if(A.top() > B.top()){
                    int a = A.top();
                    int b = B.top();
                    A.pop();
                    B.pop();
                    A.push(b);
                    B.push(a); 
                }
            }
            if(i % 2 == 0){
                ans.push_back(A.top());
            }
        }
        cout << ans.size() << "\n";
        for(int i{0}; i < (int)ans.size(); ++i){
            cout << ans[i] << " ";
            if(i % 10 == 9) cout << "\n";
        }
        cout << "\n";
    }
}