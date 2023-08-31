#include <iostream>
#include <string>
using namespace std;

void swapNumRef(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}

int fact(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int combination(int n, int k){
    return (fact(n) / (fact(k) * fact(n-k)));
}


int main(){
    int a = 5, b = 2;

    //swapNumRef(a, b);
    //cout << a << " " << b << endl;
    cout << combination(a, b);
    return 0;
}

