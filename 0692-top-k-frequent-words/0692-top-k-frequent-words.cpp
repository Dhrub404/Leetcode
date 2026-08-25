class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        //custom comparator
        auto cmp = [](pair<int,string>& a, pair<int,string>& b) {
            if(a.first == b.first) {
                return a.second > b.second;  //smaller word comes first
            }
            return a.first < b.first;  //higher frequency comes first
        };

        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)> pq(cmp);

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};