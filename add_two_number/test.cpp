vector<int> AddTwoSum(vector<int>, int target){
	vector<int> ans;
	map<int, int> hashMap;
	map<int, int>::iterator iter;

	for(int i = 0; i < num.size(); i++){
		iter = hashMap.find(target - num[i]);

		if(iter != hashMap.end()){
			ans.push_back(iter->second);
			ans.push_back(i);
			return ans;
		}else{
			hashMap.insert(pair<int, int>(num[i], i));
		}
	}

	return ans;
}
