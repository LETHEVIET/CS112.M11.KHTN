#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000, MAXM = 100000;
int n, m;
int a[MAXN + 9], b[MAXN + 9];
int tp[MAXM + 9], l[MAXM + 9], r[MAXM + 9], v[MAXM + 9];
int A, B;

int main()
{
    ifstream cin("vmellip.inp");
    ofstream cout("vmellip.ans");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> tp[i];
        if(tp[i] <= 4)
        {
            cin >> l[i] >> r[i] >> v[i];
        }
        else
        {
            cin >> l[i] >> r[i];
        }
    }
    cin >> A >> B;
    for(int i = 1; i <= m; i++)
    {
        if(tp[i] == 1)
        {
            for(int j = l[i]; j <= r[i]; j++)
            {
                if(a[j] > 0 && a[j] <= A)
                {
                    a[j] = v[i];
                }
            }
        }
        else if(tp[i] == 2)
        {
            for(int j = l[i]; j <= r[i]; j++)
            {
                if(b[j] > 0 && b[j] <= B)
                {
                    b[j] = v[i];
                }
            }
        }
        else if(tp[i] == 3)
        {
            for(int j = l[i]; j <= r[i]; j++)
            {
                if(a[j] > 0 && a[j] <= A)
                {
                    a[j] += v[i];
                }
            }
        }
        else if(tp[i] == 4)
        {
            for(int j = l[i]; j <= r[i]; j++)
            {
                if(b[j] > 0 && b[j] <= B)
                {
                    b[j] += v[i];
                }
            }
        }
        else if(tp[i] == 5)
        {
            long long ans = 0;
            for(int j = l[i]; j <= r[i]; j++)
            {
                if(a[j] > 0 && a[j] <= A && b[j] > 0 && b[j] <= B)
                {
                    ans += (long long)a[j] * b[j];
                }
            }
            cout << ans << "\n";
        }
        else
        {
            int ans = 0;
            for(int j = l[i]; j <= r[i]; j++)
            {
                if(a[j] > 0 && a[j] <= A && b[j] > 0 && b[j] <= B)
                {
                    ans++;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
