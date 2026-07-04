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

    for (auto a : meetings)
        cout << a->idx << " -> " << a->start << ", " << a->end << endl;
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

    return 0;
}