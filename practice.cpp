#include <bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x * x - 3*x + 2;  // Example function: f(x) = x^2 - 3*x + 2
}

double derivative(double x)
{
    return 2*x - 3;  // Example derivative: f'(x) = 2x - 3
}

double newtonRaphson(double x0, double epsilon, int maxIterations)
{
    double x = x0;
    int iteration = 0;
    
    while (iteration < maxIterations)
    {
        double fx = func(x);
        double dx = derivative(x);
        
        if (abs(dx) < epsilon)
        {
            cout << "Derivative is too small. Newton-Raphson method failed." << endl;
            return numeric_limits<double>::quiet_NaN();
        }
        
        double x1 = x - (fx / dx);
        
        if (abs(x1 - x) < epsilon)
        {
            cout << "Converged to root after " << iteration << " iterations." << endl;
            return x1;
        }
        
        x = x1;
        iteration++;
    }
    
    cout << "Exceeded maximum iterations. Newton-Raphson method failed to converge." << endl;
    return numeric_limits<double>::quiet_NaN();
}

int main()
{
    double x0 = 0;  // Initial guess
    double epsilon = 1e-6;  // Tolerance for convergence
    int maxIterations = 100;  // Maximum number of iterations
    
    double root = newtonRaphson(x0, epsilon, maxIterations);
    
    if (!isnan(root))
    {
        cout << "Root: " << root << endl;
        cout << "f(Root): " << func(root) << endl;
    }
    
    return 0;
}
