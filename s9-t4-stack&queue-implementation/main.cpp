#include <iostream>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res(n - k + 1);
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            res[i - k + 1] = nums[dq.front()];
    }
    return res;
}

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int idx = 1;
    StockSpanner()
    {
    }

    int next(int price)
    {
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        st.push({price, idx});
        return idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    int size, curr = 0;
    unordered_map<int, Node *> mpp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            mpp[key]->prev->next = mpp[key]->next;
            mpp[key]->next->prev = mpp[key]->prev;
            mpp[key]->next = tail;
            mpp[key]->prev = tail->prev;
            tail->prev->next = mpp[key];
            tail->prev = mpp[key];
            return mpp[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            mpp[key]->prev->next = mpp[key]->next;
            mpp[key]->next->prev = mpp[key]->prev;
            mpp[key]->next = tail;
            mpp[key]->prev = tail->prev;
            tail->prev->next = mpp[key];
            tail->prev = mpp[key];
            mpp[key]->val = value;
            return;
        }
        if (curr == size)
        {
            mpp.erase(head->next->key);
            Node *first = head->next;
            head->next = first->next;
            first->next->prev = head;
            curr--;
            delete first;
        }
        Node *newNode = new Node(key, value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;
        mpp[key] = newNode;
        curr++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct Node
{
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DLL
{
    Node *head, *tail;
    DLL()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addBack(Node *node)
    {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    bool empty()
    {
        return head->next == tail;
    }

    Node *popFront()
    {
        Node *node = head->next;
        remove(node);
        return node;
    }
};

class LFUCache
{
public:
    int capacity, used = 0, minFreq = 0;
    unordered_map<int, Node *> nodes;
    unordered_map<int, DLL *> freqList;

    LFUCache(int cap) : capacity(cap) {}

    DLL *getList(int f)
    {
        if (!freqList.count(f))
            freqList[f] = new DLL();
        return freqList[f];
    }

    void touch(Node *node)
    {
        int f = node->freq;
        freqList[f]->remove(node);
        if (f == minFreq && freqList[f]->empty())
            minFreq++;

        node->freq++;
        getList(node->freq)->addBack(node);
    }

    int get(int key)
    {
        if (!nodes.count(key))
            return -1;
        Node *node = nodes[key];
        touch(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (nodes.count(key))
        {
            Node *node = nodes[key];
            node->val = value;
            touch(node);
            return;
        }

        if (used == capacity)
        {
            Node *victim = freqList[minFreq]->popFront();
            nodes.erase(victim->key);
            delete victim;
            used--;
        }

        Node *node = new Node(key, value);
        nodes[key] = node;
        minFreq = 1;
        getList(1)->addBack(node);
        used++;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    vector<int> res = maxSlidingWindow(arr, k);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "------------------" << endl;
    return 0;
}