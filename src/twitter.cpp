#include "twitter.h"
#include <queue>
#include <algorithm>

Twitter::Twitter() : time_stamp(0) {}

void Twitter::postTweet(int userId, int tweetId) {
    user_tweets[userId].push_back({time_stamp++, tweetId});
}

std::vector<int> Twitter::getNewsFeed(int userId) {
    std::priority_queue<std::pair<int, int>> pq; // {timestamp, tweetId}

    // Agregar tweets del usuario
    for (const auto& t : user_tweets[userId]) {
        pq.push(t);
    }

    // Agregar tweets de los seguidos
    for (int followeeId : user_follows[userId]) {
        for (const auto& t : user_tweets[followeeId]) {
            pq.push(t);
        }
    }

    std::vector<int> res;
    while (!pq.empty() && res.size() < 10) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

void Twitter::follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
        user_follows[followerId].insert(followeeId);
    }
}

void Twitter::unfollow(int followerId, int followeeId) {
    user_follows[followerId].erase(followeeId);
}
