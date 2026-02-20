#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < k)
        {
            minHeap.push(nums[i]);
            continue;
        }
        if (minHeap.top() <= nums[i])
        {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
}

// helper for findKthLargestWithoutHeap
int partitionAndPivotIndex(vector<int> &arr, int l, int r)
{
    int pivot = arr[l];
    int idx = l + 1;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] > pivot)
        {
            swap(arr[i], arr[idx++]);
        }
    }
    swap(arr[l], arr[idx - 1]);
    return idx - 1;
}
int findKthLargestWithoutHeap(vector<int> &nums, int k)
{
    int l = 0, r = nums.size() - 1, pivotIdx;
    while (true)
    {
        pivotIdx = partitionAndPivotIndex(nums, l, r);
        if (pivotIdx == k - 1)
            return nums[pivotIdx];
        else if (pivotIdx > k - 1)
            r = pivotIdx - 1;
        else
            l = pivotIdx + 1;
    }
    return -1;
}

vector<int> sortNearlySortedArray(vector<int> &arr, int k)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k; i++)
        pq.push(arr[i]);
    for (int i = k + 1; i < arr.size(); i++)
    {
        int x = pq.top();
        res.push_back(x);
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        int x = pq.top();
        res.push_back(x);
        pq.pop();
    }
    return res;
}
struct cmp
{
    bool operator()(ListNode *a, ListNode *b) const
    {
        return a->val > b->val; // min-heap
    }
};

priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *dummy = new ListNode();
    ListNode *tail = dummy;
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    for (auto &node : lists)
    {
        if (node != nullptr)
            pq.push(node);
    }
    while (!pq.empty())
    {
        ListNode *smallest = pq.top();
        pq.pop();
        tail->next = smallest;
        tail = tail->next;
        if (smallest->next != nullptr)
        {
            pq.push(smallest->next);
        }
    }
    return dummy->next;
}

// Not useful using heap, sorting + map is better
vector<int> replaceWithRank(vector<int> &arr, int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++)
        pq.push({arr[i], i});
    int cnt = 0;
    int prev = -1;
    vector<int> ans(N);
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        if (x.first != prev)
            cnt++;
        ans[x.second] = cnt;
        prev = x.first;
    }
    return ans;
}

int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> mpp;
    for (char c : tasks)
        mpp[c]++;

    priority_queue<int> pq;
    for (auto &it : mpp)
        pq.push(it.second);

    int time = 0;

    while (!pq.empty())
    {
        vector<int> temp;
        int slots = n + 1;

        while (slots-- && !pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if (--x > 0)
                temp.push_back(x);
            time++;
        }

        for (int x : temp)
            pq.push(x);

        if (pq.empty())
            break;

        time += slots + 1;
    }

    return time;
}

bool isNStraightHand(vector<int> &hand, int k)
{
    int n = hand.size();
    if (n % k != 0)
        return false;
    unordered_map<int, int> freq;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int h : hand)
    {
        freq[h]++;
    }
    for (auto it : freq)
        pq.push(it.first);
    while (!pq.empty())
    {
        int x = pq.top();
        for (int i = 0; i < k; i++)
        {
            if (freq.count(x + i) == 0)
                return false;
            freq[x + i]--;
            if (freq[x + i] == 0)
            {
                if ((x + i) != pq.top())
                    return false;
                pq.pop();
            }
        }
    }
    return true;
}

// GFG - k sorted array
string isKSortedArray(vector<int> &arr, int n, int k)
{

    return "Yes";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    cout << findKthLargest(arr, k) << endl;
    cout << "--------------------" << endl;

    cout << findKthLargestWithoutHeap(arr, k) << endl;
    cout << "--------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    vector<int> res = sortNearlySortedArray(arr, k);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------------" << endl;

    cin >> n;
    vector<char> arr2(n);
    for (char &a : arr2)
        cin >> a;
    cin >> k;
    cout << leastInterval(arr2, k) << endl;
    cout << "--------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    cout << isNStraightHand(arr, k) << endl;
    cout << "--------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    cout << isKSortedArray(arr, n, k) << endl;
    cout << "--------------------" << endl;
    return 0;
}