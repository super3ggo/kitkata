#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//
// Solution
//

// Notes:
//        This is not a hard problem per se, but you watch yourself when
//        counting.
//
//        With the approach below, we have the count variable represent
//        the amount of candy we have left to give, therefore we must
//        subtract one because we always give a piece of candy to each
//        prisoner, i.e. at each index.

int saveThePrisoner(int n, int m, int s) {
    int count    = m % n == 0 ? n - 1 : (m % n) - 1;
    int prisoner = s;

    prisoner+=count;

    if (prisoner >= n) {
        prisoner-=n;
        if (prisoner == 0) { // When we've come full circle,
            prisoner = n;    // we have to reset to the next prisoner in line.
        }
    }

    return prisoner;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nms_temp;
        getline(cin, nms_temp);

        vector<string> nms = split_string(nms_temp);

        int n = stoi(nms[0]);

        int m = stoi(nms[1]);

        int s = stoi(nms[2]);

        int result = saveThePrisoner(n, m, s);

        fout << result << "\n";
    }

    fout.close();

    //
    // STDIO Testing
    //

    // Test Cases

    // Test 0
    // int n = 5;
    // int m = 2;
    // int s = 1;

    // Test 1
    // int n = 5;
    // int m = 2;
    // int s = 2;

    // Test 2
    // int n = 7;
    // int m = 19;
    // int s = 2;

    // Test 3
    // int n = 3;
    // int m = 7;
    // int s = 3;

    // Test 4
    // int n = 352926151;
    // int m = 380324688;
    // int s = 94730870;

    // Test 5
    // int n = 94431605;
    // int m = 679262176;
    // int s = 5284458;

    // Test 6 (gotcha)
    // int n = 3;
    // int m = 394274638;
    // int s = 3;

    // Test 7 (gotcha)
    // int n = 468840391;
    // int m = 468840391;
    // int s = 1;

    // cout << "Save Prisoner #" << saveThePrisoner(n, m, s) << endl;

    //
    // End Testing
    //

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
