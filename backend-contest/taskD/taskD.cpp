#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cassert>

using namespace std;

map<string, string> f_texts;
map<string, set<string>> f_excepts;


set<string> parse_inner(string, stringstream&, set<string>& stoplist);

set<string> parse_function(string f_name, set<string>& stoplist) {

    if (f_excepts.count(f_name) ) {
        return f_excepts.at(f_name);
    }

    stringstream ss(f_texts[f_name]);

    string temp;
    ss >> temp >> temp;

    stoplist.insert(f_name);
    set<string> result = parse_inner(f_name, ss, stoplist);

    return result;
}


set<string> parse_suppress(stringstream& ss) {

    string temp;
    ss >> temp;
    assert(temp == "suppress");

    set<string> result;

    ss >> temp;

    while( temp.back() == ',') {
        result.insert(temp.substr(0, temp.size() - 1));
        ss >> temp;
    }

    result.insert(temp);

    return result;
}


set<string> parse_try(string f_name, stringstream& ss, set<string>& stoplist) {

    set<string> result = parse_inner(f_name, ss, stoplist);

    set<string> suppressed = parse_suppress(ss);

    for (const auto& s: suppressed) {
        result.erase(s);
    }


    return result;
}


set<string> parse_inner(string f_name, stringstream& ss, set<string>& stoplist) {

    string temp;
    int q = 0;

    set<string> result;

    while (ss >> temp) {

        if (temp == "{") {
            ++q;
        }
        else if (temp == "}") {
            --q;
            if (q == 0) {
                return result;
            }
        }
        else if (temp == "maybethrow") {
            
            ss >> temp;
            result.insert(temp);
        }
        else if (temp == "try") {

            set<string> parsed = parse_try(f_name, ss, stoplist);

            for (const auto& e : parsed) {
                result.insert(e);
            } 

        }
        else {

            if (stoplist.count(temp) == 0) {
            
            set<string> parsed = parse_function(temp, stoplist);
          
            for (const auto& e : parsed) {
                result.insert(e);
            } 

            }

        }
    }

}



int main() {


// Чтение входных данных

int n;
cin >> n;
getchar();

string line;
string f_name;

while (std::getline(std::cin, line)) {
    
    stringstream ss(line);

    string command;
    ss >> command;

    if (command == "func") {

        ss >> f_name;
        f_texts[f_name] = line;
    }
    else {
        f_texts[f_name] += "\n" + line; 
    }
}

    assert(f_texts.size() == n);

/* 
    for (const pair<string, string>& p : f_texts) {

        cout << p.first << " :\n";
        cout << p.second << endl;
        cout << endl;
    }

*/

// Конец чтения входных данных



// Вывод результатов

    set<string> stoplist;

    set<string> result = parse_function("main()", stoplist);
    cout << result.size() << "\n";

    for (const auto& e : result) {
        cout << e << endl;
    }


    return 0;
}