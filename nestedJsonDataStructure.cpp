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
            curr->keys[key]  = * temp;
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
