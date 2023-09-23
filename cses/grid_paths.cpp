#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<iterator>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli,lli>
#define vii vector<pi >
#define Endl endl
#define ITA 200005
#define ROH 100005
#define deb(x) cout<<(#x)<<" "<<x<<endl
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}
 
int dp[1001][1001];
void solve(){
    lli n;
    cin>>n;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    dp[0][0] = s[0][0] != '*';
    fo(i,n){
        fo(j,n){
            if(s[i][j] == '*' ){
                continue;
            }
            if(i > 0){
                dp[i][j] += (dp[i-1][j]);   
                dp[i][j] %= mod;
            }
            if(j>0){
                dp[i][j] += (dp[i][j-1]);
                dp[i][j] %= mod;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}
 
int main(){
    ULTRA_INSTINCT;
    lli t =1;
    // cin>>t;
    fo(i,t){
        solve();
    }
    return 0;
}