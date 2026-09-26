#include <iostream>
#include <string>
#include <unordered_map>

class AuthenticationManager {
private:
    int ttl;
    std::unordered_map<std::string, int> tokens;

public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
    
    void generate(std::string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(std::string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (const auto& entry : tokens) {
            if (entry.second > currentTime) count++;
        }
        return count;
    }
};

int main() {
    AuthenticationManager auth(5);
    auth.renew("aaa", 1);
    auth.generate("aaa", 2);
    std::cout << "Tokens no expirados a t=6: " << auth.countUnexpiredTokens(6) << std::endl;
    auth.generate("bbb", 7);
    auth.renew("aaa", 8);
    auth.renew("bbb", 10);
    std::cout << "Tokens no expirados a t=15: " << auth.countUnexpiredTokens(15) << std::endl;
    return 0;
}
