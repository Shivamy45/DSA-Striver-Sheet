#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator> // for std::inserter

using namespace std;

void vector_example()
{
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.insert(v.begin() + 1, 10);
    v.pop_back();
    sort(v.begin(), v.end());
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void set_example()
{
    set<int> s = {3, 1, 4};
    s.insert(2);
    s.erase(3);
    cout << (s.count(1) ? "Found\n" : "Not Found\n");
    for (int x : s)
        cout << x << " ";
    cout << endl;
}

void unordered_set_example()
{
    unordered_set<int> us = {1, 2, 3};
    us.insert(4);
    us.erase(2);
    cout << (us.count(3) ? "Found\n" : "Not Found\n");
    for (int x : us)
        cout << x << " ";
    cout << endl;
}

void multiset_example()
{
    multiset<int> ms = {1, 2, 2, 3};
    ms.insert(2);
    ms.erase(ms.find(2));
    for (int x : ms)
        cout << x << " ";
    cout << endl;
}

void unordered_multiset_example()
{
    unordered_multiset<int> ums = {1, 2, 2};
    ums.insert(2);
    ums.erase(ums.find(2));
    for (int x : ums)
        cout << x << " ";
    cout << endl;
}

void map_example()
{
    map<string, int> m;
    m["apple"] = 2;
    m["banana"] = 5;
    m.erase("apple");
    cout << m["banana"] << endl;
    for (auto &p : m)
        cout << p.first << " => " << p.second << endl;
}

void unordered_map_example()
{
    unordered_map<string, int> um;
    um["car"] = 10;
    um["bike"] = 5;
    um.erase("bike");
    for (auto &p : um)
        cout << p.first << " => " << p.second << endl;
}

void multimap_example()
{
    multimap<int, string> mm;
    mm.insert({1, "one"});
    mm.insert({1, "uno"});
    for (auto &p : mm)
        cout << p.first << " => " << p.second << endl;
}

void unordered_multimap_example()
{
    unordered_multimap<int, string> umm;
    umm.insert({1, "one"});
    umm.insert({1, "uno"});
    for (auto &p : umm)
        cout << p.first << " => " << p.second << endl;
}

void queue_example()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
}

void stack_example()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}

void deque_example()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.pop_back();
    for (int x : d)
        cout << x << " ";
    cout << endl;
}

void priority_queue_example()
{
    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void list_example()
{
    list<int> l = {1, 2, 3};
    l.push_back(4);
    l.push_front(0);
    l.remove(2);
    for (int x : l)
        cout << x << " ";
    cout << endl;
}

void next_permutation_example()
{
    vector<int> v = {1, 2, 3};
    do
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

void builtin_popcount_example()
{
    int x = 29; // 11101 in binary
    cout << __builtin_popcount(x) << endl;
}

void sort_example()
{
    vector<int> v = {3, 1, 4, 2};
    sort(v.begin(), v.end());
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void min_element_example()
{
    vector<int> v = {4, 1, 6};
    cout << *min_element(v.begin(), v.end()) << endl;
}

void max_element_example()
{
    vector<int> v = {4, 1, 6};
    cout << *max_element(v.begin(), v.end()) << endl;
}

int main()
{
    vector_example();
    set_example();
    unordered_set_example();
    multiset_example();
    unordered_multiset_example();
    map_example();
    unordered_map_example();
    multimap_example();
    unordered_multimap_example();
    queue_example();
    stack_example();
    deque_example();
    priority_queue_example();
    list_example();
    next_permutation_example();
    builtin_popcount_example();
    sort_example();
    min_element_example();
    max_element_example();
    return 0;
}