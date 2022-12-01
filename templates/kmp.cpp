vector<string> get_prefix(string str){
	int n = str.size();
	vector<string> prefix;

	string tmp = ""; tmp += str[0];
	prefix.push_back(tmp);
	for(int i=1; i<n; i++){
		prefix.push_back(prefix.back() + str[i]);
	}
	return prefix;
}

vector<string> get_suffix(string str){
	int n = str.size();
	vector<string> suffix;

	string tmp = ""; tmp += str.back();
	suffix.push_back(tmp);
	for(int i=n-2; i>=0; i--){
		suffix.push_back(str[i] + suffix.back());
	}

	return suffix;
}
