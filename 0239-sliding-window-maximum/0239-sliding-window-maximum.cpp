// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> dq;
//         vector<int> ans;

//         //first window traversal
//         for(int i=0;i<k;i++){
//                 //remove smaller elements
//                 while((!dq.empty()) && nums[i] >= nums[dq.back()]){
//                     dq.pop_back();
//                 }
//             //inserting index , so that we can check out of window elements
//             dq.push_back(i);
//         }  

//         //store answer for first window
//         ans.push_back(nums[dq.front()]);
        

//         //process remaining window
//         for(int i=k;i<nums.size();i++){
//             // remove out of window elements
//             if((!dq.empty()) && (i-dq.front()) >= k){
//                 dq.pop_front();
//             }
//             //remove smaller elements for the current element
//             while((!dq.empty()) && nums[i] >= nums[dq.back()]){
//                 dq.pop_back();
//             }
//             //inserting index , so that we can check out of window elements
//             dq.push_back(i);

//             //store answer for current window
//             ans.push_back(nums[dq.front()]);

//         }
//         return ans;
//     }
// };

//using heap
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>>maxHeap ;
        vector<int> ans;
        
        //preprocess
        for(int i=0;i<k;i++){
           maxHeap.push({nums[i],i});
        }

        ans.push_back(maxHeap.top().first);

        for(int i=k;i<n;i++){
            maxHeap.push({nums[i], i});
            
            //pop out of window elements --> 1st way
            // while((!maxHeap.empty()) && (i-maxHeap.top().second >= k)){ 
            //     maxHeap.pop();
            // }

            //2nd way to pop --> //also formula can be written as maxHeap.top().second < i-k+1 
            while((!maxHeap.empty()) && (maxHeap.top().second < i-k+1)){ 
                maxHeap.pop();
            }


            // ans[i-k+1] = maxHeap.top().first;
            ans.push_back(maxHeap.top().first);

        }

        return ans;
    }
};