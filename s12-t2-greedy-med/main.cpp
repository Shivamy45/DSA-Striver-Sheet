#include <iostream>
using namespace std;

struct Node {
    int start;
    int end;
    int idx;
    Node(int a, int b, int i) : start(a), end(b), idx(i) {}
};

vector<int> maxMeetings(vector<int>& s, vector<int>& f) {
    // code here
    int n = s.size();
    vector<Node*> meetings;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        meetings.push_back(new Node(s[i], f[i], i + 1));
    }
    sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
        if (a->end == b->end) {
            return a->idx < b->idx;
        }
        return a->end < b->end;
    });

    int end = -1;
    for (auto meeting : meetings) {
        if (meeting->start > end) {
            res.push_back(meeting->idx);
            end = meeting->end;
        }
    }
    return res;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxIdx) return false;
        maxIdx = max(maxIdx, i + nums[i]);
    }
    return true;
}

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int cnt = 0, maxIdx = 0, currMaxIdx = 0;
    for (int i = 0; i < n - 1 && maxIdx < n - 1; i++) {
        currMaxIdx = max(currMaxIdx, i + nums[i]);
        if (i == maxIdx) {
            maxIdx = currMaxIdx;
            cnt++;
        }
    }
    return cnt;
}

int minPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int maxTrains = 0, currTrains = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            currTrains++;
            i++;
        } else {
            currTrains--;
            j++;
        }
        maxTrains = max(maxTrains, currTrains);
    }
    return maxTrains;
}

vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
    vector<pair<int, int>> jobs;
    int n = deadline.size();
    for (int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }
    int jobCnt = 0, maxProfit = 0;
    sort(jobs.begin(), jobs.end(), greater<>());
    vector<bool> timeline(n + 1, false);
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].second; j > 0; j--) {
            if (!timeline[j]) {
                timeline[j] = true;
                jobCnt++;
                maxProfit += jobs[i].first;
                break;
            }
        }
    }
    return {jobCnt, maxProfit};
}

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }
    int candy = 0, given = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || ratings[i] > ratings[i - 1]) {
            given++;
        } else
            given = 1;
        candy += max(right[i], given);
    }
    return candy;
}
int candy2(vector<int>& ratings) {
    int n = ratings.size();
    int total = 1;
    int i = 1;
    while (i < n) {
        if (ratings[i] == ratings[i - 1]) {
            total++;
            i++;
            continue;
        }
        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1]) {
            peak++;
            total += peak;
            i++;
        }
        int down = 1;
        while (i < n && ratings[i] < ratings[i - 1]) {
            total += down;
            down++;
            i++;
        }
        if (down > peak) total += (down - peak);
    }

    return total;
}

int solve(vector<int>& bt) {
    sort(bt.begin(), bt.end());
    int wait = 0, totalTime = 0;
    for (int b : bt) {
        totalTime += wait;
        wait += b;
    }
    return totalTime / bt.size();
}

vector<vector<int>> insert(vector<vector<int>>& intervals,
                           vector<int>& newInterval) {
    int i = 0, n = intervals.size();
    vector<vector<int>> res;
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i++]);
    }
    while (i < n && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < n) {
        res.push_back(intervals[i++]);
    }
    return res;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (auto interval : intervals) {
        if (res.empty() || res.back()[1] < interval[0])
            res.push_back(interval);
        else {
            res.back()[1] = max(res.back()[1], interval[1]);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& a : arr) cin >> a;
    vector<int> arr2(n);
    for (int& a : arr2) cin >> a;
    vector<int> res = maxMeetings(arr, arr2);
    for (int a : res) cout << a << " ";
    cout << endl;
    cout << "---------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    cout << canJump(arr) << endl;
    cout << "---------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    cout << jump(arr) << endl;
    cout << "---------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    arr2.resize(n);
    for (int& a : arr2) cin >> a;
    cout << minPlatform(arr, arr2) << endl;
    cout << "---------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    arr2.resize(n);
    for (int& a : arr2) cin >> a;
    vector<int> ans = jobSequencing(arr, arr2);
    cout << ans[0] << " " << ans[1] << endl;
    cout << "---------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    cout << candy(arr) << endl;
    cout << "---------------" << endl;
    cout << candy2(arr) << endl;
    cout << "---------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    cout << solve(arr) << endl;
    cout << "---------------" << endl;

    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (auto& interval : intervals) cin >> interval[0] >> interval[1];
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    vector<vector<int>> mergedIntervals = insert(intervals, newInterval);
    for (auto& interval : mergedIntervals)
        cout << interval[0] << " " << interval[1] << endl;
    cout << "---------------" << endl;

    cin >> n;
    intervals.resize(n, vector<int>(2));
    for (auto& interval : intervals) cin >> interval[0] >> interval[1];
    mergedIntervals = merge(intervals);
    for (auto& interval : mergedIntervals)
        cout << interval[0] << " " << interval[1] << endl;
    cout << "---------------" << endl;

    return 0;
}