#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN = 1e6 + 3;
char str[MAXN];


int main()
{
    int q;
    cin >> q;

    while (q--) {
        int n;
        LL k;
        cin >> n >> k >> str;

        // Find the index of left-most 1 in the input string.
        int leftmostOneIdx = -1;
        for(int i = 0; i < n; ++i) {
            if(str[i] == '1') {
                leftmostOneIdx = i;
                break;
            }
        }

        if(leftmostOneIdx != -1) {
            // Try k moves.
            for(int i = leftmostOneIdx + 1; i < n and k > 0; ++i) {
                if(str[i] == '0') {
                    int j;
                    if(i - leftmostOneIdx <= k) {
                        j = leftmostOneIdx;
                        leftmostOneIdx++;
                    } else {
                        j = i - k;
                    }

                    swap(str[i], str[j]);
                    k -= i - j;
                }
            }
        }

        puts(str);
    }

    return 0;
}