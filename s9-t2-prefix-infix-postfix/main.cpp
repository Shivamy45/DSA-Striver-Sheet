#include <iostream>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

string convertInfixToPostfix(string &infix)
{
    stack<char> st;
    string res = "";
    for (char &c : infix)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isalnum(c))
        {
            res += c;
        }
        else
        {
            bool rightAss = false;
            if (c == '^')
                rightAss = true;
            while (!st.empty() && (prec(c) < prec(st.top()) || (!rightAss && prec(c) == prec(st.top()))))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

string convertPrefixToInfix(string &prefix)
{
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isalnum(prefix[i]))
        {
            st.push(string(1, prefix[i]));
        }
        else
        {
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            st.push('(' + first + prefix[i] + second + ')');
        }
    }
    string res = st.top();
    st.pop();
    return res;
}

string convertPrefixToPostfix(string &prefix)
{
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isalnum(prefix[i]))
        {
            st.push(string(1, prefix[i]));
        }
        else
        {
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            st.push(first + second + prefix[i]);
        }
    }
    string res = st.top();
    st.pop();
    return res;
}

string convertPostfixToPrefix(string &postfix)
{
    stack<string> st;
    for (char &c : postfix)
    {
        if (isalnum(c))
            st.push(string(1, c));
        else
        {
            string second = st.top();
            st.pop();
            string first = st.top();
            st.pop();
            st.push(c + first + second);
        }
    }
    string res = st.top();
    st.pop();
    return res;
}

string convertPostfixToInfix(string &postfix)
{
    stack<string> st;
    for (char &c : postfix)
    {
        if (isalnum(c))
            st.push(string(1, c));
        else
        {
            string second = st.top();
            st.pop();
            string first = st.top();
            st.pop();
            st.push('(' + first + c + second + ')');
        }
    }
    return st.top();
}

string convertInfixToPrefix(string &infix)
{
    reverse(infix.begin(), infix.end());
    for (char &c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    string res = convertInfixToPostfix(infix);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string infix, prefix, postfix;
    getline(cin, infix);
    cout << convertInfixToPostfix(infix) << endl;
    cout << "-----------------------" << endl;

    getline(cin, prefix);
    cout << convertPrefixToInfix(prefix) << endl;
    cout << "-----------------------" << endl;

    cout << convertPrefixToPostfix(prefix) << endl;
    cout << "-----------------------" << endl;

    getline(cin, postfix);
    cout << convertPostfixToPrefix(postfix) << endl;
    cout << "-----------------------" << endl;

    cout << convertPostfixToInfix(postfix) << endl;
    cout << "-----------------------" << endl;

    getline(cin, infix);
    cout << convertInfixToPrefix(infix) << endl;
    cout << "-----------------------" << endl;

    return 0;
}