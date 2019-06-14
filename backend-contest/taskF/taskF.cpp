#include <iostream>

using namespace std;

void query(int l, int r) {

    cout << l << " " << r << endl << flush;
}

void print_answer(int p) {

    cout << "! " << p << endl << flush;
    exit(0);
}




int main() {

    int n;
    cin >> n;


    int l = 1;
    int r = n;

    while (true) {

        int d = r-l;

        if (d > 2) {


            int lt = l + d/3;
            int rt = l + 2*d/3;

            query(lt, rt);

            int la, ra;
            cin >> la >> ra;

            if (la == 1 && ra == 1) {
                l = rt;
            }
            else if (la == 0 && ra == 0) {
                r = lt;
            }
            else if (la == 1 && ra == 0) {

                if (rt - lt == 1) {
                    print_answer(rt);
                }
                else {
                    l = lt;
                    r = rt;
                }
            }

        }
        else if (d == 2) {


            int lt = l + 1;
            int rt = l + 2;

            query(lt, rt);

            int la, ra;
            cin >> la >> ra;

            if (la == 0 && ra == 0) {
                r = lt;
            }
            else if (la == 1 && ra == 0) {

                if (rt - lt == 1) {
                    print_answer(rt);
                }
                else {
                    l = lt;
                    r = rt;
                }
            }

        }


        else if (d == 1) {

            query(l, r);

            int la, ra;
            cin >> la >> ra;

            if (la == 0 && ra == 0) {
                print_answer(l);
            }
            else if (la == 1 && ra == 0) {

                print_answer(r);

            }

        }
        else {
            
            print_answer(l);
        }








    }

    return 0;
}