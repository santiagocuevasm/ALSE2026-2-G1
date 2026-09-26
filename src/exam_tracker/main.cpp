#include <iostream>
#include <vector>
#include <algorithm>

class ExamTracker {
private:
    std::vector<int> times;
    std::vector<long long> prefixSum;

public:
    ExamTracker() {
        prefixSum.push_back(0);
    }
    
    void record(int time, int score) {
        times.push_back(time);
        prefixSum.push_back(prefixSum.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it1 = std::lower_bound(times.begin(), times.end(), startTime);
        int idx1 = std::distance(times.begin(), it1);

        auto it2 = std::upper_bound(times.begin(), times.end(), endTime);
        int idx2 = std::distance(times.begin(), it2);

        if (idx1 >= idx2) return 0;
        return prefixSum[idx2] - prefixSum[idx1];
    }
};

int main() {
    ExamTracker tracker;
    tracker.record(1, 98);
    std::cout << "Suma (1..1): " << tracker.totalScore(1, 1) << std::endl;
    tracker.record(5, 99);
    std::cout << "Suma (1..3): " << tracker.totalScore(1, 3) << std::endl;
    std::cout << "Suma (1..5): " << tracker.totalScore(1, 5) << std::endl;
    std::cout << "Suma (3..4): " << tracker.totalScore(3, 4) << std::endl;
    std::cout << "Suma (2..5): " << tracker.totalScore(2, 5) << std::endl;
    return 0;
}
