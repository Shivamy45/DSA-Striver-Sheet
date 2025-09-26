#include <iostream>
#include <numeric>

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

int painterPartition(vector<int> &boards, int painter)
{
    int n = boards.size();
    // using in-build func from numeric
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int painterAssigned = 1, boardAssigned = 0;
        for (int board : boards)
        {
            if (boardAssigned + board > mid)
            {
                painterAssigned++;
                boardAssigned = 0;
            }
            boardAssigned += board;
            if (painterAssigned > painter)
                break;
        }
        if (painterAssigned > painter)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

double maxDistBtwGasStations(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> alreadyPlaced(n - 1, 0);
    double maxDiff = INT_MIN, maxDiffIdx = -1;
    while (k--)
    {
        double actualDiff = INT_MIN;
        maxDiffIdx = -1;
        maxDiff = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            actualDiff = (stations[i + 1] - stations[i]) / (alreadyPlaced[i] + 1);
            if (maxDiff < actualDiff)
            {
                maxDiff = actualDiff;
                maxDiffIdx = i;
            }
        }
        cout << maxDiff << " at " << maxDiffIdx << ". " << alreadyPlaced[maxDiffIdx];
        alreadyPlaced[maxDiffIdx]++;
        cout << " -> " << alreadyPlaced[maxDiffIdx] << endl;
    }
    maxDiff = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        maxDiff = max((double)(stations[i + 1] - stations[i]) / (alreadyPlaced[i] + 1), maxDiff);
    }
    return maxDiff;
}

// Using Priority Queue
double maxDistBtwGasStations_1(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> alreadyPlaced(n - 1, 0);
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < n - 1; i++)
        pq.push({stations[i + 1] - stations[i], i});

    for (int i = 0; i < k; i++)
    {
        auto top = pq.top();
        pq.pop();
        cout << top.first << " at " << top.second << ". " << alreadyPlaced[top.second];

        alreadyPlaced[top.second]++;
        double newStationLen = (double)(stations[top.second + 1] - stations[top.second]) / (alreadyPlaced[top.second] + 1);
        pq.push({newStationLen, top.second});

        cout << " -> " << alreadyPlaced[top.second] << endl;
    }

    return pq.top().first;
}

long double maxDistBtwGasStations_2(vector<int> &stations, int k)
{
    int n = stations.size();
    long double low = 0, high = INT_MIN;
    for (int i = 0; i < n - 1; i++)
        high = max(high, (long double)stations[i + 1] - stations[i]);
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int inBtw = (stations[i + 1] - stations[i]) / mid;
            if ((stations[i] - stations[i - 1]) == (mid * inBtw))
            {
                inBtw--;
            }
            cnt += inBtw;
            if (cnt > k)
                break;
        }
        if (cnt <= k)
            high = mid;
        else
            low = mid;
    }
    return high;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int cnt = 0;
    int i = 0, j = 0;
    int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
    double ele1 = -1, ele2 = -1;
    while (i < n1 && j < n2)
    {
        if (nums1[i] <= nums2[j])
        {
            cnt++;
            if (cnt == n / 2)
                ele1 = nums1[i];
            if (cnt - 1 == n / 2)
            {
                ele2 = nums1[i];
                break;
            }
            i++;
        }
        else
        {
            cnt++;
            if (cnt == n / 2)
                ele1 = nums2[j];
            if (cnt - 1 == n / 2)
            {
                ele2 = nums2[j];
                break;
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (cnt == n / 2)
            ele1 = nums1[i];
        if (cnt - 1 == n / 2)
        {
            ele2 = nums1[i];
            break;
        }
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == n / 2)
            ele1 = nums2[j];
        if (cnt - 1 == n / 2)
        {
            ele2 = nums2[j];
            break;
        }
        cnt++;
        j++;
    }

    if (n % 2)
        return ele2;
    return (ele1 + ele2) / 2;
}

double findMedianSortedArrays_1(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    // ensure nums1 is smaller
    if (n1 > n2)
        return findMedianSortedArrays_1(nums2, nums1);
    int n = n1 + n2;

    int low = 0, high = n1;
    while (low <= high)
    {
        int x = (low + high) / 2;
        int left = n / 2 - x;

        int l1 = (x == 0 ? INT_MIN : nums1[x - 1]);
        int r1 = (x == n1 ? INT_MAX : nums1[x]);
        int l2 = (left == 0 ? INT_MIN : nums2[left - 1]);
        int r2 = (left == n2 ? INT_MAX : nums2[left]);

        if (max(l1, l2) <= min(r1, r2))
            return (n % 2) ? min(r1, r2) : (max(l1, l2) + min(r1, r2)) / 2.0;
        else if (l1 > r2)
            high = x - 1;
        else
            low = x + 1;
    }
    return -1;
}

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2)
        return kthElement(b, a, k);
    int n = n1 + n2;
    int low = max(0, k - n2), high = min(k, n1);
    while (low <= high)
    {
        int x = (low + high) / 2;
        int left = k - x;

        int l1 = (x == 0 ? INT_MIN : a[x - 1]);
        int r1 = (x == n1 ? INT_MAX : a[x]);
        int l2 = (left == 0 ? INT_MIN : b[left - 1]);
        int r2 = (left == n2 ? INT_MAX : b[left]);

        if (max(l1, l2) <= min(r1, r2))
            return max(l1, l2);
        else if (l1 > r2)
            high = x - 1;
        else
            low = x + 1;
    }
    return -1;
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
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << painterPartition(arr, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    cout << maxDistBtwGasStations(arr, m) << endl;
    cout << "--------------------" << endl;
    cout << maxDistBtwGasStations_1(arr, m) << endl;
    cout << "--------------------" << endl;
    cout << maxDistBtwGasStations_2(arr, m) << endl;
    cout << "--------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    vector<int> arr2(m);
    for (int &a : arr2)
        cin >> a;
    cout << findMedianSortedArrays(arr, arr2) << endl;
    cout << "--------------------" << endl;
    cout << findMedianSortedArrays_1(arr, arr2) << endl;
    cout << "--------------------" << endl;
    cout << kthElement(arr, arr2, 8) << endl;
    cout << "--------------------" << endl;

    return 0;
}