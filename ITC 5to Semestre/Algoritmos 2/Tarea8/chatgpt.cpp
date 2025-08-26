#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

const int MAX_NODES = 512;

bool parse_tree(const string &input, vector<int> &tree, vector<bool> &filled) {
    stringstream ss(input);
    string token;
    bool complete = true;
    
    while (getline(ss, token, ')')) {
        if (token.empty() || token == "(") continue;
        
        // Remove leading '('
        token.erase(0, 1);
        
        size_t comma_pos = token.find(',');
        int value = stoi(token.substr(0, comma_pos));
        string path = token.substr(comma_pos + 1);
        
        // Determine the index in the tree array
        int index = 0;
        for (char dir : path) {
            if (dir == 'L') {
                index = 2 * index + 1;
            } else if (dir == 'R') {
                index = 2 * index + 2;
            }
            // Ensure we don't go out of bounds
            if (index >= MAX_NODES) {
                complete = false;
                break;
            }
        }
        
        if (filled[index]) {
            complete = false; // Node already filled
        } else {
            tree[index] = value;
            filled[index] = true;
        }
    }
    
    // Check if the tree is complete (all nodes from root to leaves should be filled)
    for (int i = 0; i < MAX_NODES; ++i) {
        if (filled[i]) {
            if (i != 0 && !filled[(i - 1) / 2]) { // Check parent node is filled
                complete = false;
            }
        }
    }
    
    return complete;
}

void print_breadth_first(const vector<int> &tree, const vector<bool> &filled) {
    queue<int> q;
    q.push(0);
    bool first = true;

    while (!q.empty()) {
        int index = q.front();
        q.pop();
        
        if (index < MAX_NODES && filled[index]) {
            if (!first) {
                cout << " ";
            }
            cout << tree[index];
            first = false;

            // Push left and right children to the queue
            q.push(2 * index + 1);
            q.push(2 * index + 2);
        }
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    cin.ignore(); // Ignore newline after k

    for (int t = 0; t < k; ++t) {
        string input;
        getline(cin, input);
        
        vector<int> tree(MAX_NODES, -1);
        vector<bool> filled(MAX_NODES, false);
        
        bool complete = parse_tree(input, tree, filled);
        
        if (complete) {
            print_breadth_first(tree, filled);
        } else {
            cout << "INCOMPLETE" << endl;
        }
    }
    
    return 0;
}

