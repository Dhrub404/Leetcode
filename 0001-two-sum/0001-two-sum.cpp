class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using map
        // unordered_map<int,int> mp;

        // for(int i=0;i<nums.size();i++){
        //     int need = target - nums[i];

        //     if(mp.find(need) != mp.end()){
        //         return {mp[need],i};
        //     }

        //     mp[nums[i]] = i;
        // }
        // return {}; 


        // USNIG 2 Pointer approach
        int low = 0;
        int high = nums.size() - 1;

        vector<pair<int,int>> arr;

        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i] , i});
        }

        sort(arr.begin() , arr.end());

        while(low<high){
            if(arr[low].first + arr[high].first == target){
                return {arr[low].second , arr[high].second};
            }
            else if(arr[low].first + arr[high].first < target){
                low++;
            }
            else{
                high--;
            }
        }
        return {};
    }
};