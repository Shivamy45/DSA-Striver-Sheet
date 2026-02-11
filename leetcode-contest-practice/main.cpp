#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <queue>
using namespace std;
long long countSubarrays(vector<int> &nums, long long k)
{
    int n = nums.size();
    deque<int> minE;
    deque<int> maxE;
    long long cnt = 0;
    int l = 0, r = 0;
    while(r < n)
    {
        while (!minE.empty() && nums[r] <= nums[minE.back()])
        {
            minE.pop_back();
        }
        minE.push_back(r);
        while (!maxE.empty() && nums[r] >= nums[maxE.back()])
        {
            maxE.pop_back();
        }
        maxE.push_back(r);

        long long cost = (nums[maxE.front()] - nums[minE.front()]) * (r - l + 1);
        while(cost > k){
            l++;
            if (l > maxE.front())
                maxE.pop_front();
            if (l > minE.front())
                minE.pop_front();
            cost = (nums[maxE.front()] - nums[minE.front()]) * (r - l + 1);
        }
        // cout << cost << endl;
        if (cost <= k)
            cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {1, 3, 2};
    int k = 4;
    cout << countSubarrays(nums, k);
    return 0;
}