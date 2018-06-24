#include <iostream>
using namespace std;

//0 1 1 2 3 5 8 13 21 34 55 89
//2^n
int fibanocci(int n){
    if(n == 0 || n == 1)
        return n;
    return fibanocci(n-1)+ fibanocci(n-2);
}

// O(N)
int fibanocci_dp(int n){
    if(n == 0 || n == 1)
        return n;
    int T[n+1];
    T[0] = 0;
    T[1] = 1;
    for(int i=2;i<=n;i++){
        T[i] = T[i-1] + T[i-2];
    }
    return T[n];
}
int main()
{
    //cout << "Fib " << fibanocci(255) << endl;
    cout << "Fib-DP" << fibanocci_dp(255) << endl;
}
