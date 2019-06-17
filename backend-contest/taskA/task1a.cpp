#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {


    int N, X, K;

    cin >> N >> X >> K;

    map<int, set<int>> deadlines;

    for (int i = 0; i < N; ++i) {

        int t;
        cin >> t;
        deadlines[t/X].insert(t%X);
    }

/* 
    for (const auto& p : deadlines) {

        cout << p.first << ":" << endl;

        for (const auto& s : p.second) {
             cout << s << " ";   
        }

        cout << endl;

    }
*/    
 


    set<int> mods;
    int level = 0;

    for (const auto& p : deadlines) {

        if ((p.first - level)*mods.size() >= K) {
            break;
        }
        else {
            K -= (p.first - level)*mods.size();
        }     

        level = p.first;

        for (const auto& item : p.second) {

            mods.insert(item);
        }

        
    }


    vector<int> v(mods.begin(), mods.end());

    cout << level*X + (K-1)/v.size()*X + v[(K-1) % v.size() ] << endl;

    
    return 0;
}