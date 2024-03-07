#include <bits/stdc++.h>
using namespace std;


void parse(const string& s, map<string, vector<string>>& m) {
    int i = 0;
    while (i < s.size()) {
        string key = s.substr(i, s.find(':', i) - i);
        string val;
        int next = s.find(',', i);
        if (next != string::npos) {
            val = s.substr(s.find(':', i) + 1, next - (s.find(':', i) + 1));
            i = next + 1;
        } else {
            val = s.substr(s.find(':', i) + 1);
            i = s.size();
        }

        //handle nested level objects
        if (val[0] == '{') {
            map<string, vector<string>> inner;
            parse(val, inner);
            // recursion for inner nested objects
            m[key] = inner;
        } 

        //handle single level object
        else {
            vector<string> temp = split(val, ',');
            m[key] = temp;
        }
    }
}

string printVal(const map<string, vector<string>>& m, const string& key) {
    int pos = key.find(".");

    // non-nested cases
    if (pos == string::npos) {
        if (m.find(key) != m.end()) {
            string result;
            for (auto value : m.at(key)) {
                result += value + " ";
            }
            return result;
        } else {
            return "Null";
        }
    }

    vector<string> innerJsons = split(key, '.');
    map<string, vector<string>> innerMap = m;

    for (auto& x : innerJsons) {
        if (innerMap.count(x) == 0) {
            return "Null";
        }
        innerMap = innerMap[x];
    }

    string result;
    for (auto& x : innerMap[innerJsons.back()]) {
        result += value + " ";
    }
    return result;
}

//to handle splitting of nested objects with '.' as the delimiter
vector<string> split(string& s, char d) {
    vector<string> words;
    string word;
    istringstream wordStream(s);
    while (getline(wordStream, word, d)) {
        words.push_back(words);
    }
    return words;
}

int main() {
    string s;
    int n, q;
    cin >> s >> n >> q;
    map<string, vector<string>> m;
    parse(s, m);

    for (int i = 0; i < q; i++) {
        string key;
        cin >> key;
        cout << printVal(m, key) << endl;
    }

    return 0;
}
