#ifndef TWITTER_H
#define TWITTER_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Twitter {
private:
    int time_stamp;
    std::unordered_map<int, std::vector<std::pair<int, int>>> user_tweets; // userId -> vector of {timestamp, tweetId}
    std::unordered_map<int, std::unordered_set<int>> user_follows;        // userId -> set of followeeIds

public:
    Twitter();
    void postTweet(int userId, int tweetId);
    std::vector<int> getNewsFeed(int userId);
    void follow(int followerId, int followeeId);
    void unfollow(int followerId, int followeeId);
};

#endif
