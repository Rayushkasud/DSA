#include <iostream>
using namespace std;
void pattern3(int n)
{
    int num = 1, row;
    for (int rows = 1; rows <= 2 * n; rows++)
    {
        if (rows > n)
        {
            row = ((2 * n - rows));
        }
        else
        {
            row = rows;
        }
        for (int cols = 1; cols <= row; cols++)
        {
            cout << num << " ";
            if (row < n)
            {
                num++;
            }
            else 
            {
                num--;
            }
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    int numSpaces, row;
    for (int i = 0; i <= 2 * n - 1; i++)
    {

        if (i >= n)
        {
            row = ((2 * n - i) - 1);
        }
        else
        {
            row = i;
        }
        numSpaces = n - row;
        // int row = row >= n ? ((2 * n - i) - 1) : rows;
        for (int s = 0; s < numSpaces; s++)
        {
            cout << " ";
        }
        for (int j = 0; j <= row; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}
void pattern1(int n)
{
    // int number = 3;
    int r = 0;
    for (int rows = 0; rows <= 2 * n; rows++)
    {
        int col;
        int number = 2;
        if (rows >= n)
        {
            col = n - (rows - n);
        }
        else
        {
            col = rows;
        }
        for (int cols = 0; cols < col; cols++)
        {
            if (rows > n)
            {
                r = number + 1 + (2 * n - (rows + 1));
            }
            else
            {
                r = number + rows;
            }
            cout << r << " ";
        }
        // if (rows > n)
        // {
        //     number+rows;
        // }

        // else
        // {
        //     number++;
        // }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "enter n";
    cin >> n;
    pattern3(n);
}