#include<iostream>
#include<unordered_map>

#define LEN(arr) ((int) sizeof(arr) / sizeof(arr[0]) - 1)

using namespace std;

int main() {
	
	char string[] = {"Finds an element with eyeye that compares equivalent to the value x. This overload only participates in overload resolution if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an instance of Key."};
//	char string[] = {"3105118548  : 4500744628301193799 6274956735 1885752724 8912279381 8301194912  : 500"};
//	char pattern[] = {"830119"};
	char pattern[] = {"eye"};
	int patternLength = LEN(pattern);
	cout << patternLength << endl;
	
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
//	
	// Logic
//	i = -1;
//  3105118548  : 4500744623799
 // 830119
	int count = 0, j = 1, index = -1, stamp = -1;
	auto wildCard = table.find('*');
	i = patternLength - 1;
	while(string[i] || i == -1) { 
//	for(i = patternLength - 1; i < patternLength;) {
//	printf("i is %d %c\n", i , string[i]);
		if(count == patternLength) {
			printf("Pattern found at %d\n", index);
			count = 0;
			i += (patternLength * 2);
			j = 1;
			continue;
		}
		if(string[i] == pattern[patternLength - j]) {
//			printf("Match str %d %c\n",i, string[i]);
			if(j == 1) stamp = i;
//			printf("stamp is %d\n", stamp);
			index = i;
			count++;
			i -= 1;
			j++;
			continue;
		}
		count = 0;
		j = 1;
		
		auto search = table.find(string[i]);
		if(stamp > -1) {
			i = stamp;
			stamp = -1;
		}
		if(search != table.end()) {
//			printf("pat char %c %d\n", search->first, i);
//i = stamp;
			i += search->second;
//			j = 1;
//			count = 0;
			continue;
		}
		i += wildCard->second;
	}
	
	return 0;
}
