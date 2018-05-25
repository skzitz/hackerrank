#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the permutationEquation function below.
// p(p(y)) = x
// p = [5,2,1,3,4]
// find  y such that p[y]=1, then p[y]=2 ....
// 1: p[3]
// 2: p[2]
// 3: p[4]
// 4: p[5]
// 5: p[1]
//
// now repeat the process:
// 3: p[4]
// 2: p[2]
// 4: p[5]
// 5: p[1]
// 1: p[3]
//
// p[p[4]]=1
// p[p[2]]=2
// p[p[5]]=3
// p[p[1]]=4
// p[p[3]]=5

vector<int> permutationEquation(vector<int> p) {
    map<int,int> mapping;
    vector<int> result;
    int i = 1;
    for ( auto a : p ) {
        mapping[a] = i++;
    }
    // for p=[5,2,1,3,4]
    // mapping=[3,2,4,5,1]
    // mapping[1] = 3; mapping[3] = 4
    // mapping[2] = 2; mapping[2] = 2
    // mapping[3] = 4; mapping[4] = 5
    // mapping[4] = 5; mapping[5] = 1
    // mapping[5] = 1; mapping[1] = 3
    // build a map

    for ( int i = 0;
          i < p.size();
          i++ ) {
        auto step1 = mapping[i+1];
        auto step2 = mapping[step1];
        result.push_back(step2);
    }

    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

    for ( auto it = result.begin();
          it != result.end();
          ++it ) {
        fout << *it << endl;
        cerr << *it << endl;
    }

#if 0
    }
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
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
