#include <bits/stdc++.h>
using namespace std;

int main() {
   int i, j, k, n,c;
   double a[10][10], b, x[10];

   cout << "Enter the size of matrix: ";
   cin >> n>>c;
   cout << "\nEnter the elements of augmented matrix (rowwise):\n";
   for (i = 0; i < n; i++) {
      for (j = 0; j <c; j++) {
         cin >> a[i][j];
      }
   }

   // To find the elements of the diagonal matrix
   for (j = 0; j < n; j++) {
      for (i = 0; i < c; i++) {
         if (i != j) {
            b = a[i][j] / a[j][j];
            for (k = 0; k <= n; k++) {
               a[i][k] = a[i][k] - b * a[j][k];
            }
         }
      }
   }

   cout << "\nThe solution is:\n";
   for (i = 0; i < n; i++) {
      x[i] = a[i][n] / a[i][i];
      cout << "x" << i + 1 << " = " << x[i] << " ";
   }

   cout<<"\n";
   for (i = 0; i < n; i++) {
      for (j = 0; j <c; j++) {
         
         cout<< a[i][j]<<"\t";
      }
      cout<<"\n";
   }

   return 0;
}
