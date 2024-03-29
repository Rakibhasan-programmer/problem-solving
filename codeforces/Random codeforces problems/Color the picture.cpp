#include <bits/stdc++.h>
using namespace std;


bool canColor(int dim1, int dim2, const vector<int> &a)
{
    int stripeSum = 0;
    int extraStripeCount = 0;

    for (int i = 0; i < a.size() and stripeSum < dim1; ++i) {
        int currStripeCount = a[i] / dim2;
        if (currStripeCount < 2) continue;

        int canTake = min(dim1 - stripeSum, currStripeCount);
        stripeSum += canTake;
        extraStripeCount += canTake - 2;

        if (dim1 - stripeSum == 1) {
            if (extraStripeCount > 0) {
                --extraStripeCount;
                --stripeSum;
            } else {
                stripeSum -= 2;
            }
        }
    }

    return stripeSum == dim1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(k, 0);

        for (auto &val : a) {
            scanf("%d", &val);
        }

        bool ans = canColor(n, m, a) || canColor(m, n, a);

        printf("%s\n", ans? "Yes" : "No");
    }
    
    return 0;
}