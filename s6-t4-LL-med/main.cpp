#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val, ListNode *next1 = nullptr)
    {
        data = val;
        next = next1;
    }
};

ListNode *convertArrToLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *prev = nullptr, *temp = head, *forward = head->next;
    while (temp != nullptr)
    {
        temp->next = prev;
        prev = temp;
        temp = forward;
        if (forward != nullptr)
            forward = forward->next;
    }
    return prev;
}

ListNode *reverseLlUsingRecursion(ListNode *prev, ListNode *temp, ListNode *forward)
{
    if (forward == nullptr)
    {
        temp->next = prev;
        return temp;
    }

    temp->next = prev;
    return reverseLlUsingRecursion(temp, forward, forward->next);
}

ListNode *reverseList_1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *prev = nullptr, *temp = head, *forward = head->next;
    return reverseLlUsingRecursion(prev, temp, forward);
}

bool hasCycle(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *temp = head;
    unordered_map<ListNode *, int> mpp;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
            return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}

ListNode *detectCycle_1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return nullptr;
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int lengthOfLoop(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    int cnt = 0;
    do
    {
        fast = fast->next;
        cnt++;
    } while (slow != fast);

    return cnt;
}

bool isPalindrome(ListNode *head)
{
    ListNode *temp = head;
    string s = "", s2 = "";
    while (temp)
    {
        s += temp->data;
        s2 = to_string(temp->data) + s2;
        temp = temp->next;
    }
    return s == s2;
}

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp1 = head, *temp2 = head->next, *temp3 = head->next;
    while (temp1->next != nullptr && temp2->next != nullptr)
    {
        temp1->next = temp1->next->next;
        temp2->next = temp2->next->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp3;
    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int size = 0;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    temp = head;
    if (n == size)
        return head->next;
    for (int i = 0; i < size - n - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}

ListNode *removeNthFromEnd_1(ListNode *head, int n) {
    if(!head)
        return nullptr;
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy, *fast = dummy;
    for (int i = 0; i < n + 1; i++)
        fast = fast->next;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

ListNode *deleteMiddle(ListNode *head)
{
    if(!head || !head->next)
        return nullptr;
    ListNode *slow, *fast, *prev;
    prev = slow = fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = prev->next->next;
    delete slow;
    return head;
}

ListNode *sortLL1s2s3s(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *zeroHead = new ListNode(-1);
    ListNode *oneHead = new ListNode(-1);
    ListNode *twoHead = new ListNode(-1);
    ListNode *zero = zeroHead, *one = oneHead, *two = twoHead;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else if (temp->data == 2)
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    return zeroHead->next;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *temp = head;
    int sum = 0, carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        sum = l1->data + l2->data + carry;
        carry = sum / 10;
        sum %= 10;
        ListNode *newNode = new ListNode(sum);
        temp->next = newNode;
        temp = newNode;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr)
    {
        sum = l1->data + carry;
        carry = sum / 10;
        sum %= 10;
        ListNode *newNode = new ListNode(sum);
        temp->next = newNode;
        temp = newNode;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        sum = l2->data + carry;
        carry = sum / 10;
        sum %= 10;
        ListNode *newNode = new ListNode(sum);
        temp->next = newNode;
        temp = newNode;
        l2 = l2->next;
    }
    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        temp->next = newNode;
        temp = newNode;
    }

    return head->next;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    ListNode *head = convertArrToLL(arr);
    printLL(head);
    cout << "---------------------------" << endl;

    cout << middleNode(head)->data << endl;
    cout << "---------------------------" << endl;

    head = reverseList(head);
    printLL(head);
    cout << "---------------------------" << endl;

    head = reverseList_1(head);
    printLL(head);
    cout << "---------------------------" << endl;

    ListNode *cycleHead = new ListNode(1);
    cycleHead->next = new ListNode(2);
    cycleHead->next->next = new ListNode(3);
    cycleHead->next->next->next = new ListNode(4);
    cycleHead->next->next->next->next = new ListNode(5);
    cycleHead->next->next->next->next->next = cycleHead->next->next;

    cout << hasCycle(cycleHead) << endl;
    cout << "---------------------------" << endl;

    cout << detectCycle(cycleHead) << endl;
    cout << "---------------------------" << endl;

    cout << detectCycle_1(cycleHead) << endl;
    cout << "---------------------------" << endl;

    cout << lengthOfLoop(cycleHead) << endl;
    cout << "---------------------------" << endl;
    
    cout << isPalindrome(head) << endl;
    cout << "---------------------------" << endl;

    printLL(head);
    head = oddEvenList(head);
    printLL(head);
    cout << "---------------------------" << endl;

    printLL(head);
    head = removeNthFromEnd(head, 2);
    printLL(head);
    cout << "---------------------------" << endl;

    printLL(head);
    head = deleteMiddle(head);
    printLL(head);
    cout << "---------------------------" << endl;

    cin >> n;
    arr.resize(n);
    // for (int &a : arr)
    //     cin >> a;
    // ListNode *headSort = convertArrToLL(arr);
    // printLL(headSort);
    // headSort = sortLL(headSort);
    // printLL(headSort);
    // cout << "---------------------------" << endl;

    for (int &a : arr)
        cin >> a;
    ListNode *headSort = convertArrToLL(arr);
    printLL(headSort);
    headSort = sortLL1s2s3s(headSort);
    printLL(headSort);
    cout << "---------------------------" << endl;
    



    

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    ListNode *head1 = convertArrToLL(arr);
    printLL(head1);
    cout << "+" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    ListNode *head2 = convertArrToLL(arr);
    printLL(head2);
    cout << "=" << endl;
    ListNode *head3 = addTwoNumbers(head1, head2);
    printLL(head3);
    cout << "---------------------------" << endl;

    return 0;
}