#include <bits/stdc++.h>

using namespace std;

// count the number of divisors (mod=0) occurring within the integer.
// each digit is considered unique, so each occurrence should be counted.
// e.g. for n=111, 1 is a divisor of 111, and it appears 3x, so the answer
// would be 3.
// so for 1122334,
//  is 1 a divisor?
//  is 1 a divisor?
//  is 2 a divisor?
//  is 2 a divisor?
//  is 3 a divisor?
//  is 3 a divisor?
//  is 4 a divisor?
//
//  seen[#] -> how many times this # has been seen
//             -1 means its been calculated and is not a divisor
//              0 means it has not been calculated, so do the calculation, and add
//                to the count
//              1 we've seen it, just add to the count

// Complete the findDigits function below.
int findDigits(int n) {
    vector<int> seen;
    int         count   = 0;
    int         workInt = n;

    while ( workInt > 0 ) {
        int digit = workInt % 10;
        workInt /= 10;
        if ( 0 != digit ) {
#if 0
            if ( 1 == seen[digit] ) {
                count++;
            } else if ( 0 == seen[digit] ) {
                if ( 0 == ( n % digit ) ) {
                    count++;
                    seen[digit] = 1;
                }
            }
#else
            if ( 0 == (n%digit) ) {
                count++;
            }
#endif
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
        cerr << result << endl;
    }

    fout.close();

    return 0;
}
