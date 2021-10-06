#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Tên chương trình
//const string NAME = "template";
// Số test kiểm tra
//const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    string NAME = "baitap";
    int NTEST = 100;
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        /*** 
            Code phần sinh test ở đây
        ***/
        inp.close();

        auto start = high_resolution_clock::now();
        system((NAME + ".exe").c_str());
        auto stop = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop - start);

        start = high_resolution_clock::now();
        system((NAME + "_trau.exe").c_str());
        stop = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop - start);
        
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
        cout << NAME + ".exe" + "excution time: " << duration1.count()<< " microseconds" << endl;
        cout << NAME + "_trau.exe" + "excution time: " << duration2.count()<< " microseconds" << endl;
    }
    return 0;
}