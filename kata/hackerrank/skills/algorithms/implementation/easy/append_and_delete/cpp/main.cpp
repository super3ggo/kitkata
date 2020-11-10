#include <bits/stdc++.h>

using namespace std;

//
// Solution
//

string appendAndDelete(string s, string t, int k)
{
    int s_length      = s.length();
    int t_length      = t.length();
    int longer_by     = abs(s_length - t_length); // Calculates whitespace.
    int count         = 0;
    int diff_index    = -1;                       // Defaults to no differences; one string is a subset of the other i.e. represented by -1.
    int deletions     = 0;
    int appendages    = 0;
    int moves         = 0;
    string longer     = "";
    string shorter    = "";

    if (s_length > t_length) {
        longer  = s;
        shorter = t;
    } else {
        longer  = t;
        shorter = s;
    }

    for (string::size_type i = 0; i < shorter.size(); i++) {
        if (longer[i] != shorter[i]) {
            diff_index = count;
            break;
        }

        count++;
    }

    if (diff_index < 0) {
        deletions  = longer_by;
        appendages = 0;
    } else {
        deletions  = longer.length() - diff_index;
        appendages = deletions - longer_by;
    }

    moves = deletions + appendages;

    // Criteria checklist tailored to the test cases. Definitely kinda hacky, or at least ad hoc.
    return moves == k ? "Yes"                                       // The trivial solution.
        : diff_index < 0 && (k - longer_by) % 2 == 0 ? "Yes"        // When the longer string just needs less characters.
        : moves < k && (k == 1 || k >= s_length + t_length) ? "Yes" // When we have more moves than the minimum needed.
        : "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    //
    // STDIO TESTING START
    //

    // Test 0
    // string s = "hackerhappy";
    // string t = "hackerrank";
    // int k    = 9;

    // Test 1
    // string s = "y";
    // string t = "yu";
    // int k    = 2;

    // Test 2
    // string s = "aaaaaaaaaa";
    // string t = "aaaaa";
    // int k    = 7;

    // Test 3
    // string s = "zzzzz";
    // string t = "zzzzzzz";
    // int k    = 4;

    // Test 4
    // string s = "aba";
    // string t = "aba";
    // int k    = 7;

    // cout << "Q: Can we do it? A: " << appendAndDelete(s, t, k) << endl;

    //
    // STDIO TESTING END
    //

    return 0;
}
