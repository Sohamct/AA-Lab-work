// horsepool’s Algo

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void horsePool(string text, string pattern, int n, int m) {
    vector<int> shift(256, m);  // Initialize all characters with pattern length as the default shift value

    // Set the shift values based on the pattern
    for (int i = 0; i < m - 1; i++) {
        shift[pattern[i]] = m - 1 - i;
    }

    vector<int> matchIndex;
    int j = 0;

    while (j <= n - m) {
        int i = m - 1;
        while (i >= 0 && pattern[i] == text[i + j]) {
            i--;
            
            if (i == -1) {
                matchIndex.push_back(j);
                break;
            }
        }

        // Update j based on the shift value of the character in the text
        j += shift[text[j + m - 1]];
    }

    for (auto it : matchIndex) {
        cout << it << " ";
    }
    if(!matchIndex.size()) cout <<"Pattern not found!" << endl;
}

int main() {
    string text, pattern;
    cout << "Enter the text in which you want to search: ";
    getline(cin >> ws, text);
    cout << "Enter the pattern: ";
    cin >> pattern;

    int n = text.length(); 
    int m = pattern.length(); 
    cout << "n: " << n << " m: " << m << endl;
    horsePool(text, pattern, n, m);

    return 0;
}



