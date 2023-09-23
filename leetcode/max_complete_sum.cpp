
// problem link : https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/

class Solution {
public:

    int getResidue(int x){       
        for(int i = 2; i*i <= x;i++){
            int sq = i*i;
            if(x%sq == 0){
              return getResidue(x/sq);
            }
        }
        return x;
    }
    long long maximumSum(vector<int>& nums) {
        
        map<int,long long> mp;
        long long ans = 0;
        for(int i =0;i<nums.size();i++){
            int res = getResidue(i+1);
            mp[res] += nums[i];
            ans = max(ans, mp[res]);
        }

        return ans;

    }
};