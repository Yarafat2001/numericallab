#include <bits/stdc++.h>

using namespace std;


int main()
{
    int i, j, k, n,col;
    float A[20][20], c, x[10], sum = 0.0;
    
    cout << "Enter the order of matrix: ";
    cin >> n>>col;
    
    cout << "\nEnter the elements of augmented matrix row-wise:\n\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <col; j++)
        {
            cin >> A[i][j];
        }
    }
    
    for (j = 0; j < col; j++) /* loop for the generation of upper triangular matrix */
    {
        for (i = 0; i < n; i++)
        {
            if (i > j)
            {
                c = A[i][j] / A[j][j];
                for (k = 0; k <= n; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
    /* this loop is for backward substitution */
    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }
    
    cout << "\nThe solution is:\n";
    for (i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << "\t"; /* x1, x2, x3 are the required solutions */
    }
    cout<<"\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <col; j++)
        {
            cout<< A[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
    cout <<endl;
    
    return 0;
}
