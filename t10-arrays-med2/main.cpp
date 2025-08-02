#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

//! This is if we can do only 1 transaction
void stockBuyAndSell(vector<int> &prices)
{
    int n = prices.size();
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    cout << "Max Profit with 1 transaction: " << maxProfit << endl;
}

void stockBuyAndSell2(vector<int> &prices)
{
    bool buy = false;
    int n = prices.size();
    int boughtAt = 0, profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (prices[i + 1] > prices[i] && !buy)
        {
            buy = true;
            boughtAt = prices[i];
        }
        else if (buy && prices[i] > prices[i + 1])
        {
            buy = false;
            profit += prices[i] - boughtAt;
        }
    }
    if (buy)
    {
        profit += prices[n - 1] - boughtAt;
    }
    cout << "Max Profit with many transaction: " << profit << endl;
}

void alternatingArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> posArr;
    vector<int> negArr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            posArr.push_back(arr[i]);
        else
            negArr.push_back(arr[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = posArr[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i + 1] = negArr[i];
    }
    printArr(arr);
}
void alternatingArray2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            res[negIdx] = arr[i];
            negIdx += 2;
        }
        else
        {
            res[posIdx] = arr[i];
            posIdx += 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
}

//? if no.(+ve) != no.(-ve)
void alternatingArray3(vector<int> &arr)
{
    int n = arr.size();
    vector<int> posArr, negArr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            posArr.push_back(arr[i]);
        else
            negArr.push_back(arr[i]);
    }
    int m = min(posArr.size(), negArr.size());
    for (int i = 0; i < m; i++)
    {
        arr[2 * i] = posArr[i];
        arr[2 * i + 1] = negArr[i];
    }
    for (int i = m; i < posArr.size(); i++)
    {
        arr[m + i] = posArr[i];
    }
    for (int i = m; i < negArr.size(); i++)
    {
        arr[m + i] = negArr[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    stockBuyAndSell(prices);
    cout << "-----------------------------------" << endl;
    stockBuyAndSell2(prices);
    cout << "-----------------------------------" << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArr(arr);
    alternatingArray(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArr(arr);
    alternatingArray2(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArr(arr);
    alternatingArray3(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;

    return 0;
}