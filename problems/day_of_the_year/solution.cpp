class Solution {
public:
    int dayOfYear(string date) {
        
        int currDay=0, currMonth=0, currYear=0, dayOfYear=0;
        stringstream ss(date);
        string word;
        while(getline(ss, word, '-')){
            if(currYear==0) currYear = stoi(word);
            else if(currMonth==0) currMonth = stoi(word);
            else currDay = stoi(word);
        }
        dayOfYear+=currDay;
        switch(currMonth) {
            case 12:
                dayOfYear += 30;
            case 11:
                dayOfYear += 31;
            case 10:
                dayOfYear += 30;
            case 9 :
                dayOfYear += 31;
            case 8 :
                dayOfYear += 31;
            case 7 :
                dayOfYear += 30;
            case 6 :
                dayOfYear += 31;
            case 5 :
                dayOfYear += 30;
            case 4 :
                dayOfYear += 31;
            case 3 :
                dayOfYear += (currYear % 4 == 0 || (currYear % 100 == 0 && currYear % 400 == 0)) ? 29 : 28;
            case 2 :
                dayOfYear += 31;
        }        
        
        return dayOfYear;
        
    }
};