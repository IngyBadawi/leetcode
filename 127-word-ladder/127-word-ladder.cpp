class Node {
public:
    string word;
    vector<Node*> children;
    
    Node(string s) {
        word = s;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Node *begin = new Node(beginWord);
        vector <Node*> words(wordList.size() + 1);
        words[0] = begin;
        
        // Make words in a node class
        preprocess_words(words, wordList);
        
        // Build adj
        for (int i = 0 ; i < words.size() ; i++) {
            for (int j = i + 1 ; j < words.size() ; j++) {
                if (num_of_differences(words[i]->word, words[j]->word) == 1) {
                    words[i]->children.push_back(words[j]);
                    words[j]->children.push_back(words[i]);
                }
            }
        }
        // print_adj(words);
        
        // Perform BFS
        return bfs(endWord, words);
    }
    
private:
    
    int bfs(string endWord, vector<Node *> &words) {
        map<Node*, bool> vis;
        queue<pair<Node*, int>> q;
        q.push({words[0], 1});
        while(q.size()) {
            Node *curr_node = q.front().first;
            int curr_depth = q.front().second;
            vis[curr_node] = true;
            q.pop();
            for (Node *child : curr_node->children) {
                if (vis.find(child) == vis.end())
                    q.push({child, curr_depth + 1});
                
                if (child->word == endWord) 
                    return (curr_depth + 1);
            }
        }
        return 0;
    }
    
    void print_adj(vector<Node*> &words) {
        for (Node *curr : words) {
            cout<<curr->word<<": ";
            for (Node *child : curr->children) {
                cout<<child->word<<", ";
            }
            cout<<endl;
        }
    }
    
    void preprocess_words(vector<Node *> &words, vector<string> &wordList) {
        for (int i = 0 ; i < wordList.size() ; i++) {
            string word = wordList[i];
            Node *temp = new Node (word);
            words[i + 1] = temp;
        }
    }
    
    int num_of_differences(string s, string t) {
        int diff = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] != t[i])
                diff++;
        }
        return diff;
    }
};