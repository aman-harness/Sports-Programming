#include <bits/stdc++.h>

using namespace std;
int m ,n;
vector<vector<int>> graph(5001, vector<int>());

map<string, int> line_of_lhs;
vector<pair<string, string>> inp;


map<int, bool> V;
int dfs(int from, stack<int>& stk){
	cout << "from --" <<from << endl;
	if (V[from]) return 1;
	
	for(auto next: graph[from]){
		dfs(next, stk);
	}
	stk.push(from);
	V[from] = 1;
	return 1;
}

vector<int> top_sort(){
	stack<int> stk; std::vector<int> order;

	// for(int i = 1; i <= n; i++){
	// 	cout << i << " ";
	// 	for(auto next: graph[i]) cout << next << " ";
	// 		cout << endl;
	// }

	for(int i = 1; i <= n; i++){
		dfs(i, stk);
	}
	while(!stk.empty()){
		// cout << stk.top() << endl;
		order.push_back(stk.top());
		stk.pop();
	}
	return order;
}
map<int, string> line_values;
int main(){
	char input[100];
	cin >> n >> m;

	string xs = "XOR", as = "AND", cs = "OR", lhs, rhs, temp;
	map<string, int> mp;

	for(int i = 1; i <= n; i++){
		cin >> lhs;
		cin >> temp;
		cin.getline(input,sizeof(input));
		temp = string(input);
		temp = string(input).substr(1);
		// cout << lhs << " " << temp  << endl;
		inp.push_back({lhs, temp});
		mp[lhs] = i;
	}

	for(int i = 0; i < n;i++){
		if(inp[i].second.size() == m && (inp[i].second[0] == '1' || inp[i].second[0] == '0')) {
			line_values[i + 1] = inp[i].second;
			continue;
		}
		else{
			int it = 0;
			string &temp = inp[i].second;
			while(it < temp.size() && temp[it] != ' ') it++;
			string ll = temp.substr(0, it);
			it++;
			while(it < temp.size() && temp[it] != ' ') it++;
			string rr = temp.substr(it + 1);
			// cout << ll << "-" << rr << endl;
			if(ll != string("?")){
				graph[mp[ll]].push_back(i + 1);
			}
			if(rr != string("?")){
				graph[mp[rr]].push_back(i + 1);
			}
		}
	}

	vector<int> order = top_sort();
	std::vector<bool> minv(m, 0);
	for(auto line: order){
		if(line_values.find(line) != line_values.end()) continue;
		else{
			
		}
	}

	return 0;
}
	