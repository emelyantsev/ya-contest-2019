#include <iostream>

using namespace std;


int main() {


    int K, N;
    cin >> K >> N;


    int Petya = 0;
    int Vasya = 0;

    for (int i = 0; i < N; ++i) {

        int t;
        cin >> t;

        if (t % 7 == 0 && t % 10 == 0) {

            Petya += t;
            Vasya += t;

        }
        else if (t % 7 == 0) {
            Vasya += t;
        }
        else if (t % 10 == 0) {
            Petya += t/2 ;
        }


        if (Petya >= K && Petya > Vasya) {
            cout << "Petya" << endl;
            return 0;
        }
        else if (Vasya >= K && Vasya > Petya){
            cout << "Vasya" << endl;
            return 0;    
        }
    }


    if (Petya > Vasya) {
        cout << "Petya" << endl;
    }
    else if (Vasya > Petya) {
        cout << "Vasya" << endl;
    }
    else {
        cout << "Draw" << endl;
    }

    return 0;
}