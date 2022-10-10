#include<iostream>
using namespace std ;

/*

int gcd(int a, int b){
    int min = a<b ? a : b; 
    while(min > 0){
        
        if (a%min == 0 && b%min == 0) return min;
        min--;
    }
    return 0;
}



*/

/* EUCLIDIAN ALGORITHM 

it says that 
if b<a
then
gcd(a,b) == acd (a-b,b)

*/

/*

int gcd(int a, int b){
    while (a!=b){
        a>b ? a = a-b : b = b-a; 
    }
    return a;
}

*/

/* optimized version */

int gcd(int a, int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    return 0;
}

