#include <iostream>
#include <map>
using namespace std;

void twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i <= nums.size(); i++)
    {
        auto it = find(nums.begin(), nums.end(), target - nums[i]);
        if (it != nums.end())
        {
            int x = distance(nums.begin(), it);
            if (i == x)
                continue;
            cout << i << " " << x << endl;
            return;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    twoSum(nums, 8);
    return 0;
}