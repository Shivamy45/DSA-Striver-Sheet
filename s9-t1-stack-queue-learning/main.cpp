#include <iostream>
using namespace std;

class stackImpUsingArray
{
public:
    int topPointer = -1;
    static const int stackSize = 10;
    int st[stackSize] = {0};

    void push(int val)
    {
        if (topPointer == stackSize - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        topPointer++;
        st[topPointer] = val;
    }
    void pop()
    {
        if (topPointer == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        st[topPointer] = -1;
        topPointer--;
    }
    int top()
    {
        if (topPointer == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return st[topPointer];
    }
};

class queueImpUsingArray
{
public:
    int front = -1, rear = -1;
    static const int queueSize = 10;
    int qt[queueSize] = {0};

    void push(int val)
    {
        if ((rear + 1) % queueSize == front)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % queueSize;
        qt[rear] = val;
    }
    void pop()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        qt[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % queueSize;
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return qt[front];
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return qt[rear];
    }
};

// Stack using Queue
class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    void push(int x)
    {
        if (q2.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop()
    {
        int x = -1;
        if (q1.empty())
        {
            while (!q2.empty())
            {
                x = q2.front();
                q2.pop();
                if (q2.empty())
                    break;
                q1.push(x);
            }
        }
        else
        {
            while (!q1.empty())
            {
                x = q1.front();
                q1.pop();
                if (q1.empty())
                    break;
                q2.push(x);
            }
        }
        return x;
    }

    int top()
    {
        return (q2.empty()) ? q1.back() : q2.back();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

// Stack using Queue
class MyStack
{
public:
    queue<int> qt;
    MyStack()
    {
    }

    void push(int x)
    {
        int n = qt.size();
        qt.push(x);
        for (int i = 0; i < n; i++)
        {
            qt.push(qt.front());
            qt.pop();
        }
    }

    int pop()
    {
        int x = qt.front();
        qt.pop();
        return x;
    }

    int top()
    {
        return qt.front();
    }

    bool empty()
    {
        return qt.empty();
    }
};

// Queue using two stack
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int front = s1.top();
        s1.pop();
        return front;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

// Queue using one Stack
class MyQueue
{
public:
    stack<int> s1;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (s1.empty())
        {
            s1.push(x);
            return;
        }
        int popped = pop();
        push(x);
        s1.push(popped);
    }

    int pop()
    {
        int popped = s1.top();
        s1.pop();
        return popped;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

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

class stackImpUsingLL
{
public:
    Node *topPointer = nullptr;
    int size = 0;

    void push(int val)
    {
        if (!topPointer)
            topPointer = new Node(val);
        else
        {
            Node *newNode = new Node(val);
            newNode->next = topPointer;
            topPointer = newNode;
        }
        size++;
    }
    void pop()
    {
        if (!topPointer)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        Node *temp = topPointer;
        topPointer = topPointer->next;
        delete temp;
        size--;
    }
    int top()
    {
        if (!topPointer)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return topPointer->data;
    }
    int getSize() { return size; }
};

class queueImpUsingLL
{
public:
    Node *front = nullptr, *back = nullptr;
    int size = 0;

    void push(int val)
    {
        if (!back)
        {
            back = new Node(val);
            front = back;
        }
        else
        {
            Node *newNode = new Node(val);
            back->next = newNode;
            back = newNode;
        }
        size++;
    }
    void pop()
    {
        if (!front)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        Node *temp = front;
        if (front == back)
        {
            front = nullptr;
            back = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete temp;
        size--;
    }
    int getFront()
    {
        if (!front)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return front->data;
    }
    int getRear()
    {
        if (!back)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return back->data;
    }
    int getSize() { return size; }
};

bool isValid(string s)
{
    stack<char> st;
    for (char &c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else if (c == ')' && st.top() == '(')
            st.pop();
        else if (c == '}' && st.top() == '{')
            st.pop();
        else if (c == ']' && st.top() == '[')
            st.pop();
        else
            return false;
    }
    if (!st.empty())
        return false;
    return true;
}

class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }
    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
    stackImpUsingArray *st = new stackImpUsingArray();
    int op, val;
    while (1)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            st->push(val);
        }
        else if (op == 2)
            st->pop();
        else if (op == 3)
            cout << st->top() << endl;
        else
            break;
    }
    cout << "-----------------------" << endl;

    queueImpUsingArray *qt = new queueImpUsingArray();
    while (1)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            qt->push(val);
        }
        else if (op == 2)
            qt->pop();
        else if (op == 3)
            cout << qt->getFront() << endl;
        else if (op == 4)
            cout << qt->getRear() << endl;
        else
            break;
    }
    cout << "-----------------------" << endl;

    stackImpUsingLL *stLL = new stackImpUsingLL();
    while (1)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            stLL->push(val);
        }
        else if (op == 2)
            stLL->pop();
        else if (op == 3)
            cout << stLL->top() << endl;
        else
            break;
    }
    cout << "-----------------------" << endl;

    queueImpUsingLL *qtLL = new queueImpUsingLL();
    while (1)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> val;
            qtLL->push(val);
        }
        else if (op == 2)
            qtLL->pop();
        else if (op == 3)
            cout << qtLL->getFront() << endl;
        else if (op == 4)
            cout << qtLL->getRear() << endl;
        else
            break;
    }
    cout << "-----------------------" << endl;

    string brackets;
    cin.ignore();
    getline(cin, brackets);
    cout << isValid(brackets) << endl;
    cout << "-----------------------" << endl;

    return 0;
}