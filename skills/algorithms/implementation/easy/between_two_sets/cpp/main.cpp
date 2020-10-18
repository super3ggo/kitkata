#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//
// Solution
//

//
// Externalities
//

// Both implementations of gcd and lcm were taken from the following Stack Overflow post:
// https://stackoverflow.com/questions/4229870/c-algorithm-to-calculate-least-common-multiple-for-multiple-numbers

// Did not implement.
int gcd(int a, int b) {
    for (;;) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

// Did not implement.
int lcm(int a, int b) {
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

//
// Helper Functions
//

int gcd_of_list(vector<int> v, int v0) {
    return accumulate(v.begin(), v.end(), v0, gcd);
}

int lcm_of_list(vector<int> v) {
    return accumulate(v.begin(), v.end(), 1, lcm);
}

int getTotalX(vector<int> a, vector<int> b) {
    // let vector a and vector b be sorted from lowest to greatest.
    // let lcm = the least common multiple of a.
    // let gcd = the greatest common denominator of b.
    // let btw = map . \x -> lcm * x . [1..n]
    //           Where n is a positive integer from 0 to positive
    //           infinity and every element of btw satisfies...
    //           1. elem <= gcd
    //           2. gcd % elem == 0
    //
    // We don't actually need to return btw, just its size. If we just
    // compute the elements of btw across 1..n and count them, that
    // would give us the size of btw.

    int gcd   = 0;
    int lcm   = 0;
    int count = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i=0; i<a.size(); i++) {
        cout << i << " = " << a[i] << endl;
    }

    for (int i=0; i<b.size(); i++) {
        cout << i << " = " << b[i] << endl;
    }

    lcm = lcm_of_list(a);
    gcd = gcd_of_list(b, b.front());

    int i = 1;
    while ((lcm * i) <= gcd) {
        if (gcd % (lcm * i) == 0) count++;
        i++;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
