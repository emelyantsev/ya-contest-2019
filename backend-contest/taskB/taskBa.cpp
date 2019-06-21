#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <utility>
#include <iterator>

using namespace std;

int main() {

    int n;
    cin >> n;

    int k = log2(n+1);
 //   cout << "k = " << k << endl;

    vector<pair<string, string>> matches(n);
    map<string, int> stat;
    map<int, set<string>> inverse_stat;


    for (int i = 0; i < n; ++i) {

        string s1, s2;
        cin >> s1 >> s2;

        matches[i] = {s1,s2};

        stat[s1] +=1;
        stat[s2] +=1;
    }


    for (const auto& s : stat) {

        inverse_stat[s.second].insert(s.first) ;
    }

/*
    for (const auto& s1 : inverse_stat) {

        cout << s1.first << " : " << endl;

        for (const auto& s2 : s1.second) {

            cout << s2 << " " ;

        }

        cout << endl;
    }
 */


    map<string, string> winners;


    for (const auto& p : matches) {

        if (stat[p.first] == k && stat[p.second] == k) {
            continue;
        }
        else if (stat[p.first] < stat[p.second] ) {

            if (winners.count(p.first) ) {
                cout << "NO SOLUTION" << endl;
                exit(0);
            }
            else {
                winners[p.first] = p.second;
            }
        }
        else if (stat[p.first] > stat[p.second] ) {

            if (winners.count(p.second) ) {
                cout << "NO SOLUTION" << endl;
                exit(0);
            }
            else {
                winners[p.second] = p.first;
            }

        }

        else {

            cout << "NO SOLUTION" << endl;
            exit(0);
        }



    }


    for (int i = 1; i <= k; ++i) {

        if (i == k && inverse_stat[i].size() == 2) {
            continue;
        }
        else if (i == k-1) {

            if (inverse_stat[i].size() != 2) {
                cout << "NO SOLUTION" << endl;
                exit(0);
            }

            set<string> s1;

            for (const auto& player : inverse_stat[i] ) {

                s1.insert(winners[player]);
            }

            set<string> s2;

            for (const auto& player : inverse_stat[i+1] ) {

                s2.insert(player); 
            }

            if (s1 != s2) {
                cout << "NO SOLUTION" << endl;
                exit(0);
            }


        }


        else if (inverse_stat[i].size() == pow(2,k-i) ) {

            set<string> s1;

            for (const auto& player : inverse_stat[i] ) {

                s1.insert(winners[player]);
            }

            set<string> s2;

            for (const auto& player : inverse_stat[i+1] ) {

                s2.insert(player);    
                s2.insert(winners[player]);
            }


            if (s1 != s2) {
                cout << "NO SOLUTION" << endl;
                exit(0);
            }


        }
        else {
            cout << "NO SOLUTION" << endl;
            exit(0);
        }

    }

    cout << *inverse_stat[k-1].begin() << " " << *next(inverse_stat[k-1].begin()) << endl;


    return 0;
}