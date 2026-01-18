class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
      
        for (const auto& str : strs) {
            string sortedKey = str;
          
            sort(sortedKey.begin(), sortedKey.end());
          
            anagramGroups[sortedKey].emplace_back(str);
        }
      
        vector<vector<string>> result;
      
        for (auto& [key, group] : anagramGroups) {
            result.emplace_back(group);
        }
      
        return result;
    }
};
