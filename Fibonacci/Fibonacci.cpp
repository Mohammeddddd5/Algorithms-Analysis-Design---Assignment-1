#include <iostream>
#include <vector>

using namespace std;

// Fibonacci Formula: F(n) = F(n−1) + F(n−2)

//------------------------------------------------------------------------------------
// 1. Fibonacci using Recursion:

int FibonacciRecursive(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return FibonacciRecursive(n-1) + FibonacciRecursive(n-2);
}

//------------------------------------------------------------------------------------
//2. Fibonacci using Divide & Conquer [Matrix Multiplication]

void MatrixMultiplication(int F[2][2], int M[2][2]){
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void Power(int F[2][2], int n){
    if (n == 0 || n == 1){
        return;
    }
    int M[2][2] = {{1, 1}, {1, 0}};

    Power(F, n / 2);
    MatrixMultiplication(F, F);

    if (n % 2 != 0)
        MatrixMultiplication(F, M);
}

int FibonacciMatrix(int n){
    if (n == 0){
        return 0;
    }
    int F[2][2] = {{1, 1}, {1, 0}};
    Power(F, n - 1);
    return F[0][0];
}
//------------------------------------------------------------------------------------
// 3. Fibonacci series using Dynamic Programming

int FibonacciDynamicProgramming(int n){
    if (n <= 1){
        return n;
    }

    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}

//------------------------------------------------------------------------------------
// Main Program:

void FibonacciRunner(int n){
    cout << "Result using Fibonacci - Recursive Method: " << FibonacciRecursive(n) << endl;
    cout << "Result using Fibonacci - Matrix Multiplication Method: " << FibonacciMatrix(n) << endl;
    cout << "Result using Fibonacci - Dynamic Programming Method: " << FibonacciDynamicProgramming(n) << endl;
}

int main(){
    int answer, n;
    cout << "Welcome to Fibonacci Series Calculator." << endl;
    cout << "---------------------------------------" << endl;
    while(true){
        cout << "1) Run Test Cases\n2) Run Custom Test Cases\n3) Exit" << endl;
        cin >> answer;
        if(answer == 1){
            cout << "---------------------------------------------------------------" << endl;
            for(int i = 0; i < 10; i++){
                cout << "Test Case (n = " << i << ")" << endl;
                FibonacciRunner(i);
                cout << "---------------------------------------------------------------" << endl;
            }
        }
        else if(answer == 2){
            cout << "Enter nth Fibonacci number: ";
            cin >> n;
            FibonacciRunner(n);
        }
        else if(answer == 3){
            break;
        }
        else{
            cout << "Invalid Input" << endl;
        }
    }

}


