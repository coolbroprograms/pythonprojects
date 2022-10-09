// Solution for https://codeforces.com/contest/205/problem/c 

#include<iostream>
#include<array>
using namespace std;

int main(){
    // accept range
    int l,r;
    int count=0, rem, num, index=0;
    array<int, 4> arr;

    cout<<"Enter the range: ";
    cin>>l>>r;

    int i=l;
    int max=r;

    // Iterate until "i" is less than/equal to max (last number of range).
    while(i<=max){
        // store all the digits from the number in an array.
        num=i;
        while(num!=0){
            rem=num%10;
            arr[index]=rem;
            num=num/10;
            index+=1;
        }
        // checks if the last and first digit of the number are equal
        if(arr[0]==arr[index-1]){
            count+=1;
        }
        i+=1;
        index=0;
    }

    // display how many numbers first and last digits are same.
    cout<<count;
    return 0;
}
