#include <iostream>
using namespace std;

const int MOD = 1000000007;

int helperMyAtoi(string s, int i, int sign, long long res)
{
    if (i >= s.size() || !isdigit(s[i]))
        return (int)sign * res;
    res = (res * 10) + (s[i] - '0');
    if (sign * res >= INT_MAX)
        return INT_MAX;
    if (sign * res <= INT_MIN)
        return INT_MIN;
    return helperMyAtoi(s, i + 1, sign, res);
}

int myAtoi(string s)
{
    int n = s.length();
    int i = 0, sign = 1;
    while (i < n && s[i] == ' ')
        i++;
    if (i < n && (s[i] == '-' || s[i] == '+'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < n && s[i] == '0')
        i++;
    return helperMyAtoi(s, i, sign, 0);
}

double helperMyPow(double x, long long n, double res)
{
    if (n == 0)
        return res;
    if (n % 2)
        return helperMyPow(x, n - 1, res * x);
    else
        return helperMyPow(x * x, n / 2, res);
    return 1.0;
}

double myPow(double x, int n)
{
    if (x == 1)
        return 1;
    long long nn = (n < 0) ? (long long)-1 * n : n;
    double res = helperMyPow(x, nn, 1.0);
    if (n < 0)
        return 1.0 / res;
    return res;
}

long long helperCountGoodNumbers(long long x, long long n)
{
    if (n == 0)
        return 1;
    if (n % 2)
        return (x % MOD) * (helperCountGoodNumbers(x, n - 1) % MOD);
    else
        return helperCountGoodNumbers(x * x, n / 2) % MOD;
}

int countGoodNumbers(long long n)
{
    long long evenPos = (n + 1) / 2;
    long long oddPos = n / 2;

    long long a = helperCountGoodNumbers(5, evenPos);
    long long b = helperCountGoodNumbers(4, oddPos);

    return (a * b) % MOD;
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void helperSortStackInsert(stack<int> &st, int val)
{
    if (st.empty() || st.top() <= val)
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    helperSortStackInsert(st, val);
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;
    int val = st.top();
    st.pop();
    sortStack(st);
    helperSortStackInsert(st, val);
}

void helperInsertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    helperInsertAtBottom(st, val);
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int val = st.top();
    st.pop();
    reverseStack(st);
    helperInsertAtBottom(st, val);
}

int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    cout << myAtoi(s) << endl;
    cout << "----------------------" << endl;

    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << myPow(x, n) << endl;
    cout << "----------------------" << endl;

    cin >> n;
    cout << countGoodNumbers(n) << endl;
    cout << "----------------------" << endl;

    cin >> n;
    stack<int> st;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        st.push(a);
    }
    printStack(st);
    sortStack(st);
    printStack(st);
    cout << "----------------------" << endl;

    printStack(st);
    reverseStack(st);
    printStack(st);
    cout << "----------------------" << endl;

    return 0;
}