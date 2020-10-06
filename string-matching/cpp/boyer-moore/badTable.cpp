#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	
	char pattern[] = {"test"};
	int patternLength = (int) sizeof(pattern) / sizeof(pattern[0]) - 1;
	
	// bad match table
	unordered_map<char, int> table;
	int i = -1;
	while(pattern[++i]) {
		//bad match condition
		int val = patternLength - i - 1;
		auto search = table.find(pattern[i]);
		if(search != table.end()) {
			search->second = val > 1 ? val : 1;
			continue;
		}
		table.insert(make_pair(pattern[i], (val > 1) ? val : 1));
	}
	
	table.insert({'*', patternLength});
	
	for(const auto& n : table) {
		cout << n.first << " " << n.second << endl;
	}
	
	return 0;
}
