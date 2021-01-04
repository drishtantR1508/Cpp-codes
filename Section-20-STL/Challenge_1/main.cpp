// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

// template <typename T>
// void display(const deque<T> &vec) {
//     cout << "[ ";
//     for (const auto &elem: vec)
//         cout << elem << " ";
//     cout <<  "]"<<endl;
// }
// string uppercase(string d){
//     auto it = d.begin();
//     while (it != d.end()){
//         if (*it == ' '){
//             d.erase(it);
//         }else{
//             it++;
//         }
//     }
//     transform(d.begin(),d.end(),d.begin(),::toupper);
//     return d;
// }
// bool is_palindrome(string str){
//     //check palindrome
//     int c;
//     for (int i=0;i<str.size()/2;i++){
//         if (str[i] != str[str.size()-i-1]){
//             c = 0;
//             break;
//         }else{
//             c=1;
//         }
//     }
//     return c;
// }
bool is_palindrome(string str){
    deque <char> d;
    for (auto c:str){
        if (isalpha(c)){
            d.push_back(toupper(c));
        }
    }

    // while (d.size() >1){
    //     if (d.front() != d.back()){
    //         d.pop_front();
    //         d.pop_back();
    //         return false;
    //     }
    // }
    // return true;

    // ===============================================================================================================================================//
    // In above logic we can see that if it happens that element at front and back is same then nothing will be popped from either front or back and hence
    // loop size will not change and this will cause infinite while loop occurence as d.size() will always remain greater than 1.
    // Therefore try this logic. 
    // ==============================================================================================================================================//

    char c1,c2;
    while(d.size() > 1) {
        c1 = d.front();
        c2 = d.back();
        d.pop_front();
        d.pop_back();
        if(c1 != c2)
            return false;
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter the string to check if palindrome : ";
    getline(cin,str);
    if (is_palindrome(str)){
        cout<<str<<" is a PALINDROME."<<endl;
    }else{
        cout<<"Not a PALINDROME"<<endl;
    }
    
    
}
