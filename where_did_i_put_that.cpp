#include <iostream>
#include <cstring>
using namespace std;

int letter_finder(const string& input, char find, bool case_sensitive) {
    if (!case_sensitive) {
        find = tolower(find);
    }

    for (int i = 0; i < input.length(); i++) {
        if (case_sensitive && input[i] == find) {
            return i;
        }
        if (!case_sensitive && tolower(input[i]) == find) {
            return i;
        }
    }
    return -1;
}

int letter_finder(const string& input, const string& find, bool case_sensitive) {
    int input_length = input.length();
    int find_length = find.length();
    
    for (int i = 0; i <= input_length - find_length; i++) {
        bool match = true;
        for (int j = 0; j < find_length; j++) {
            char input_char = input[i + j];
            char find_char = find[j];
            
            if (!case_sensitive) {
                input_char = tolower(input_char);
                find_char = tolower(find_char);
            }
            
            if (input_char != find_char) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

int main() {
    string input; 
    string find;
    char case_sensitive;

    cout << "What's your input?: ";
    getline(cin, input);
    
    cout << "Find (character or substring): ";
    getline(cin, find);
    
    cout << "Do you want the search to be case-sensitive? (Y)es or (N)o: ";
    cin >> case_sensitive;
    
    bool search_sensitive = (case_sensitive == 'Y' || case_sensitive == 'y');

    if (find.length() == 1) {
        int result = letter_finder(input, find[0], search_sensitive);
        if (result != -1) {
            cout << "Character found at index: " << result << endl;
        } else {
            cout << "Character not found." << endl;
        }
    } 
    else {
        int result = letter_finder(input, find, search_sensitive);
        if (result != -1) {
            cout << "Substring found at index: " << result << endl;
        } else {
            cout << "Substring not found." << endl;
        }
    }

    return 0;
}
