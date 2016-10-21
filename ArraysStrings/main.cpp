//
//  main.cpp
//  ArraysStrings
//  CTCI Ch1

#include <iostream>
#include <string>
#include <cmath>


using namespace std;

// Question 1
bool isUnique(string input){
    // Assume ASCII character set
    int letters[256] = {0};

    // Check if size of array > possible chars
    size_t length = input.length();
    if (length > 256) return false;

    for(int i=0; i<length; ++i){
        if(letters[input[i]]++ == 1)
            return false;
    }

    return true;
}

// Question 3
string URLify(string str, size_t size){
    // find number of spaces in string
    size_t numSpaces = 0;
    for(int i=0; i<size; ++i){
        if(str[i]==' ') ++numSpaces;
    }

    // set varaibles for shifting array
    --size;
    size_t backIndex = size + 2*numSpaces;

    while(size < backIndex){
        if (str[size]==' ') {
            str[backIndex--] = '0';
            str[backIndex--] = '2';
            str[backIndex--] = '%';
        } else {
            str[backIndex--] = str[size];
        }
        --size;
    }

    return str;
}

// Question 5
//Not 100% correct
bool oneAway(string str1, string str2){
    size_t i=0, j=0;
    bool flag = false;

    while (i < str1.length() && j < str2.length()){
        if (str1[i] == str2[j]) {
            ++i;
            ++j;
        } else if (str1[i] == str2[j+1]){
            if (flag) return false;
            flag = true;
            j += 2;
            ++i;
        } else if (str1[i+1] == str2[j]){
            if (flag) return false;
            flag = true;
            i +=2;
            ++j;
        }
    }
    cout << fabs(i-j) << endl << flag << endl;
    if (fabs(i-j) != 1  && flag) return false;
    return true;

}

int main(int argc, const char * argv[]) {
    cout << "Is there a duplicate in 'this string' " << isUnique("this string") << endl;
    cout << "Test URLify " << URLify("This is a test!      ", 15)<< endl;
    cout << oneAway("abcd","acd");
    return 0;
}
