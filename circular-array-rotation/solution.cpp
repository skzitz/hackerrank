#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#if SLOW_WAY
// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, vector<int> m) {


}
#endif

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkq_temp;
    getline(cin, nkq_temp);

    vector<string> nkq = split_string(nkq_temp);

    int n = stoi(nkq[0]);

    int k = stoi(nkq[1]);


    int q = stoi(nkq[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> m(q);

    for (int i = 0; i < q; i++) {
        int m_item;
        cin >> m_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        m[i] = m_item;
    }

#if SLOW_WAY
    vector<int> result = circularArrayRotation(a, m);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];


        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
#else
    auto array_size = a.size();
    if ( k > n ) {
        // doesn't make sense to rotate multiple complete times.
        // if the array has n elements, and we rotate n+1 times,
        // that's the same as just rotating once.
        cerr << "trimming redundant rotates from " << k;
        k = k % array_size;
        cerr << " to " << k << endl;
    }
    auto m_size = m.size();
    for ( auto i = 0; i < m_size; i++ ) {
        auto offset = (m[i]-k+array_size) % array_size;
        cerr << "i=" << i << "; m[i]=" << m[i] << "; k=" << k << "; m[i]-k=" << (m[i]-k) << "; (m[i]-k+array_size)=" << (m[i]-k+array_size)<< "; (m[i]-k+array_size)%array_size=" << offset << endl;
        cout << a[offset] << endl;
        fout << a[offset] << endl;

    }
#endif

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
