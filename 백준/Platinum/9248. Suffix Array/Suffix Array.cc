// 2022-12-01
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

vi SuffixArray(string &s) {
    int n=s.size();
    int lim = max(257,n+1);
    vi sfx(n);
    vi g(n + 1);
    vi ng(n + 1);
    vi orderToIdx(n + 1);
    vi cnt;
    for(int i=0; i<n; i++) sfx[i]=i, g[i]=s[i];
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int idx=n-1; idx>=0; idx--) orderToIdx[--cnt[g[min(idx+t,n)]]]=idx;
 
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[orderToIdx[i]]]]=orderToIdx[i];
 
        auto cmp = [&](int i, int j) {
            if(g[i]==g[j]) return g[i+t]<g[j+t];
            else return g[i]<g[j];
        };
        ng[sfx[0]]=1;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        swap(g, ng);
    }
    return sfx;
}

vi LcpArray(string& str){
    vi sfx = SuffixArray(str);
    int n = (int)str.size();
    vi rank(n);
    vi lcp(n);
    for(int i{0}; i < n; ++i){
        rank[sfx[i]] = i;
    }   
    int len = 0;
    for(int i{0}; i < n; ++i){
        int k = rank[i];
        if(k){
            int j = sfx[k - 1];
            while(str[j + len] == str[i + len]) len++;
            lcp[k] = len;
            if(len) len--;
        }
    }
    return lcp;
}

int main() {
	fastio;
	string str;
    cin >> str;
    vi sfx = SuffixArray(str);
    vi lcp = LcpArray(str);
    for(auto& i : sfx) cout << i + 1 << " ";
    cout << "\n";
    cout << "x" << " ";
    for(int i{1}; i < (int)lcp.size(); ++i){
        cout << lcp[i] << " ";
    }
}
	
