#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(const string &binary)
{
    int decimal = 0;
    int power = 1; // Initialize 2^0

    // Start from the rightmost (least significant) digit of the binary number
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += power;
        }
        power *= 2; // Multiply by 2 for each position to the left
    }

    return decimal;
}

//actually remember in binary the number which is having 1 at the end is the odd number 
//and the number which has maximum 1s at the start is the smallest 
string maximumOddBinaryNumber(string binaryString)
{
    string ans = "";
    //as we will be adding one extra one at the end that's we are starting count from -1
    int oneCount = -1;
    for(auto i : binaryString){
        if (i == '1')
        {
            oneCount++;
        }
    }
    for (int i = 0; i < binaryString.length() - 1; i++)
    {

        if (oneCount > 0)
        {
            //to make the smallest number we are adding all the 1s at the start
            ans = ans + '1';
            oneCount--;
        }else{
            ans = ans + '0';
        }
    }
    //to make the odd we are adding one number at the end 
    ans = ans + '1';
    return ans;
}

int main()
{
    string s = "0101";
    cout << maximumOddBinaryNumber(s);

    return 0;
}