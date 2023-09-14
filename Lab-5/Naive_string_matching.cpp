#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string text, pattern;
    cout << "Enter the text in which yo want to search: ";
    getline(cin >> ws, text);
    cout << "Enter the pattern: ";
    cin >> pattern;
    
    // cout << endl << text << pattern << endl;
    
    int length = text.length();
    int length2 = pattern.length();
    
    vector <int> matchIndex;
    for(int i = 0; i < length - length2; i++){
        string str = text.substr(i, length2);
        
        if(str == pattern){
            matchIndex.push_back(i);
        }
    }
    cout << endl;
    for(auto i : matchIndex){
        cout << i << " ";
    }

    return 0;
}
