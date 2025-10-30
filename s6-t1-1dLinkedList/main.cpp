#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    cout << "Created Succesfully" << endl;
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

Node *insertNode(Node *head, int ele, int idx)
{
    Node *newNode = new Node(ele);
    if (idx == 0)
    {
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    for (int i = 0; i < idx; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

//? LeetCode Solution
// void deleteNode(Node *node)
// {
//     node->data = node->next->data;
//     node->next = node->next->next;
// }

// Del by Element value
Node *deleteNode(Node *head, int ele)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    if (head->data == ele)
    {
        head = head->next;
        delete temp;
        return head;
    }
    while (temp->next != nullptr)
    {
        if (temp->next->data == ele)
        {
            temp->next = temp->next->next;
            free(temp->next);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool searchElement(Node *head, int ele)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == ele)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;

    Node *head = convertArrToLL(arr);
    cout << "--------------------------" << endl;

    printLL(head);
    cout << "--------------------------" << endl;

    head = insertNode(head, 9, 2);
    printLL(head);
    cout << "--------------------------" << endl;

    head = deleteNode(head, 2);
    printLL(head);
    cout << "--------------------------" << endl;

    cout << lengthOfLL(head) << endl;
    cout << "--------------------------" << endl;

    cout << searchElement(head, 4) << endl;
    cout << "--------------------------" << endl;

    return 0;
}