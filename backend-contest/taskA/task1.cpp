#include <iostream>
#include <set>

using namespace std;

int main() {


    int N, X, K;

    cin >> N >> X >> K;

    set<long long> deadlines;

    for (int i = 0; i < N; ++i) {

        long long t;
        cin >> t;
        deadlines.insert(t);

    }

    for (int i = 0; i < K-1; ++i) {

        long long m = *deadlines.begin();
        deadlines.erase(m);
        deadlines.insert(m+X);

    }


    cout << *deadlines.begin() << endl;

    return 0;
}