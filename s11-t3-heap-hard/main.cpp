#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

class Twitter
{
public:
    int postOrder = 0;
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> posts;
    unordered_map<int, unordered_set<int>> followers;
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        ++postOrder;
        if (posts[userId].size() == 10)
            posts[userId].pop();
        posts[userId].push({postOrder, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> news(10);
        priority_queue<int> pq;
        for (int follows : followers[userId])
        {
        }
    }

    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }
};

int main()
{

    return 0;
}