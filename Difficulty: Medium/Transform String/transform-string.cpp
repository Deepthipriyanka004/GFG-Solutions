class Solution {
	public:
	int transform(string &s1, string &s2) {
		// code here
		int arr[128] {0};
		if (s1.size() != s2.size())return - 1;
		// checking anagrams
		for (auto i:s1)arr[i]++;
		for (auto i: s2)arr[i]--;
		for (int i = 0 ; i<128 ; i++) {
			if (arr[i])return - 1;
		}
		int j = s1.size() - 1, count = 0;
		for (int i = s1.size() - 1 ; i >= 0 ; i--) {
			while (j >= 0 && s1[j] != s2[i])j--;
			if (j >= 0) {
				count++;
				j--;
			} else{
			    break;
			}
		}
		return s1.size() - count;
	}
};