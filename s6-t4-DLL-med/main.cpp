#include <iostream>
#include <unordered_set>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int val1, ListNode *prev1 = nullptr, ListNode *next1 = nullptr)
    {
        val = val1;
        prev = prev1;
        next = next1;
    }
};

ListNode *convertToDLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i], temp);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void printDLL(ListNode *head)
{
    while (head->next != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;
    while (head->prev != nullptr)
    {
        cout << head->val << " -> ";
        head = head->prev;
    }
    cout << head->val << endl;
}

ListNode *deleteAllOccurrences(ListNode *head, int target)
{
    ListNode *dummyHead = new ListNode(-1, nullptr, head);
    ListNode *prevNode = dummyHead;
    head->prev = dummyHead;
    ListNode *temp = head, *nextNode = head->next;
    while (temp)
    {
        if (temp->val == target)
        {
            prevNode->next = nextNode;
            if (nextNode)
                nextNode->prev = prevNode;
            free(temp);
        }
        else
            prevNode = prevNode->next;

        temp = nextNode;
        if (nextNode)
            nextNode = nextNode->next;
    }
    head = dummyHead->next;
    if (head)
        head->prev = nullptr;
    return head;
}

vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
{
    vector<vector<int>> res;
    ListNode *start = head, *end = head;
    while (end->next != nullptr)
        end = end->next;

    while (start->val < end->val)
    {
        if (start->val + end->val == target)
        {
            res.push_back({start->val, end->val});
            start = start->next;
            end = end->next;
        }
        else if (start->val + end->val < target)
            start = start->next;
        else
            end = end->prev;
    }
    return res;
}

ListNode *removeDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *prevNode = head, *temp = head->next, *nextNode = head->next->next;
    while (temp->next != nullptr)
    {
        if (prevNode->val == temp->val)
        {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(temp);
        }
        else
            prevNode = prevNode->next;
        temp = nextNode;
        if (nextNode)
            nextNode = nextNode->next;
    }
    return head;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    ListNode *head = convertToDLL(arr);
    cout << "Before: " << endl;
    printDLL(head);
    head = deleteAllOccurrences(head, 4);
    cout << "After: " << endl;
    printDLL(head);
    cout << "---------------------------------------" << endl;

    printDLL(head);
    vector<vector<int>> res = findPairsWithGivenSum(head, 7);
    for (vector<int> &ans : res)
        cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    cout << "---------------------------------------" << endl;

    for (int &a : arr)
        cin >> a;
    head = convertToDLL(arr);
    cout << "Before: " << endl;
    printDLL(head);
    head = removeDuplicates(head);
    cout << "After: " << endl;
    printDLL(head);
    cout << "---------------------------------------" << endl;

    return 0;
}