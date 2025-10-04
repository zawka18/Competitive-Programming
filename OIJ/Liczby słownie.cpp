#include <bits/stdc++.h>

using namespace std;

string liczby[] = {"",           "jeden",      "dwa",          "trzy",        "cztery",
                   "piec",       "szesc",      "siedem",       "osiem",       "dziewiec",
                   "dziesiec",   "jedenascie", "dwanascie",    "trzynascie",  "czternascie",
                   "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};

string siatki[] = {"",
                   "",
                   "dwadziescia",
                   "trzydziesci",
                   "czterdziesci",
                   "piecdziesiat",
                   "szescdziesiat",
                   "siedemdziesiat",
                   "osiemdziesiat",
                   "dziewiecdziesiat"};

string setki[] = {"",        "sto",      "dwiescie",  "trzysta",  "czterysta",
                  "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};

string tys[] = {"tysiac", "tysiace", "tysiecy"};
string mln[] = {"milion", "miliony", "milionow"};
string mld[] = {"miliard", "miliardy", "miliardow"};

string* arrRefs[] = {tys, mln, mld};
long long multipliers[] = {(long long)1e3, (long long)1e6, (long long)1e9};

string generate_three_digits(long long x) {
    if (x == 0)
        return "zero";
    long long reszta = x % 100;
    string res = setki[x / 100];

    if (res != "" && reszta > 0)
        res += " ";

    if (reszta < 20) {
        res += liczby[reszta];
        return res;
    }

    res += siatki[reszta / 10];

    if (reszta % 10 != 0) {
        res += " " + liczby[reszta % 10];
    }

    return res;
}

string suffix(string* arr, int x) {
    if (x == 0)
        return "";
    if (x == 1)
        return arr[0];
    if (x <= 4 || (x > 20 && (x % 10 >= 2 && x % 10 <= 4)))
        return arr[1];
    return arr[2];
}

string whichSuffix(int i, long long x) {
    if (i == 0)
        return "";
    return suffix(arrRefs[i - 1], x);
}

string generate_string_from_number(long long x) {
    vector<string> v;
    for (int i = 0; i < 6; i++) {
        long long cur3Digits = x % 1000;
        string curS = generate_three_digits(cur3Digits);
        if (x >= 1000 && curS == "zero") {
            curS = "";
        } else if (i > 0)
            curS += " " + whichSuffix(i, x);
        if (curS != "")
            v.push_back(curS);
        x /= 1000;
        if (x == 0)
            break;
    }

    reverse(v.begin(), v.end());
    string s;
    for (int i = 0; i < (int)v.size(); i++) {
        string x = v[i];
        s += x;
        if (i != (int)v.size() - 1) {
            s += " ";
        }
    }
    return s;
}

vector<string> split_on_delim(string s, char delim) {
    vector<string> res;
    int pos = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == delim) {
            res.push_back(s.substr(pos, i - pos));
            pos = i + 1;
        }
    }
    res.push_back(s.substr(pos));
    return res;
}

long long getMultiplier(string s) {
    for (int i = 0; i < 3; i++) {
        string* arr = arrRefs[i];
        for (int j = 0; j < 3; j++) {
            string suff = arr[j];
            if (s == suff) {
                return multipliers[i];
            }
        }
    }
    return -1;
}

long long generateCur(vector<string>& toNum) {
    string merged;

    for (int i = 0; i < (int)toNum.size(); i++) {
        if (i)
            merged += " ";
        merged += toNum[i];
    }

    for (int i = 0; i <= 999; i++) {
        if (generate_string_from_number(i) == merged) {
            return i;
        }
    }

    return -1;
}

void solve(vector<string>& v, string s) {
    long long number = 0;
    vector<string> toNum;
    for (int i = 0; i < (int)v.size(); i++) {
        long long mul = getMultiplier(v[i]);
        if (mul == -1) {
            toNum.push_back(v[i]);
        } else {
            long long cur = generateCur(toNum);
            if (cur < 0) {
                cout << "NIE\n";
                return;
            }
            number += (cur * mul);
            toNum.clear();
        }

        if (toNum.size() > 3) {
            cout << "NIE\n";
            return;
        }
    }

    if (toNum.size()) {
        long long cur = generateCur(toNum);
        if (cur < 0) {
            cout << "NIE\n";
            return;
        }
        number += cur;
        toNum.clear();
    }

    if (number > 0 && number <= (long long)1e9 && s == generate_string_from_number(number)) {
        cout << number << "\n";
    } else
        cout << "NIE\n";
}

int main() {
    string s;
    getline(cin, s);
    vector<string> v = split_on_delim(s, ' ');
    solve(v, s);
    return 0;
}
