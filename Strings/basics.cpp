#include<iostream>
#include <algorithm>
using namespace std;

int main() {

    char ch = 'A';
    //Character can store a single character
    //Strings can store a sequence of characters
    string str = "Hello world";
    string str1 = "These are strings";

    cout<<str<<" "<<str1<<endl;

    //Taking input
    string input;
    getline(cin, input); //getline used for strings having spaces  
    cout<<input;

    //Reverse string
    reverse(str.begin(), str.end());
    cout<<str;

    //str.substring(starting index pos, length);
    //No length will print entire string for start

    //Append a character
    string s1 = "abc";
    s1.push_back('d');
    //s1 becomes "abcd"

    int n = 12;
    string x = to_string(n);
    //x is "12", can do operations like strings

    //Strings are mutable in cpp
    string x = "care";
    swap(x[0], x[2]);
    //x becomes race
    return 0;
}