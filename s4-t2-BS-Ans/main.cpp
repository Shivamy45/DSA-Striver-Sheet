#include <iostream>

using namespace std;

int findSqrt(int n)
{
    int ans = -1;
    for (int i = 1; i < n; i++)
    {
        if (i * i <= n)
            ans = i;
        else
            break;
    }
    return ans;
}

int findSqrt_1(int n)
{
    // int ans = 1;
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= n)
        {
            // ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    // low will be the first wrong ans
    // high will be the last possible ans
    return high;
    // return ans;
}

// Power exponential method:
long long funcPow(int b, int exp, int n)
{
    long long ans = 1;
    long long base = b;
    while (exp > 0)
    {
        if (ans > n)
            break;

        if (exp % 2)
        {
            exp--;
            ans = ans * base;
        }
        else
        {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int nthRootOfaNumber(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        long long temp = funcPow(i, m, n);
        if (temp == n)
            return i;
    }
    return -1;
}

int nthRootOfaNumber_1(int n, int m)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int temp = funcPow(mid, m, n);
        if (temp == n)
            return mid;
        else if (temp < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int high = INT_MIN;
    for (int pile : piles)
        high = max(high, pile);
    int low = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int timeTaken = 0;
        for (int pile : piles)
            timeTaken += ceil((float)pile / mid);
        if (timeTaken <= h)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int low = INT_MAX, high = INT_MIN;
    for (int flowers : bloomDay)
    {
        low = min(low, flowers);
        high = max(high, flowers);
    }
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cont = 0, bouquetMade = 0;
        for (int flowerBloom : bloomDay)
        {
            if (flowerBloom <= mid)
                cont++;
            else
                cont = 0;
            if (cont == k)
            {
                cont = 0;
                bouquetMade++;
            }
            if (bouquetMade == m)
                break;
        }
        if (bouquetMade >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1, high = INT_MAX;
    for (int num : nums)
        high = min(high, num);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sumQo = 0;
        for (int num : nums)
            sumQo += ceil((float)num / mid);
        if (sumQo < threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int shipWithinDays(vector<int> &weights, int days)
{
    long long low = 1, high = INT_MIN;
    for (long long weight : weights)
        high = max(high, weight);
    high *= high;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long currWeight = 0;
        int day = 0;
        for (long long weight : weights)
        {
            if (currWeight + weight > mid)
            {
                day++;
                currWeight = 0;
            }
            currWeight += weight;
        }
        if (day <= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low + k;
}

bool helperAggresiveCows(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size();
    int prevCow = stalls[0], cowPlaced = 1;
    for (int i = 1; i < n; i++)
    {
        if (dist <= stalls[i + 1] - prevCow)
        {
            cowPlaced++;
            prevCow = stalls[i + 1];
        }
        if (cowPlaced >= cows)
            return true;
    }
    return false;
}

int aggresiveCows(vector<int> &stalls, int cows)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (helperAggresiveCows(stalls, mid, cows))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int minimumPagesAllocation(vector<int> &books, int students)
{
    int n = books.size();
    int low = INT_MIN, high = 0;
    for (int pages : books)
    {
        low = max(low, pages);
        high += pages;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int studentAssigned = 1, pagesAssigned = 0;
        for (int pages : books)
        {
            if (pagesAssigned + pages > mid)
            {
                studentAssigned++;
                pagesAssigned = 0;
            }
            pagesAssigned += pages;
            if (studentAssigned > students)
                break;
        }
        if (studentAssigned > students)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int helperSplitArray(vector<int> &nums, int maxSum)
{
    // To get no. of splits of the array for maxSum(mid)
    int currSum = 0, splits = 1;
    for (int num : nums)
    {
        if (currSum + num > maxSum)
        {
            splits++;
            currSum = 0;
        }
        currSum += num;
    }
    return splits;
}
int splitArray(vector<int> &nums, int k)
{
    int low = INT_MIN, high = 0;
    for (int num : nums)
    {
        low = max(low, num);
        high += num;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (helperSplitArray(nums, mid) > k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    cout << findSqrt(n) << endl;
    cout << findSqrt_1(n) << endl;
    cout << "--------------------" << endl;
    int m;
    cin >> m;
    cout << nthRootOfaNumber(n, m) << endl;
    cout << nthRootOfaNumber_1(n, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    int h;
    cin >> h;
    cout << minEatingSpeed(arr, h) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m >> h;
    cout << minDays(arr, m, h) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << smallestDivisor(arr, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << shipWithinDays(arr, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << findKthPositive(arr, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << aggresiveCows(arr, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << minimumPagesAllocation(arr, m) << endl;
    cout << "--------------------" << endl;

    return 0;
}