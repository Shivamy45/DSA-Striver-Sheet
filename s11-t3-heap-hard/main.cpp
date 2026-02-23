#include <iostream>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Twitter
{
private:
    struct Tweet
    {
        int tweetId;
        int time;
        Tweet *next;
        Tweet(int id, int t) : tweetId(id), time(t), next(nullptr) {}
    };
    int timer = 0;
    unordered_map<int, Tweet *> tweets;
    unordered_map<int, unordered_set<int>> followers;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        Tweet *t = new Tweet(tweetId, ++timer);
        t->next = tweets[userId];
        tweets[userId] = t;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<Tweet *> maxHeap;
        if (tweets[userId])
            maxHeap.push(tweets[userId]);
        for (int f : followers[userId])
        {
            if (tweets[f])
                maxHeap.push(tweets[f]);
        }
        vector<int> res;
        int i = 0;
        while (!maxHeap.empty() && i < 10)
        {
            Tweet *t = maxHeap.top();
            res.push_back(t->tweetId);
            maxHeap.pop();
            maxHeap.push(t->next);
            i++;
        }
        return res;
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

int connectSticks(vector<int> &sticks)
{
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int stick : sticks)
    {
        minHeap.push(stick);
    }
    while (!minHeap.empty())
    {
        int first = minHeap.top();
        minHeap.pop();
        int sec = minHeap.top();
        minHeap.pop();
        cost += (first + sec);
        if (!minHeap.empty())
            minHeap.push(first + sec);
    }
    return cost;
}

class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int x : nums)
        {
            minHeap.push(x);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};

vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();
    vector<int> res;
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> used;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    maxHeap.push({a[0] + b[0], {0, 0}});
    used.insert({0, 0});
    int i = 0, j = 0;
    while (res.size() < k)
    {
        auto it = maxHeap.top();
        maxHeap.pop();
        i = it.second.first, j = it.second.second;
        res.push_back(it.first);
        if (i + 1 < n && used.count({i + 1, j}) == 0)
        {
            maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
            used.insert({i + 1, j});
        }
        if (j + 1 < n && used.count({i, j + 1}) == 0)
        {
            maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
            used.insert({i, j + 1});
        }
    }

    return res;
}

class MedianFinder
{
private:
    priority_queue<int> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> greaterHalf;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (smallerHalf.empty() || num <= smallerHalf.top())
            smallerHalf.push(num);
        else
            greaterHalf.push(num);

        if (smallerHalf.size() > greaterHalf.size() + 1)
        {
            greaterHalf.push(smallerHalf.top());
            smallerHalf.pop();
        }
        else if (greaterHalf.size() > smallerHalf.size())
        {
            smallerHalf.push(greaterHalf.top());
            greaterHalf.pop();
        }
    }

    double findMedian()
    {
        if (smallerHalf.size() == greaterHalf.size())
            return (smallerHalf.top() + greaterHalf.top()) / 2.0;
        return smallerHalf.top();
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    for (int &num : nums)
        mpp[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto &it : mpp)
    {
        minHeap.push(make_pair(it.second, it.first));
        if (minHeap.size() > k)
            minHeap.pop();
    }
    vector<int> res;
    while (k-- && !minHeap.empty())
    {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    cout << connectSticks(arr) << endl;
    cout << "---------------------" << endl;

    cin >> n;
    arr.resize(n);
    vector<int> arr2(n);
    for (int &a : arr)
        cin >> a;
    for (int &a : arr2)
        cin >> a;
    int k;
    cin >> k;
    vector<int> res = topKSumPairs(arr, arr2, k);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "---------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    res = topKFrequent(arr, k);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "---------------------" << endl;

    return 0;
}