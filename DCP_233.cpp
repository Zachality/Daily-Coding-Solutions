//Implement the function fib(n), 
//which returns the nth number in the Fibonacci sequence, 
//using only O(1) space.

#include <iostream>
// #include <assert>

int Fib(int n){
    if(n <= 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    int F = 0;
    int S = 1;
    int C;
    int iter = 0;
    while(iter < n){
        C = F + S;
        S = F;
        F = C; 
        ++iter;
    }
    return C;
}

int main(){
    std::cout << Fib (10) << "     ";
}