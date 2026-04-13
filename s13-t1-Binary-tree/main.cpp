#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

TreeNode *createTree(vector<int> &arr)
{
    if (arr.size() < 1 || arr[0] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (arr[i] != -1)
        {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void preInPostOrderTraversal(TreeNode *root)
{
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<TreeNode *, int>> st;
    st.push(make_pair(root, 1));
    while (!st.empty())
    {
        pair<TreeNode *, int> temp = st.top();
        st.pop();
        if (temp.second == 1)
        {
            preOrder.push_back(temp.first->data);
            temp.second = 2;
            st.push(temp);
            if (temp.first->left)
                st.push(make_pair(temp.first->left, 1));
        }
        else if (temp.second == 2)
        {
            inOrder.push_back(temp.first->data);
            temp.second = 3;
            st.push(temp);
            if (temp.first->right)
                st.push(make_pair(temp.first->right, 1));
        }
        else
        {
            postOrder.push_back(temp.first->data);
        }
    }
    for (int a : preOrder)
        cout << a << " ";
    cout << endl;
    for (int a : inOrder)
        cout << a << " ";
    cout << endl;
    for (int a : postOrder)
        cout << a << " ";
    cout << endl;
}

void helperpreorderTraversalUsingRecursion(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    res.push_back(root->data);
    helperpreorderTraversalUsingRecursion(root->left, res);
    helperpreorderTraversalUsingRecursion(root->right, res);
}
// using recursion
vector<int> preorderTraversalUsingRecursion(TreeNode *root)
{
    vector<int> res;
    helperpreorderTraversalUsingRecursion(root, res);
    return res;
}

void inorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
vector<int> inorderTraversalUsingRecursion(TreeNode *root)
{
    vector<int> res;
    inorder(root, res);
    return res;
}

void helper(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    helper(root->left, res);
    helper(root->right, res);
    res.push_back(root->data);
}
vector<int> postorderTraversalUsingRecursion(TreeNode *root)
{
    vector<int> res;
    helper(root, res);
    return res;
}

void helper(TreeNode *root, vector<vector<int>> &res, int lvl)
{
    if (!root)
        return;
    if (lvl >= res.size())
        res.push_back({root->data});
    else
        res[lvl].push_back(root->data);
    helper(root->left, res, lvl + 1);
    helper(root->right, res, lvl + 1);
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    helper(root, res, 0);
    return res;
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        res.push_back(curr->data);
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
    return res;
}

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> res;
    TreeNode *node = root;
    while (!st.empty() || node != nullptr)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            node = st.top();
            st.pop();
            res.push_back(node->data);
            node = node->right;
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    TreeNode *curr = root;
    st1.push(root);
    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        curr = st2.top();
        st2.pop();
        res.push_back(curr->data);
    }
    return res;
}

vector<int> postorderTraversal2(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    TreeNode *curr = root;
    st1.push(root);
    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        curr = st2.top();
        st2.pop();
        res.push_back(curr->data);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    TreeNode *root = createTree(arr);
    preInPostOrderTraversal(root);
    cout << "-------------------" << endl;
    vector<int> res = preorderTraversalUsingRecursion(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;
    res = inorderTraversalUsingRecursion(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;
    res = postorderTraversalUsingRecursion(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;
    vector<vector<int>> lvl = levelOrder(root);
    for (auto it : lvl)
    {
        for (int a : it)
            cout << a << " ";
        cout << endl;
    }
    cout << "-------------------" << endl;
    res = preorderTraversal(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;
    res = inorderTraversal(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;
    res = postorderTraversal(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;
    res = postorderTraversal2(root);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;

    return 0;
}