// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void parse(string s, map<string, vector<string>>&m) {
    
    if(s[0] == '{') {
        int i = 1;
        
        while(i<s.size()) {
            string key = s.substr(i,s.find(':', i) - i);
            
            string val = s.substr(s.find(':', i) +1,  s.find(',', i);
            
            if(val[0] == '{') {
                map<string, vector<string>> inner;
                parse(val, inner);
                
                //recursion for inner nested objects
                m[key] = inner;
            } else {
                if(m.find(key) != m.end())
                    m.push_back(val);
                else {
                    vector<string>temp;
                    temp.push_back(key);
                    m[key] = value;
                }
            }
            i = s.find(',', i) + 1;
        }
    } 
}

void printVal(map<string, vector<string>>m, string key) {
    int pos = key.find(".");

    //non-nested cases
    if (pos == -1) {
        return m[key];
    }
    
    vector<string> innerJsons = split(key, ".");
    map<string, vector<string>> innerMap = m;
    
    for(auto x:innerJsons) {
        if(innerMap.count(x) == 0)
            return;
        innerMap = innerMap[x];
    }
    
    string ans  = "";
    for(auto x: innerMap[innerJsons.back()]) {
        ans+= x;
    }
    return ans;
    
}
int main() {
    // Write C++ code here
    string s;
    int n,q;
    cin>>s;
    cin>>n>>q;
    map<string, vector<string>>m;
    parse(s, m);
    
    //sample string 
    string json ="{\firstName\": \"Steve\", 
    "\address\": {\"street\" : \"1st cross\"}};
    
    for(int i= 0; i<q;i++) {
        string key;
        cin>>key;
        cout<<printValue(m, key)<<endl;
    }

    return 0;
}
