class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        sort(tasks.begin(), tasks.end());
        int n1 = tasks.size();
        int c = 0;
        int maxi = 0;

        unordered_map<int,int> mp;
        for(auto it : tasks){
            mp[it]++;
            maxi = max(maxi , mp[it]);
        }

        for(auto it : mp){
            if(maxi == it.second){
                c++;
            }
        } 

        int ans = ((maxi-1) * (n+1)) + c;
        return ans > tasks.size() ? ans : tasks.size();

    }
};