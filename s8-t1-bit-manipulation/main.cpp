#include <iostream>
using namespace std;

string decimalToBinary(int num)
{
    string res;
    while (num > 0)
    {
        res = to_string(num % 2) + res;
        num /= 2;
    }
    return res;
}

int binaryToDecimal(string binary)
{
    int val = 1, decimal = 0;
    for (int i = binary.length() - 1; i >= 0; --i)
    {
        if (binary[i] == '1')
            decimal += val;
        val *= 2;
    }
    return decimal;
}

int main()
{
    int num;
    cin >> num;
    cout << decimalToBinary(num) << endl;
    cout << "----------------------------" << endl;

    string binary;
    cin.ignore();
    getline(cin, binary);
    cout << binaryToDecimal(binary) << endl;
    cout << "----------------------------" << endl;

    return 0;
}