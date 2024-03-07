
#include<bits/stdc++.h>
using namespace std;

void parse(const string& s, map<string, vector<string>>& m);
string printVal(const map<string, vector<string>>& m, const string& key);
vector<string> split(string& s, char d);

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
            m[key] = vector<string>{val};
        } 
        
        //handle single level object
        else {
            vector<string> temp = split(val, ',');
            m[key] = temp;
        }
    }
}

string printVal(const map<string, vector<string>>& m, const string& key) {
    size_t pos = key.find(".");

    if (pos == string::npos) {
        if (m.find(key) != m.end()) {
            string result;
            for (const auto& value : m.at(key)) {
                result += value + " ";
            }
            return result;
        } else {
            return "Null";
        }
    } else {
        string innerKey = key.substr(0, pos);
        string outerKey = key.substr(pos + 1);
        if (m.find(innerKey) != m.end()) {
            map<string, vector<string>> innerMap;
            parse(m.at(innerKey).front(), innerMap);
             // recursion for inner nested objects
            return printVal(innerMap, outerKey);
        } else {
            return "Null";
        }
    }
}

//to handle splitting of nested objects with '.' as the delimiter
vector<string> split(string& s, char d) {
    vector<string> words;
    string word;
    istringstream wordStream(s);
    while (getline(wordStream, word, d)) {
        words.push_back(word);
    }
    return words;
}

int main() {
    //asssuming input string in one line
    string s;
    getline(cin, s);

    int q;
    cin >> q;
    map<string, vector<string>> m;
    parse(s, m);

    for (int i = 0; i < q; i++) {
        string key;
        cin >> key;
        cout << printVal(m, key) << endl;
    }

    return 0;
}

