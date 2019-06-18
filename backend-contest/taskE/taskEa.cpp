#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

typedef list<char>::iterator It;

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

bool decode(list<char>& l, It& it) {

    if (*it == 'o' && next(it, 1) != l.end() && next(it, 2) != l.end() && next(it, 3) != l.end() ) {

        char X = *next(it,1);
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

    list<It> iterators;

    for (auto it = l.begin(); it != l.end(); ++it) {
        if (*it == 'o') {
            iterators.push_back(it);
        }
    }




    while (!iterators.empty()) {

  //      cout << "S:  " <<  string(l.begin(), l.end()) << endl;
 //       cout << "l = " << iterators.size() << endl;

        bool decoded = false;

        for (auto it = iterators.begin(); it != iterators.end(); ) {


            if (decode(l, *it) ) {


                decoded = true;

                if (**it != 'o') {

                  //  cout << "not o" << endl;

                    auto p_it = *it;  

            //        cout << "+" << *p_it << endl;  

                    for (int i = 0; i < 3; ++i) {

                        if ( p_it != l.begin() ) {

                            p_it = prev(p_it);

                            if (*p_it == 'o') {

                                if (it == iterators.begin() ||  *prev(it) != p_it ) {

                                    iterators.insert(it, p_it);
                                } 
                                break;

                            }

                        }
                        else {
                            break;
                        } 

                        
                    }  



                      ++it;  
                      iterators.erase(prev(it));

                }
                else {
                    ++it;
                }






            }
            else {
                ++it;
                iterators.erase(prev(it));
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