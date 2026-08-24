class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n = piles.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }

        while(k--){
            int maxi = pq.top();
            pq.pop();

            if(maxi%2 == 0){
                maxi = maxi/2;
            }
            else{
                maxi = maxi/2 + 1;
            }
            pq.push(maxi);
        }

        while(!pq.empty()){
            ans+= pq.top();
            pq.pop();
        }

        return ans;
    }
};