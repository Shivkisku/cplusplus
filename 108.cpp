#include <iostream>

// Simulated read4 function for testing
int read4(char *buf) {
    // Simulate reading 4 characters from the input stream into buf
    // In a real implementation, this function would read from a file or input source
    return 4;
}

class Solution {
private:
    int ptr = 0;
    char* tmp = new char[4];
public:
    int read(char *buf, int n) {
        int cnt = 0;
        int k;
        while(cnt < n){
            if(ptr == 0) k = read4(tmp);
            if(k == 0) break;
            while(cnt < n && ptr < k){
                buf[cnt++] = tmp[ptr++];
            }
            if(ptr == k) ptr = 0;
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    char buf[100]; // Destination buffer
    int n = 10;    // Maximum number of characters to read

    int bytesRead = solution.read(buf, n);

    std::cout << "Characters read: " << bytesRead << std::endl;
    std::cout << "Content of buf: ";
    for (int i = 0; i < bytesRead; ++i) {
        std::cout << buf[i];
    }
    std::cout << std::endl;

    return 0;
}
