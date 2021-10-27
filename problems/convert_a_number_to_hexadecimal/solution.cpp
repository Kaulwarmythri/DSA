class Solution {
public:
    string toHex(int num) {
         if(num==0){
			return "0";
		}
		unsigned int num1 = num;
		vector<char> help = {'a','b','c','d','e','f'};
		string answer = "";
		while(num1>0){
			int rem = num1%16;
			num1/=16;

			if(rem>9){
				rem-=10;
				answer+=help[rem];
			}else{
				answer+=to_string(rem);
			}
		}


		for(int i = 0; i<answer.size()/2; i++){
			swap(answer[i],answer[answer.size()-i-1]);
		}
		return answer;
        
    }
};




