class Solution {
	public:
		string convert(string s, int numRow){

			if(numRow == 1) return s;

			vector<string> rows(min(s.size(), numRow));
			int curRow = 0;
			bool goingDown = false;

			for(char c : s){
				rows[curRow] += c;
				if(curRow == 0 || curRow == numRow - 1) goingDown != goingDown;
				curRow += goingDown? 1 : -1;
			}

			string ret;
			for(string row : rows) ret += row;

			return ret;
		}
}
