#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;
void Divisor(int largestNumber,  int smallestNumber){
    while (smallestNumber != 0) {
        int remainder = largestNumber% smallestNumber;
        largestNumber = smallestNumber;
        smallestNumber = remainder;
    }
    cout<<"The gcd is "<<largestNumber<<endl;
}

int main() {
    int largestNumber, smallestNumber;
    cout<<"Enter two numbers(the largest first)"<<endl;
    cin>>largestNumber;
    cout<<"Enter another number(the smallest )"<<endl;
    cin>>smallestNumber;
    Divisor(largestNumber, smallestNumber);

    return 0;
}