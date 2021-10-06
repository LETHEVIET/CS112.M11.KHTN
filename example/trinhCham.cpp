#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int MINN = 1, MAXN = 10, MINM = 1, MAXM = 10, MINV = 1, MAXV = 10;
int n, m;

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= 100; iTest++)
    {
        ofstream inp("vmellip.inp");
        n = MINN + rand() % (MAXN - MINN + 1);
        m = MINM + rand() % (MAXM - MINM + 1);
        inp << n << " " << m << "\n";
        for(int i = 1; i <= n; i++)
        {
            inp << MINV + rand() % (MAXV - MINV + 1) << " " << MINV + rand() % (MAXV - MINV + 1) << " ";
        }
        inp << "\n";
        for(int i = 1; i <= m; i++)
        {
            int tp = 1 + rand() % 6, l = 1 + rand() % n, h = 1 + rand() % n, v = MINV + rand() % (MAXV - MINV + 1);
            if(l > h)
            {
                swap(l, h);
            }
            if(tp <= 4)
            {
                inp << tp << " " << l << " " << h << " " << v << "\n";
            }
            else
            {
                inp << tp << " " << l << " " << h << "\n";
            }
        }
        inp << MINV + rand() % (MAXV - MINV + 1) << " " << MINV + rand() % (MAXV - MINV + 1);
        inp.close();

        auto start = high_resolution_clock::now();
        system("vmellip.exe");
        auto stop = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop - start);

        start = high_resolution_clock::now();
        system("vmellip_trau.exe");
        stop = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop - start);

        if(system("fc vmellip.out vmellip.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
        cout << "vmellip.exe excution time: " << duration1.count()<< " microseconds" << endl;
        cout << "vmellip_trau.exe excution time: " << duration2.count()<< " microseconds" << endl;
    }
    return 0;
}
