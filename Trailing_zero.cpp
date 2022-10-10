#include<iostream>
using namespace std;

/*

this donot work for slighlty higher values 
*/
/*

int fact(int n){
    if (n == 1 || n == 0) return 1;
    else return n * fact(n-1);
}

int trailing_zero(long int n){
    int count = 0;
    while( n%10 == 0 ){
        n /= 10;
        count++;
        cout << count << endl;
    }
    return count;
}

int main(){
    int n;
    cout << "Enter the number :";
    cin >> n;
    cout << trailing_zero(fact(n)) << endl;
    return 0;
}
*/


/*
###NEW APPROCH###
number of 5 in factorrial is always less then 2 so we need to count number of prime 5 in the multiplication
we also need to factor 25 those have more then 1 prime 5
*/
/*
second attempt

int trialing_zero(int n){
    int count = 0,sp;
    for (int i = 1; i <= n ; i++){
        sp = i;
        while(sp%5 == 0){
            count++;
            sp /= 5;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    cout << trialing_zero(n) << endl;
    return 0;
}

*/


/* ##############CORRECT METHORD######################### */

int trialing_zero(int n){
    int count = 0;
    for (int i = 5; i <= n; i*=5 ) count += n/i;
    return count;
}

int main(){
    int n;
    cin >> n;
    cout << trialing_zero(n) << endl;
    return 0;
}
