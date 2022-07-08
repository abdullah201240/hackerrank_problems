// C++ program to find new after swapping
// characters at position i and i + c
// b times, each time advancing one
// position ahead
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

string rotateLeft(string s, int p)
{

    // Rotating a string p times left is
    // effectively cutting the first p
    // characters and placing them at the end
    return s.substr(p) + s.substr(0, p);
}

// Method to find the required string
string swapChars(string s, int c, int b)
{

    // Get string length
    int n = s.size();

    // If c is larger or equal to the length of
    // the string is effectively the remainder of
    // c divided by the length of the string
    c = c % n;

    if (c == 0)
    {

        // No change will happen
        return s;
    }
    int f = b / n;
    int r = b % n;

    // Rotate first c characters by (n % c)
    // places f times
    string p1 = rotateLeft(s.substr(0, c),
                  ((n % c) * f) % c);

    // Rotate remaining character by
    // (n * f) places
    string p2 = rotateLeft(s.substr(c),
                  ((c * f) % (n - c)));

    // Concatenate the two parts and convert the
    // resultant string formed after f full
    // iterations to a string array
    // (for final swaps)
    string a = p1 + p2;

    // Remaining swaps
    for(int i = 0; i < r; i++)
    {

        // Swap ith character with
        // (i + c)th character
        char temp = a[i];
        a[i] = a[(i + c) % n];
        a[(i + c) % n] = temp;
    }

    // Return final string
    return a;
}
string revers(string s)
{
    string b=s;
    reverse(b.begin(), b.end());
    //cout<<"\n"<<b;
return b;
}
int factorial(int n) {
  if(n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}
// Driver code
int main()
{

    // Given values
    string s1;
    cin>>s1;

    int a=s1.length();
    int b = 0,sum=0;
    int c = 0;
 a= factorial(a);

    // Get final string print final string
    for(int i=0;i<a;i++){
        string n=swapChars(s1, c, b);
        if(n==revers(n)){
            sum++;
        }
        b++;
        c++;
    }
    cout<<sum<<endl;


}

// This code is contributed by rag2127
