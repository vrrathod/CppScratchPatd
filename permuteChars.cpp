#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int counter = 0;


void removeCharacter(string &s, char c) {
    size_t pos = s.find_first_of(c);
    if( string::npos != pos ) {
        s.erase(pos, 1);
    }
}

void Permute_Private(string output, string characters) {
    // cout << ":: " << output << " :: " << characters << " " << endl;
    if( characters == "" ) {
    //    cout << output << endl;
        counter ++;
    } else {
        for(int i = 0; i < characters.length(); i++) {
            output.push_back(characters[i]);

            string newCharacters = characters;
            removeCharacter(newCharacters, characters[i]);

            Permute_Private(output, newCharacters);

            output.pop_back();
        }
    }
}

void Permute(string s) {
    Permute_Private("", s);
}

int main (int argc, char* argv[]) {
    clock_t start = clock();
    Permute("abcdefg");
    clock_t end = clock();
    cout << endl << "Clock ticks = " << end - start << endl;
    cout << "counter = " << counter << endl;
    cout << " per word = " << ((float)end-start) / counter << endl;

    return 0;
}
