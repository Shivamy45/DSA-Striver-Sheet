#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, maximum = 0;
    cin >> n;

    //? Integer hashing using vector - O(n)
    //* INTEGER HASHING
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maximum = max(maximum, arr[i]);
    }
    vector<int> hash(maximum + 1, 0);
    for (int i : arr)
        hash[i]++;

    int queries;
    cin >> queries;
    while (queries--)
    {
        int x;
        cin >> x;
        cout << x << " -> " << hash[x] << endl;
    }

    cout << "------------------" << endl;

    //? Character hashing using ASCII array - O(n)
    //* CHARACTER HASHING
    string s;
    cin.ignore();
    getline(cin, s);

    // lowercase chars only
    // int smallCharsHash[26] = {0};
    // for (char i : s)
    //     smallCharsHash[i - 'a']++;

    // int charQueries;
    // cin >> charQueries;
    // while (charQueries--)
    // {
    //     char c;
    //     cin >> c;
    //     cout << c << " --> " << smallCharsHash[c - 'a'] << endl;
    // }

    //? Character hashing using ASCII array - O(n)
    //* all chars
    int charhash[256] = {0};
    for (char i : s)
        charhash[i]++;

    int charQueries;
    cin >> charQueries;
    cin.ignore();
    //! Caution - Use this code for multi line input
    // while (charQueries--)
    // {
    //     char c;
    //     cin.get(c);
    //     cin.ignore(); //! Without this line only single line input
    //     cout << c << " --> " << charhash[c] << endl;
    // }
    //? This method can be used for both single/multi line input
    while (charQueries--)
    {
        char c;
        do
        {
            c = cin.get(); // reads even spaces/newlines
        } while (c == '\n'); // skip empty lines
        cout << (c == ' ' ? "' '" : string(1, c)) << " --> " << charhash[c] << endl;
    }

    cout << "------------------" << endl;

    //? Hashing using unordered_map - O(n)
    //* Using Map STL
    int m;
    cin >> m;
    vector<int> bigArr(m);
    for (int i = 0; i < m; i++)
        cin >> bigArr[i];

    // map<int, int> mpp;
    unordered_map<int, int> mpp;
    for (int i : bigArr)
        mpp[i]++;

    for(auto itr : mpp)
        cout << itr.first << " : " << itr.second << endl;
    int bigQueries;
    cin >> bigQueries;
    while (bigQueries--)
    {
        int x;
        cin >> x;
        cout << x << " ---> " << mpp[x] << endl;
    }

    return 0;
}