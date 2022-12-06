// 2022-12-07
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


int main() {
	fastio;
	vector<vi> g(26);
    vi cost(26);
    string str;
    vi degree(26);
    while(getline(cin, str)){
        vs A;
        stringstream ss;
        ss.str(str);
        string s;
        while(ss >> s){
            A.push_back(s);
        }
        cost[A[0][0] - 'A'] = stoi(A[1]);
        if(A.size() == 3){
            for(auto& j : A[2]){
                g[j - 'A'].push_back(A[0][0] - 'A');
                degree[A[0][0] - 'A']++;
            }
        }
    }
    queue<int> Q;
    vi ans(26);
    for(int i{0}; i < 26; ++i){
        if(degree[i] == 0) {
            Q.push(i);
            ans[i] = cost[i];
        }
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            ans[i] = max(ans[i], ans[x] + cost[i]);
            degree[i]--;
            if(degree[i] == 0) Q.push(i);
        }
    }
    cout << *max_element(ans.begin(), ans.end());
}
	
