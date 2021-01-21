#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> invec;
    int N = 100;
    int i = 0;
    invec.resize(N+1);

    for (i = 1; i <= N; i++) {
        invec[i] = rand();
    }

    //minrun


    /*    invec[1]=13;
        invec[2]=12;
        invec[3]=132;
        invec[4]=233;
        invec[5]=1;
        invec[6]=4;
        invec[7]=5342;
        invec[8]=7;
        invec[9]=13;
        invec[10]=233;
        ifstream fin;
        fin.open("input.txt", ios::in);
        if (fin.is_open()) {
           for (i=1, i<=15, i++) {
                fin >> invec[i];
            }
        }
    */

    for (i = 1; i <= N; i++) {
        cout << invec[i] << endl;
    }
    return 0;
}