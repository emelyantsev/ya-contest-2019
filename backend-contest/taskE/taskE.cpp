#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;


bool is_valid(char c) {

    if ( (c >= '0' && c <= '7') || (c >= 'a' && c <= 'h') || (c >= 'A' && c <= 'H') ) {
        return true;
    }
    else {
        return false;
    }
}


int change(char c) {

    if (c >= '0' && c <= '7') {
        return c - '0';
    } 
    else if (c >= 'a' && c <= 'h') {
        return c - 'a';
    }
    else {
        return c - 'A';
    }
}

bool decode(list<char>& l, list<char>::iterator& it) {

    if (*it == 'o' && next(it) != l.end() && next(it, 2) != l.end() && next(it, 3) != l.end() ) {

        char X = *next(it);
        char Y = *next(it,2);
        char Z = *next(it,3);
    

    if (is_valid(X) && is_valid(Y) && is_valid(Z) ) {

        int s = 64*change(X)+8*change(Y)+change(Z);

        if (s < 256) {

            char c = s;
            it = l.insert(l.erase(it, next(it,4)), c);

      //      cout << X << Y << Z << " --> "  << c << endl;

            return true;
        }

    }

    }


    return false;

}


int main() {

    string s;
    cin >> s;

    list<char> l(s.begin(), s.end());


    int result = 0;

    // cout << "ok" << endl;

    while (true) {

   //     cout << "l " <<  string(l.begin(), l.end()) << endl;

        bool decoded = false;

        for (auto it = l.begin(); it != l.end(); ++it) {


            if (decode(l, it) ) {

                decoded = true;
            }

        }

        


        if (decoded) {
            ++result;
        }
        else {
            break;
        }

    }

    cout << result << endl;

    return 0;
}