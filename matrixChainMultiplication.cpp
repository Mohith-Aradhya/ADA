#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int MCM(int *dimensionMatrix, int num)
{

    int matrix[num][num];

    for (int i = 0; i < num; i++)
    {
        matrix[i][i] = 0;
    }

    for (int l = 2; l < num; l++)
    {
        for (int i = 0; i < num - l + 1; i++)
        {

            int j = i + l - 1;
            matrix[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + dimensionMatrix[i - 1] * dimensionMatrix[k] * dimensionMatrix[j]);
            }
        }
    }

    return matrix[1][num - 1];
}

int main()
{
    int num, row, col;

    cout << "\nEnter number of matrices: ";
    cin >> num;

    int *dimensionMatrix = new int[num];
    int j = 0;

    cout << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the dimensions of Matrix " << i + 1 << ": ";
        cin >> row >> col;

        if (i == 0)
        {
            dimensionMatrix[j++] = row;
            dimensionMatrix[j++] = col;
        }
        else
        {
            if (dimensionMatrix[j - 1] == row)
            {
                dimensionMatrix[j++] = col;
            }
            else
            {
                cout << "\nMatrix multiplication not possible";
            }
        }
    }

    cout << "\nDimensions taken are: ";
    for (int i = 0; i <= num; i++)
    {
        cout << dimensionMatrix[i] << " ";
    }

    cout << "\nMinimum number of multiplications required is: " << MCM(dimensionMatrix, j) << endl;

    return 0;
}
