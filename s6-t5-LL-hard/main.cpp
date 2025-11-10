#include <iostream>
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

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val, Node *_next = NULL, Node *_random = NULL)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node *buildBottomList(const vector<int> &vals)
{
    if (vals.empty())
        return NULL;
    Node *head = new Node(vals[0]);
    Node *temp = head;
    for (int i = 1; i < vals.size(); i++)
    {
        temp->random = new Node(vals[i]);
        temp = temp->random;
    }
    return head;
}

Node *buildLinkedList()
{
    // Each column (main node + its random chain)
    vector<vector<int>> data = {
        {5, 7, 8, 30},
        {10, 20},
        {19, 22, 50},
        {28, 35, 40, 45}};

    Node *head = NULL;
    Node *tail = NULL;

    for (auto &col : data)
    {
        Node *colHead = buildBottomList(col);
        if (!head)
            head = tail = colHead;
        else
        {
            tail->next = colHead;
            tail = tail->next;
        }
    }

    return head;
}

void printList(Node *head)
{
    Node *down = head;
    while (down)
    {
        Node *temp = down;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->random;
        }
        cout << endl;
        down = down->next;
    }
}

Node *buildLinkedList_2()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    return head;
}

void printList_2(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << temp->val << endl;
}

ListNode *convertArrToLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i]);
        temp->next = newNode;
        temp = newNode;
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

ListNode *helperReverse(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *prev = nullptr, *temp = head, *nextNode = head->next;
    while (temp)
    {
        temp->next = prev;
        prev = temp;
        temp = nextNode;
        if (nextNode)
            nextNode = nextNode->next;
    }
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevLastNode = nullptr;
    while (temp)
    {
        ListNode *kthNode = temp;
        int end = k - 1;
        while (kthNode && end--)
            kthNode = kthNode->next;
        if (!kthNode)
        {
            if (prevLastNode)
                prevLastNode->next = temp;
            break;
        }
        ListNode *nextNode = kthNode->next;
        kthNode->next = nullptr;
        kthNode = helperReverse(temp);
        if (temp == head)
            head = kthNode;
        else
            prevLastNode->next = kthNode;
        prevLastNode = temp;
        temp = nextNode;
    }
    return head;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;
    ListNode *temp = head;
    int size = 1;
    while (temp->next)
    {
        size++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % size;
    int end = size - k;
    while (end--)
        temp = temp->next;
    head = temp->next;
    temp->next = nullptr;
    return head;
}

Node *flatten(Node *root)
{
    if (!root || !root->next)
        return root;
    root->next = flatten(root->next);
    Node *t1 = root, *t2 = root->next;
    Node *dummyHead = new Node(-1);
    Node *temp = dummyHead;
    while (t1 && t2)
    {
        if (t1->val <= t2->val)
        {
            temp->random = t1;
            t1 = t1->random;
        }
        else
        {
            temp->random = t2;
            t2 = t2->random;
        }
        temp = temp->random;
    }
    if (t1 == nullptr)
        temp->random = t2;
    else
        temp->random = t1;

    dummyHead->random->next = nullptr;
    return dummyHead->random;
}

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, Node *> mpp;
    while (temp)
    {
        mpp[temp] = new Node(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        mpp[temp]->next = mpp[temp->next];
        mpp[temp]->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

Node *copyRandomList_1(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        temp->next = new Node(temp->val, temp->next);
        temp = temp->next->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        else
            temp->next->random = nullptr;
        temp = temp->next->next;
    }
    Node *dummyHead = new Node(-1, head);
    Node *res = dummyHead;
    temp = head;
    while (temp)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        res = res->next;
    }
    return dummyHead->next;
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
    head = reverseKGroup(head, 3);
    printLL(head);
    cout << "------------------------------" << endl;

    printLL(head);
    head = rotateRight(head, 2);
    printLL(head);
    cout << "------------------------------" << endl;

    Node *subHead = buildLinkedList();
    cout << "Before: " << endl;
    printList(subHead);
    subHead = flatten(subHead);
    cout << "After: " << endl;
    printList(subHead);
    cout << "------------------------------" << endl;

    Node *ranHead = buildLinkedList_2();
    printList_2(ranHead);
    // ranHead = copyRandomList(ranHead);
    printList_2(ranHead);
    cout << "------------------------------" << endl;

    printList_2(ranHead);
    ranHead = copyRandomList_1(ranHead);
    printList_2(ranHead);
    cout << "------------------------------" << endl;

    return 0;
}