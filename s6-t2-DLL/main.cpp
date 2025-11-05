#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val, Node *prevPtr = nullptr, Node *nextPtr = nullptr)
    {
        data = val;
        prev = prevPtr;
        next = nextPtr;
    }
};

Node *convertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

void printDLL(Node *head)
{
    if (head == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

Node *insertAtHead(Node *head, int ele)
{
    Node *newNode = new Node(ele, nullptr, head);
    if (head == nullptr)
        return newNode;
    head->prev = newNode;
    return newNode;
}

Node *insertNodeAtKth(Node *head, int ele, int idx)
{
    if (idx == 0)
        return insertAtHead(head, ele);
    if (head == nullptr)
        return nullptr;

    Node *newNode = new Node(ele);
    Node *temp = head;
    for (int i = 0; i < idx - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr)
        return head;

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    head->prev = nullptr;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    Node *before = temp->prev;
    before->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node *deleteKth(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;

    for (int i = 0; i < k && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr)
        return head;

    Node *before = temp->prev;
    Node *after = temp->next;
    if (!before && !after)
        return nullptr;
    else if (!before)
        return deleteHead(head);
    else if (!after)
        return deleteTail(head);

    before->next = after;
    after->prev = before;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteByVal(Node *head, int ele)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp != nullptr && temp->data != ele)
        temp = temp->next;

    if (temp == nullptr)
        return head;

    Node *before = temp->prev;
    Node *after = temp->next;
    if (!before && !after)
        return nullptr;
    else if (!before)
        return deleteHead(head);
    else if (!after)
        return deleteTail(head);

    before->next = after;
    after->prev = before;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *reverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    stack<int> filler;
    Node *temp = head;
    while (temp)
    {
        filler.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr || !filler.empty())
    {
        temp->data = filler.top();
        temp = temp->next;
        filler.pop();
    }

    return head;
}

Node *reverseDLL_1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *temp = head, *prev = nullptr;
    while (temp)
    {
        temp->prev = temp->next;
        temp->next = prev;

        prev = temp;
        temp = temp->prev;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;

    Node *head = convertArrToDLL(arr);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = insertAtHead(head, 6);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = insertNodeAtKth(head, 9, 3);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = deleteHead(head);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = deleteTail(head);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = deleteKth(head, 3);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = deleteByVal(head, 9);
    printDLL(head);
    cout << "-----------------------" << endl;

    head = convertArrToDLL(arr);
    head = reverseDLL(head);
    printDLL(head);
    cout << "-----------------------" << endl;
    head = reverseDLL_1(head);
    printDLL(head);
    cout << "-----------------------" << endl;

    return 0;
}