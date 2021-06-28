#include <iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
void sen_to_word(string s);

template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &elem: vec)
        std::cout << elem << ", ";
    std::cout <<  "]"<< std::endl;
}

template <typename T1, typename T2>
void display_map(const std::map<T1, T2> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]  " << std::endl;
}

void sen_to_word(string s){
    map <string,int> word_count {};
    vector <string> vec{};
    string word="";
    

    for(auto i : s){
        if(i == ' '){
            vec.push_back(word);
            word = "";
        }
        else{
            word = word + i;
        }
    }
    vec.push_back(word);
    // display(vec);
    set <string> st(vec.begin(),vec.end());
    for (auto i:st){
        word_count.insert({i,count(vec.begin(),vec.end(),i)});
    }
    display_map(word_count);
    
    
}



int main()
{
    string s{"two things are infinite the universe and the human stupidity"};
    sen_to_word(s);
}