#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT                 \
     ios_base::sync_with_stdio(false); \
     cin.tie(0)
#define fo(i, n) for (lli i = 0; i < (n); i++)
#define FO(i, x, n) for (lli i = (x); i < (n); i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli, lli>
#define vii vector<pi>
#define Endl "\n"
using namespace std;
const lli mod = 1e9 + 7;

lli gcd(lli a, lli b){
      if (b == 0)
        return a;
      return gcd(b, a % b);
}


lli fac[11];

lli ncr(lli n, lli r){
     if(r > n){
          return 0;
     }
     if(r == n){return 1;}

     lli x = fac[n] / fac[r];
     x /= fac[n-r];
     return x;
}


lli getLen(lli x){

     lli tot = 9;
      if(tot >= x){
               return 1;
     }
     for(lli len = 2;len <= 10;len++){
          tot += ncr(10, len);
          if(tot >= x){
               return len;
          }
     }
     return 10;
}

void generateNums(string num, lli len, vector<string> & nums){
     if(num.length() == len){
          nums.push_back(num);
          return;
     }
     // cout<<num<<"\n";
     lli last = num.back() - '0';

     if(last < len - num.length()){
          return ;
     }

     fo(i, last){
          num += ('0' + i);
          generateNums(num, len, nums);
          num.pop_back();
     }

}

bool comp(const string& s, const string& t){
     if (s.length() != t.length()){
       if (s.length() < t.length()){
          return true;
       }
       return false;
     }
     for(int i = 0;i < s.length();i++){
          if(s[i] < t[i]){
               return true;
          }else if(s[i] > t[i]){
               return false;
          }
     }

}

lli stringToInt(string& s){
     lli num = 0;
     for(char c : s){
          num = num *10 + (c - '0');
     }
     return num;
}
void solve(){

     lli n;
     cin>>n;

     vector<string> nums;

     for(int len = 1;len <= 10;len++){
          for(int start = 1;start < 10;start++){

               char st = ('0' + start);
               string s = "";
               s += st;
               generateNums(s, len,nums );
          }
     }

     vi numbers;

     for(string s : nums){
          numbers.push_back(stringToInt(s));
     }
     sort(numbers.begin(),numbers.end());
     // for(int x : numbers){
     //      cout<<x<<"\n";
     // }
     cout<<numbers[n-1]<<"\n";

}    

int main(){
     fac[0] = 1;
     FO(i,1,11){
          fac[i] = i * fac[i-1]; 
     }


     ULTRA_INSTINCT;
     lli t = 1;
     // cin >> t;
     fo(i, t){
          //   cout<<"Case #"<<i+1<<": ";
          solve();
     }
     return 0;
}