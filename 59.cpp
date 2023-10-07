#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> res;
        if (maxWidth == 0) return {""};
        int i = 0, j = 0;
        while (j != words.size()) {
            int len = -1;
            while (j < words.size() && len + words[j].size() + 1 <= maxWidth)
                len += words[j++].size() + 1;
            int space = maxWidth - len + j - i - 1;
            int k = i;
            while (space) {
                words[k++] += " ";
                space--;
                if (j != words.size() && (k == j - 1 || k == j)) k = i;
                if (j == words.size() && k == j) k = j - 1;
            }
            std::string line = "";
            for (int l = i; l < j; l++)
                line += words[l];
            res.push_back(line);
            i = j;
        }
        return res;
    }
};

int main() {
    Solution solution;

    std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    std::vector<std::string> justifiedText = solution.fullJustify(words, maxWidth);

    // Printing the justified text
    for (const std::string& line : justifiedText) {
        std::cout << line << std::endl;
    }

    return 0;
}
