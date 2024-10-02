//#include<bits/stdc++.h>
//using namespace std;
//
//vector<int>contacts(vector<vector<string>>q)
//{
//    vector<string>v;
//    vector<int>ans;
//    for(int i=0;i<q.size();i++){
//        string opr=q[i][0];
//        string s=q[i][1];
//        if(opr=="add")
//            v.push_back(s);
//        else{
//            int a=0;
//            for(int i=0;i<v.size();i++){
//                string k=v[i];
//                int b=s.size();
//                string an=k.substr(0,b);
//                if(an==s)
//                    a++;
//            }
//            ans.push_back(a);
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    vector<vector<string>>q(n,vector<string>(2));
//    for(int i=0;i<n;i++)
//        cin>>q[i][0]>>q[i][1];
//    vector<int>v=contacts(q);
//    for(int i=0;i<v.size();i++)
//        cout<<v[i]<<" ";
//    cout<<endl;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// TrieNode structure definition
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;  // To store how many names pass through this node

    TrieNode() : count(0) {}
};

// Trie class definition
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Add a contact name to the trie
    void add(const string& name) {
        TrieNode* node = root;
        for (char c : name) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;  // Increment the count at each node
        }
    }

    // Find how many contacts start with the given prefix
    int find(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return 0;  // Prefix not found
            }
            node = node->children[c];
        }
        return node->count;  // Return the count of names starting with this prefix
    }
};

// Main function to process queries
vector<int> contacts(vector<string>& queries) {
    Trie trie;
    vector<int> results;

    // Process each query
    for (const string& query : queries) {
        string operation = query.substr(0, query.find(" "));
        string value = query.substr(query.find(" ") + 1);

        if (operation == "add") {
            trie.add(value);  // Add the contact name to the trie
        } else if (operation == "find") {
            results.push_back(trie.find(value));  // Find the number of contacts starting with the prefix
        }
    }

    return results;
}

int main() {
    int n;
    cin >> n;
    vector<string> queries(n);

    // Input the queries
    cin.ignore();  // To ignore the newline after reading the number of queries
    for (int i = 0; i < n; ++i) {
        getline(cin, queries[i]);
    }

    // Get the results for the find operations
    vector<int> result = contacts(queries);

    // Output the results
    for (int count : result) {
        cout << count << endl;
    }

    return 0;
}
