#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int flag_l = 0;
    int flag_u = 0;

    for(char i : s) {
        if(islower(i)) {
            flag_l |= (1 << (i - 'a'));
        } else if(isupper(i)) {
            flag_u |= (1 << (i - 'A'));
        }
    }

    // Combine both masks to check case-insensitive pangram
    if(((flag_l | flag_u) == (1 << 26) - 1)) {
        cout << "The given string is a pangram.";
    } else {
        cout << "The given string is not a pangram.";
    }

    return 0;
}
