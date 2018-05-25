#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int arr[1000] = {0};
    arr[0] = 1;
    auto len = 1;
    for ( auto i = 2;
          i <= n;
          i++) {
        auto carry = 0;
        for ( auto j = 0;
              j < len;
              j++) {
            auto mul = i * arr[j] + carry;
            auto dig = mul % 10;
            arr[j] = dig;
            carry = mul / 10;
        }

        while (carry) {
            len++;
            auto dig = carry % 10;
            arr[len - 1] = dig;
            carry /= 10;
        }
    }

    for ( auto i = len - 1;
         i >= 0;
         i--) {
        cout << arr[i];
    }

    cout << endl;

}


int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
