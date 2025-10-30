#include <iostream>
using namespace std;

void sort0and1(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}

Node *s(Node *root)
{
    Node *temp = root;
    temp = temp->left;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;

    sort0and1(arr);
    for (int num : arr)
        cout << num << " ";
    return 0;
}

/*
1d array
0/1 combo

sort 0, 1
*/