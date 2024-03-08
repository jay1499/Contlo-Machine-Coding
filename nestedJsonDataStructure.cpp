
//Data structure logic

class Trie {
   string value;
   map<string, Trie> keys;

   Trie() {}

   Trie(value) {
      value = value;
   }
};

class Json {

   Trie *root = new Trie();

 // {firstname: john, lastname: doe, address : { city : bangalore}}

   void insert (vector<string> keys, string val) {

      Trie *curr = root;

      for(auto key: keys) {
         if(curr.keys.find(key) == curr.end()) {
            Trie* temp = new Trie(val);

            map<string, Trie>m;
            m[key] = *temp;
            temp->keys = m;
            curr->keys[key]  = *temp;
         } 
         else {
            curr = curr->keys[key];
         }
      }
   }

   String getValue (vector<string> keys) {
      Trie *curr = root;

      for(auto key: keys) {
         if(curr->keys[key] == nullptr)
            return "";

         curr = curr->keys[key];
      }

      return curr->value;
   }

}

//
{
   "firstName" : "John",
   "address" : {
      "street": "1st cross",
      "area": "whitefield",
      "phone": {
         "countryCode": "+91",
         "number": 9980204345
    }
   "lastName": "Doe"
   }
}

Parsing logic

1) Accept user input line by line
2) For each line,
   - Extract the key by extracting characters before colon(:)
      -- If character after colon is open braces then accept next line input, store the key in the keys
       array which will be a temporary array until closing braces are found in the user input
      -- If its not open brace, then extract charactets before comma(,) which will be the value
      -- Call insert function with keys array and value

Value extraction logic

1) Split the user input into keys string based on the colon character delimiter
2) Call the getValue function with keys array as the parameter
