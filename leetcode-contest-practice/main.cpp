#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <queue>
using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int helper(map<
               pair<int, pair<long long, long long>>,
               long long>
               &memo,
           vector<int> &nums, long long k, int i, long long num, long long den)
{
    int g = gcd(num, den);
    num /= g;
    den /= g;
    if (i == nums.size())
        return (num % den == 0) && ((num / den) == k);
    auto key = make_pair(i, make_pair(num, den));
    if (memo.count(key))
        return memo[key];
    int cnt = 0;
    cnt += helper(memo, nums, k, i + 1, num, den);
    cnt += helper(memo, nums, k, i + 1, num * nums[i], den);
    cnt += helper(memo, nums, k, i + 1, num, den * nums[i]);
    memo[key] = cnt;
    return cnt;
}

int countSequences(vector<int> &nums, long long k)
{
    map<
        pair<int, pair<long long, long long>>,
        long long>
        memo;
    return helper(memo, nums, k, 0, 1, 1);
}

int main()
{
    return 0;
}