
#include <iostream>

using namespace std;

int main() {

    int nfa[11][2] = {0};

    nfa[0][0] = 71; nfa[0][1] = 1;

    nfa[1][0] = 0; nfa[1][1] = 2;

    nfa[2][0] = 3; nfa[2][1] = 0;

    nfa[3][0] = 0; nfa[3][1] = 5;

    nfa[4][0] = 4; nfa[4][1] = 1;

    nfa[5][0] = 0; nfa[5][1] = 6;

    nfa[6][0] = 71; nfa[6][1] = 1;

    nfa[7][0] = 8; nfa[7][1] = 0;

    nfa[8][0] = 1; nfa[8][1] = 0;

    nfa[9][0] = 10; nfa[9][1] = 1;

    int dfa[20][2] = {0};

    int dstate[20] = {0};

    int i = 1, n, j, k = 1, flag = 0, m, q, r;

    dstate[i++] = 0;

    n = i;

    dfa[1][0] = nfa[0][0];

    dfa[1][1] = nfa[0][1];

    cout << "\nf(" << dstate[1] << ",a)=" << dfa[1][0] << endl;

    cout << "f(" << dstate[1] << ",b)=" << dfa[1][1] << endl;

    for (j = 1; j < n; j++) {

        if (dfa[1][0] != dstate[j])

            flag++;

    }

    if (flag == n - 1) {

        dstate[i++] = dfa[1][0];

        n++;

    }

    flag = 0;

    for (j = 1; j < n; j++) {

        if (dfa[1][1] != dstate[j])

            flag++;

    }

    if (flag == n - 1) {

        dstate[i++] = dfa[1][1];

        n++;

    }

    k = 2;

    while (dstate[k] != 0) {

        m = dstate[k];

        if (m > 10) {

            q = m / 10;

            r = m % 10;

        }

        if (nfa[r][0] != 0)

            dfa[k][0] = nfa[q][0] * 10 + nfa[r][0];

        else

            dfa[k][0] = nfa[q][0];

        if (nfa[r][1] != 0)

            dfa[k][1] = nfa[q][1] * 10 + nfa[r][1];

        else

            dfa[k][1] = nfa[q][1];

        cout << "\nf(" << dstate[k] << ",a)=" << dfa[k][0] << endl;

        cout << "f(" << dstate[k] << ",b)=" << dfa[k][1] << endl;

        flag = 0;

        for (j = 1; j < n; j++) {

            if (dfa[k][0] != dstate[j])

                flag++;

        }

        if (flag == n - 1) {

            dstate[i++] = dfa[k][0];

            n++;

        }

        flag = 0;

        for (j = 1; j < n; j++) {

            if (dfa[k][1] != dstate[j])

                flag++;

        }

        if (flag == n - 1) {

            dstate[i++] = dfa[k][1];

            n++;

        }

        k++;

    }


    cout << "\n\tTransition Table \n";

    cout << "_____________________________________\n";

    cout << "Current State |\tInput |\tNext State";

    cout << "\n_____________________________________\n";



    for (i = 0; i <= n; i++) {

            cout << "\n  q[" << i << "]\t      |   a   |  q[" << dfa[i][1] << "]";

             cout << "\n  q[" << i << "]\t      |   b   |  q[" << dfa[i][0] << "]";


        }


    cout << "_____________________________________\n";

    return 0;

}
