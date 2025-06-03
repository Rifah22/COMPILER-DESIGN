#include <iostream>

using namespace std;

int main()
{
    int nfa[11][2] = {0};
    nfa[0][0] = 1; nfa[0][1] = 2;
    nfa[1][0] = 3; nfa[1][1] = 2;
    nfa[2][0] = 4; nfa[2][1] = 0;
    nfa[3][0] = 0; nfa[3][1] = 5;
    nfa[4][0] = 2; nfa[4][1] = 0;
    nfa[5][0] = 7; nfa[5][1] = 6;
    nfa[6][0] = 1; nfa[6][1] = 0;
    nfa[7][0] = 8; nfa[7][1] = 1;
    nfa[8][0] = 9; nfa[8][1] = 2;
    nfa[9][0] = 12; nfa[9][1] = 20;
    int dfa[20][2]={0};
    int dstate[20]={0};
    int i = 1, n, j, k, flag = 0, m, q, r;
    dstate[i++] = 1;
    n = i;

    dfa[0][1] = nfa[1][1];
    dfa[2][2] = nfa[1][2];
    cout << "\nf(" << dstate[1] << ",a)=" << dfa[0][1] << endl;
    cout << "f(" << dstate[1] << ",b)=" << dfa[2][2] << endl;

    for (j = 1; j < n; j++)
    {
        if (dfa[0][1] != dstate[j])
            flag++;
    }
    if (flag == n - 1)
    {
        dstate[i++] = dfa[0][1];
        n++;
    }
    flag = 0;
    for (j = 1; j < n; j++)
    {
        if (dfa[2][2] != dstate[j])
            flag++;
    }
    if (flag == n - 1)
    {
        dstate[i++] = dfa[2][2];
        n++;
    }
    k = 2;
    while (dstate[k] != 0)
    {
        m = dstate[k];
        if (m > 10)
        {
            q = m / 10;
            r = m % 10;
        }
        if (nfa[r][1] != 0)
            dfa[k][0] = nfa[q][1] * 10 + nfa[r][2];
        else
            dfa[k][1] = nfa[q][1];
        if (nfa[r][2] != 0)
            dfa[k][0] = nfa[q][1] * 10 + nfa[r][2];
        else
            dfa[k][2] = nfa[q][2];

        cout << "\nf(" << dstate[k] << ",a)=" << dfa[k][1] << endl;
        cout << "f(" << dstate[k] << ",b)=" << dfa[k][2] << endl;

        flag = 0;
        for (j = 1; j < n; j++)
        {
            if (dfa[k][1] != dstate[j])
                flag++;
        }
        if (flag == n - 1)
        {
            dstate[i++] = dfa[k][1];
            n++;
        }
        flag = 0;
        for (j = 1; j < n; j++)
        {
            if (dfa[k][2] != dstate[j])
                flag++;
        }
        if (flag == n - 1)
        {
            dstate[i++] = dfa[k][2];
            n++;
        }
        k++;
    }
    cout << "\n\tTransition Table \n";
    cout << "_____________________________________\n";
    cout << "Current State |\tInput |\tNext State";
    cout << "\n_____________________________________\n";
    for (i = 1; i < n; i++)
    {
        cout << "  q[" << i << "]\t      |   a   |  q[" << dfa[i][1] << "]\n";
        cout << "  q[" << i << "]\t      |   b   |  q[" << dfa[i][2] << "]\n";
    }

    cout << "_____________________________________\n";

    return 0;
}
