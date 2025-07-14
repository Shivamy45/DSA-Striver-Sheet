#include <iostream>
using namespace std;

void print1(int n)
{
    /*
     * * * *
     * * * *
     * * * *
     * * * *
     */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print2(int n)
{
    /*
     *
     * *
     * * *
     * * * *
     */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print3(int n)
{
    /*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n)
{
    /*
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
    */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n)
{
    /*
     * * *
     * *
     *
     */

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void print6(int n)
{
    /*
     1 2 3 4
     1 2 3
     1 2
     1
     */

    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void print7(int n)
{
    //   *
    //  ***
    // *****
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= 2 * i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n)
{
    // *****
    //  ***
    //   *
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= 2 * i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print9(int n)
{
    //   *
    //  ***
    // *****
    //  ***
    //   *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= 2 * i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= 2 * i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void print10(int n)
{
    //  *
    //  **
    //  ***
    //  **
    //  *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print11(int n)
{
    //  1
    //  01
    //  0101
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if ((j + i) % 2)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void print12(int n)
{
    // 1         1
    // 1 2     2 1
    // 1 2 3 3 2 1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        for (int j = 2 * (n - i); j > 0; j--)
            cout << "  ";
        for (int j = i; j > 0; j--)
            cout << j << " ";
        cout << endl;
    }
}

void print13(int n)
{
    // 1
    // 2 3
    // 4 5 6
    int a = 1;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j < i; j++)
            cout << a++ << " ";
        cout << endl;
    }
}

void print14(int n)
{
    // A
    // A B
    // A B C
    for (int i = 0; i < n; i++)
    {
        int letterToPrint = 65;
        for (int j = 0; j <= i; j++)
        {
            cout << (char)letterToPrint++ << " ";
        }
        cout << endl;
    }
}

void print15(int n)
{
    // A B C
    // A B
    // A
    for (int i = n - 1; i >= 0; i--)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print16(int n)
{
    // A
    // B B
    // C C C
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << (char)('A' + i) << " ";
        cout << endl;
    }
}

void print17(int n)
{
    //       A
    //     A B A
    //   A B C B A
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << "  ";
        for (char j = 'A'; j < 'A' + i; j++)
            cout << j << " ";
        for (char j = 'A' + i - 2; j >= 'A'; j--)
            cout << j << " ";
        for (int j = 0; j < n - i; j++)
            cout << "  ";
        cout << endl;
    }
}

void print18(int n)
{
    // C
    // C B
    // C B A
    for (int i = n; i > 0; i--)
    {
        for (char j = 'A' + n - 1; j >= 'A' + i - 1; j--)
            cout << j << ' ';
        cout << endl;
    }
}

void print19(int n)
{
    // * * * * * *
    // * *     * *
    // *         *
    // *         *
    // * *     * *
    // * * * * * *
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "* ";
        for (int j = 0; j / 2 < n - i; j++)
            cout << "  ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "* ";
        for (int j = 0; j / 2 < n - i; j++)
            cout << "  ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
}

void print20(int n)
{
    // *         *
    // * *     * *
    // * * * * * *
    // * *     * *
    // *         *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "* ";
        for (int j = 0; j / 2 < n - i - 1; j++)
            cout << "  ";
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "* ";
        for (int j = 0; j / 2 < n - i; j++)
            cout << "  ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
}

void print21(int n)
{
    // ***
    // * *
    // ***
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void print22(int n)
{
    // 33333
    // 32223
    // 32123
    // 32223
    // 33333
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << n - min(min(i, j), min(2 * n - i, 2 * n - j) - 2);
        }
        cout << endl;
    } 
}

int main()
{
    //? Printing Patterns
    int n;
    cin >> n;
    // print1(n);
    // print2(n);
    // print3(n);
    // print4(n);
    // print5(n);
    // print6(n);
    // print7(n);
    // print8(n);
    // print9(n);
    // print10(n);
    // print11(n);
    // print12(n);
    // print13(n);
    // print14(n);
    // print15(n);
    // print16(n);
    // print17(n);
    // print18(n);
    // print19(n);
    // print20(n);
    // print21(n);
    print22(n);

    return 0;
}
