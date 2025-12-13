class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int, string>> validCoupons;
        int n = code.size();
        for (int i = 0; i < n; ++i) {
            bool isValid = true;
            if (code[i].empty()) {
                isValid = false;
            } else {
                for (char c : code[i]) {
                    if (!isalnum(c) && c != '_') {
                        isValid = false;
                        break;
                    }
                }
            }
            if (businessLine[i] != "electronics" && businessLine[i] != "grocery" &&
                businessLine[i] != "pharmacy" && businessLine[i] != "restaurant") {
                isValid = false;
            }
            if (!isActive[i]) {
                isValid = false;
            }

            if (isValid) {
                int businessLinePriority;
                if (businessLine[i] == "electronics") {
                    businessLinePriority = 0;
                } else if (businessLine[i] == "grocery") {
                    businessLinePriority = 1;
                } else if (businessLine[i] == "pharmacy") {
                    businessLinePriority = 2;
                } else {
                    businessLinePriority = 3;
                }
                validCoupons.push_back({businessLinePriority, code[i]});
            }
        }

        sort(validCoupons.begin(), validCoupons.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        vector<string> result;
        for (const auto& coupon : validCoupons) {
            result.push_back(coupon.second);
        }

        return result;
    }
};