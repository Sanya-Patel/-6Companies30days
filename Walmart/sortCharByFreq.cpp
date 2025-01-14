class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<pair<int, char>> v;
        string ans = "";

        // count character frequency
           for(int i=0;i<s.size();i++)
        {
           mp[s[i]]++;
        }

        // push from map to vector 
        for(auto i=mp.begin();i!=mp.end();i++){
            v.push_back({i->second, i->first});
        }

        // sort the vector in decreasing order
          sort(v.rbegin(),v.rend());

        // add to final answer string
            for(auto i:v){
               for(int j=0;j<i.first;j++){
                    ans+= i.second;
        }
    }
        return ans;
    }
};