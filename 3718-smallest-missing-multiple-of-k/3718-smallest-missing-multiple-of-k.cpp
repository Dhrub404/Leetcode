class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans = k;
        for(int i: nums){
            mp[i]++;
        }

        int c = 0;
        for(auto i: mp){
            if(mp.find(ans) == mp.end()){
                return ans;
            }
            else{
               ans += k;
               c++;
            }
            if(c == mp.size())  return ans;
        }

        return nums[0]+k;
    }
};