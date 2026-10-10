class Solution {
private:
    // Helper function to check if a string has valid parentheses
    bool isValid(const std::string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
                // If closing parenthesis exceeds opening, it's immediately invalid
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);

        bool foundValidAtThisLevel = false;

        while (!q.empty()) {
            int currentLevelSize = q.size();
            
            // Process the current level entirely
            for (int i = 0; i < currentLevelSize; ++i) {
                std::string currentStr = q.front();
                q.pop();

                // If it is valid, add it to our results
                if (isValid(currentStr)) {
                    result.push_back(currentStr);
                    foundValidAtThisLevel = true;
                }

                // If we already found a valid string at this level, 
                // do not generate the next level (children)
                if (foundValidAtThisLevel) continue;

                // Generate all possible states by removing one parenthesis
                for (int j = 0; j < currentStr.length(); ++j) {
                    // Skip characters that are not parentheses
                    if (currentStr[j] != '(' && currentStr[j] != ')') continue;

                    // Form a child string by omitting the character at index j
                    std::string nextStr = currentStr.substr(0, j) + currentStr.substr(j + 1);

                    // If we haven't processed this configuration, queue it up
                    if (visited.find(nextStr) == visited.end()) {
                        q.push(nextStr);
                        visited.insert(nextStr);
                    }
                }
            }

            // Stop BFS once we have extracted all valid strings at the minimum removal level
            if (foundValidAtThisLevel) {
                break;
            }
        }

        return result;
    }
};
