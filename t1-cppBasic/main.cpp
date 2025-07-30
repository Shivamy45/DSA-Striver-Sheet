// #include <iostream>
// using namespace std;

// int sum(int num1, int num2)
// {
//     return num1 + num2;
// }

// //*  Pass by Value
// // void doSomethingByValue(int num){
// //     cout << num << endl;
// //     num += 5;
// //     cout << num << endl;
// //     num += 5;
// //     cout << num << endl;
// // }

// //*  Pass by Refrence
// void doSomethingByRef(int &num){
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
// }

// void takeArray(int arr[], int n){
//     arr[0] += 100;
//     cout << "Value inside array: " << arr[0] << endl;
// }

// int main()
// {
//     // int x;     //* declaration
//     // cin >> x;  //* input
//     // cout << x; //* output

//     //? If Else Statement
//     // if (x > 18)
//     // {
//     //     cout << "Greater that 18";
//     // }
//     // else if (x > 60)
//     // {
//     //     cout << "Retirement time!!";
//     // }
//     // else
//     // {
//     //     cout << "Not eligible";
//     // }

//     //? Switch Statement
//     // int day;
//     // cin >> day;
//     // switch (day)
//     // {
//     // case 1:
//     //     cout << "Monday";
//     //     break;
//     // case 2:
//     //     cout << "Tuesday";
//     //     break;
//     // case 3:
//     //     cout << "Wednesday";
//     //     break;
//     // case 4:
//     //     cout << "Thrusday";
//     //     break;
//     // case 5:
//     //     cout << "Friday";
//     //     break;
//     // case 6:
//     //     cout << "Saturday";
//     //     break;
//     // case 7:
//     //     cout << "Sunday";
//     //     break;

//     // default:
//     //     cout << "Break called";
//     //     break;
//     // }

//     //? Array

//     //* 1D array
//     // int arr[5] = {1, 2, 3, 4, 5};
//     // cout << arr[3];

//     //* 2D array
//     // int arr[3][5];
//     // arr[1][3] = 5;
//     // cout << arr[1][3] << endl;
//     // cout << arr[2][3];

//     //? Strings
//     // string s;
//     // cin >> s; // takes only first word
//     //! getline is used to take a line input
//     // getline(cin, s);
//     // cout << "This is the string: \"" << s << "\"";

//     //? For loop
//     // for (int i = 0; i < 5; i++)
//     // {
//     //     cout << i << " ";
//     // }

//     //? While loop
//     // int i = 0;
//     // while (i <= 6)
//     // {
//     //     cout << i << " ";
//     //     i++;
//     // }

//     //? Do While loop
//     // int i = 0;
//     // do
//     // {
//     //     cout << i << " ";
//     //     i++;
//     // } while (i <= 6);

//     //? Functions
//     /*
//      * Void
//      * Return
//      * Parameter
//      * No Parameter
//      */

//     // Take two numbers and print sum
//     // int a, b;
//     // cin >> a >> b;
//     // cout << sum(a, b) << endl;
//     // cout << min(a, b) << endl; // inbuile function in math.h
//     // cout << max(a, b) << endl; // inbuile function in math.h

//     // int x = 10;
//     // doSomethingByValue(x);
//     // doSomethingByRef(x);
//     // cout << x << endl;

//     //! Array goes by refrence
//     // int n = 5;
//     // int arr[n];
//     // for (int i = 0; i < n; i++)
//     // {
//     //     cin >> arr[i];
//     // }
//     // takeArray(arr, n);
//     // cout << "Value inside array: " << arr[0] << endl;

//     int x;
//     cin >> x;
//     cout << x;

//     return 0;
// }

#include <iostream>
using namespace std;

// Recursive function to return nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i);
        if (i != n - 1)
            cout << " ";
    }

    return 0;
}