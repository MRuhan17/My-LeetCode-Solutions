class TimeMap {
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        keyToTimestampValues[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& timestampValuePairs = keyToTimestampValues[key];

        pair<int, string> targetPair = {timestamp, string({127})};

        auto upperBoundIter = upper_bound(timestampValuePairs.begin(),
                                         timestampValuePairs.end(),
                                         targetPair);

        return upperBoundIter == timestampValuePairs.begin() ? "" : (upperBoundIter - 1)->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> keyToTimestampValues;
};

