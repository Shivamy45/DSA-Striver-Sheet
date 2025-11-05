#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val1, ListNode *next1 = nullptr)
    {
        val = val1;
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
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << temp->val << endl;
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
    stack<int> st;
    ListNode *temp = head;
    while (temp)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->val != st.top())
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

bool isPalindrome_1(ListNode *head)
{
    if (!head || !head->next)
        return true;

    ListNode *slow, *fast, *first;
    slow = fast = first = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverseList(slow->next);
    slow = slow->next;
    while (slow)
    {
        if (first->val != slow->val)
        {
            reverseList(newHead);
            return false;
        }
        first = first->next;
        slow = slow->next;
    }
    reverseList(newHead);
    return true;
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

ListNode *removeNthFromEnd_1(ListNode *head, int n)
{
    if (!head)
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
    if (!head || !head->next)
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

ListNode *sortList(ListNode *head)
{
    ListNode *temp1 = head, *temp2 = head;
    while (temp1 != nullptr)
    {
        bool swapped = false;
        temp2 = temp1->next;
        while (temp2 != nullptr)
        {
            if (temp1->val > temp2->val)
            {
                swap(temp1->val, temp2->val);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}
ListNode *helperMergeList(ListNode *temp1, ListNode *temp2)
{
    ListNode *dummyHead = new ListNode(-1);
    ListNode *temp = dummyHead;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->val <= temp2->val)
        {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 == nullptr)
    {
        temp->next = temp2;
    }
    else
    {
        temp->next = temp1;
    }
    return dummyHead->next;
}

ListNode *helperMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *sortList_1(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *middle = helperMiddle(head);
    ListNode *right = middle->next;
    middle->next = nullptr;
    ListNode *left = sortList_1(head);
    right = sortList_1(right);
    return helperMergeList(left, right);
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
        if (temp->val == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->val == 1)
        {
            one->next = temp;
            one = temp;
        }
        else if (temp->val == 2)
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> sett;
    ListNode *t1 = headA, *t2 = headB;
    while (t1 != nullptr)
    {
        sett.insert(t1);
        t1 = t1->next;
    }
    while (t2 != nullptr)
    {
        if (sett.find(t2) != sett.end())
            return t2;
        t2 = t2->next;
    }
    return nullptr;
}

ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA, *t2 = headB;
    int n = 0, m = 0;
    while (t1)
    {
        m++;
        t1 = t1->next;
    }
    while (t2)
    {
        n++;
        t2 = t2->next;
    }
    t1 = headA;
    t2 = headB;
    for (int i = 0; i < abs(m - n); i++)
        if (m > n)
            t1 = t1->next;
        else
            t2 = t2->next;
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t1 == t2)
        return t1;
    return nullptr;
}

ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA, *t2 = headB;
    while (t1 != t2)
    {
        t1 = (t1 != nullptr) ? t1->next : headB;
        t2 = (t2 != nullptr) ? t2->next : headA;
    }
    return t1;
}

ListNode *addOne(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *dummyHead = new ListNode(1, head);
    ListNode *prev = dummyHead, *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->val != 9)
            prev = temp;
        temp = temp->next;
    }
    if (temp->val == 9)
    {
        temp = prev->next;
        while (temp != nullptr)
        {
            temp->val = 0;
            temp = temp->next;
        }
        if (prev == dummyHead)
            return dummyHead;
        prev->val += 1;
    }
    else
        temp->val += 1;
    return head;
}

ListNode *addOne_1(ListNode *head)
{
    head = reverseList(head);
    ListNode *temp = head;
    int carry = 1;
    while (temp && carry)
    {
        int sum = temp->val + carry;
        carry = sum / 10;
        temp->val = sum % 10;
        if (!temp->next && carry)
            temp->next = new ListNode(0); // creates a extra node for the carry
        temp = temp->next;
    }
    head = reverseList(head);
    return head;
}
int helperRecAddOne(ListNode *head)
{
    if (!head)
        return 1;
    int carry = helperRecAddOne(head->next);
    int sum = head->val + carry;
    carry = sum / 10;
    head->val = sum % 10;
    return carry;
}

ListNode *addOne_2(ListNode *head)
{
    int carry = helperRecAddOne(head);
    if (carry)
        return new ListNode(carry, head);
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *temp = head;
    int sum = 0, carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        sum = l1->val + l2->val + carry;
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
        sum = l1->val + carry;
        carry = sum / 10;
        sum %= 10;
        ListNode *newNode = new ListNode(sum);
        temp->next = newNode;
        temp = newNode;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        sum = l2->val + carry;
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

    cout << middleNode(head)->val << endl;
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

    cout << isPalindrome_1(head) << endl;
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
    for (int &a : arr)
        cin >> a;
    ListNode *headSort = convertArrToLL(arr);
    printLL(headSort);
    headSort = sortList(headSort);
    printLL(headSort);
    cout << "---------------------------" << endl;

    headSort = convertArrToLL(arr);
    printLL(headSort);
    headSort = sortList_1(headSort);
    printLL(headSort);
    cout << "---------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    headSort = convertArrToLL(arr);
    printLL(headSort);
    headSort = sortLL1s2s3s(headSort);
    printLL(headSort);
    cout << "---------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    head = convertArrToLL(arr);
    printLL(head);
    head = addOne(head);
    printLL(head);
    cout << "---------------------------" << endl;

    printLL(head);
    head = addOne_1(head);
    printLL(head);
    cout << "---------------------------" << endl;

    printLL(head);
    head = addOne_2(head);
    printLL(head);
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