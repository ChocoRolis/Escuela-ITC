#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a); i < (b); ++i)
#define rf(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
#define ll long long 
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

using namespace std;

typedef struct node {
	int val;
	struct node* left;
	struct node* right;
} Node;

Node* new_Node()
{
        Node *new_node = (Node*) malloc(sizeof(Node));
        
        new_node->val = -1;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
}

void free_tree(Node* root)
{
	if (!root) { return; }

	free_tree( root->left );
	free_tree( root->right );

	free(root);
}

void insert(Node* root, int val, string pos) // Transversing tree
{
        for (char c : pos)
        {
                if ( c == 'L' )
		{
			if (!root->left)
			{
				root->left = new_Node();
			}

			root = root->left;
		}
                if ( c == 'R' )
		{
			if (!root->right)
			{
				root->right = new_Node();
			}

			root = root->right;
		}
        }

	if (root->val >= 0)
	{
		root->val = -2; // -2 means duplicate
		return;
	}

	if (root->val == -1)
	{
		root->val = val;
	}
}

void read_line(string& line, Node* root)
{
	int i = 0;
	string pos = "";
	string num = "";
	
	while (line[i] != '('  ||  line[i+1] != ')') // End when "()" is found
	{
		pos.clear();
		num.clear();

		++i;

		while (isdigit( line[i] ))
		{
			num += line[i++];
		}

		++i;

		while (isalpha( line[i] ))
		{
			pos += line[i++];
		}

		insert(root, stoi(num), pos);

		++i;
	}
}

bool tree_is_possible(Node* root, vi& result) // BFS algorithm
{
	queue<Node*> nodes;

	nodes.push(root);

	while (!nodes.empty())
	{
		if (nodes.front()->left != NULL)
		{
			nodes.push( nodes.front()->left );
		}
		if (nodes.front()->right != NULL)
		{
			nodes.push( nodes.front()->right );
		}

		if ( nodes.front()->val < 0 ) // Tree is not possible when val is -1 or -2
		{
			return false;
		}

		result.pb( nodes.front()->val );

		nodes.pop();
	}

	return true;
}

void solve()
{
	string line;
	Node* root = new_Node();
	vi result;

	getline(cin, line);

	read_line(line, root);

	if ( tree_is_possible(root, result) )
	{
		cout << result[0];

		f(i, 1, result.size())
		{
			cout << " " << result[i]; 
		}

		cout << endl;
	}
	else
	{
		cout << "INCOMPLETE\n";
	}

	free_tree(root); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	cin.ignore(); 

	while (T--)
	{
		solve();
	}
}
