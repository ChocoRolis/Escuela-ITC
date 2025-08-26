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

void solve(int n)
{
	bool stack_works = true;
	bool queue_works = true;
	bool pqueue_works = true;

	stack<int> stack_ds; // Stack data structure
	queue<int> queue_ds;
	priority_queue<int> pqueue_ds;

	char operation;
	int num;

	while (n--)
	{
		cin >> operation >> num;

		if (operation == 'i')
		{
			stack_ds.push(num);
			queue_ds.push(num);
			pqueue_ds.push(num);
			
			continue;
		}

		if (num != stack_ds.top())
		{
			stack_works = false;
		}
		if (num != queue_ds.front())
		{
			queue_works = false;
		}
		if (num != pqueue_ds.top())
		{
			pqueue_works = false;
		}
		
		stack_ds.pop();
		queue_ds.pop();
		pqueue_ds.pop();
	}

	if (stack_works  and  !queue_works  and  !pqueue_works)
	{
		cout << "stack\n";
	}
	else if (!stack_works  and  queue_works  and  !pqueue_works)
	{
		cout << "queue\n";
	}	
	else if (!stack_works  and  !queue_works  and  pqueue_works)
	{
		cout << "priority queue\n";
	}
	else if (!stack_works  and  !queue_works  and  !pqueue_works)
	{
		cout << "impossible\n";
	}
	else 
	{
		cout << "uncertain\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	
	while (cin >> T )
	{
		if (!T) { break; }

		solve(T);
	}
}

