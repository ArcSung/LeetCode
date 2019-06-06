class Solution {
public:
	int reverse(int x){
		int ret = 0;
		while(x != 0){
			int pop = x % 10;
			x = x / 10;

			if(ret > INT_MAX/10 || (ret == INT_MAX/10  && pop > 7)) return 0;
			if(ret < INT_MIN/10 || (ret == INT_MIN/10  && pop < 8)) return 0;

			ret = ret * 10 + pop
		}
	}
}
