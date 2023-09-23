


// Problem link : https://leetcode.com/problems/minimum-array-length-after-pair-removals/description/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {

        int lastCnt = 1;
        vector<int> arr;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                lastCnt++;
            }else{
                arr.push_back(lastCnt);
                lastCnt = 1;
            }
        }
        arr.push_back(lastCnt);
        int tot = 0;
        for(int i=0;i<arr.size();i++){
            tot += arr[i];
        }

        vector<bool> chk(arr.size(),false);
        for(int i =0;i<arr.size();i++){
            if(tot - arr[i] < arr[i]){
                return arr[i] - (tot - arr[i]);
            }            
        }

        return nums.size()%2;
    }
};