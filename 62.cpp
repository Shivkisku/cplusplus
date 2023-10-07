#include <iostream>
#include <sstream>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string res, s;
        std::stack<std::string> stk;
        std::stringstream ss(path);
        
        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") continue;
            if (s == ".." && !stk.empty()) stk.pop();
            else if (s != "..") stk.push(s);
        }
        
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution solution;

    std::string path = "/a/./b/../../c/";

    std::string simplifiedPath = solution.simplifyPath(path);

    std::cout << "Simplified path: " << simplifiedPath << std::endl;

    return 0;
}
