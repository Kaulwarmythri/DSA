class TextEditor {
    stack<char> left, right;
    
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto c : text) left.push(c);
    }
    
    int deleteText(int k) {
        int count = 0;
        while(!left.empty() && k > 0) {
            left.pop();
            count++;
            k--;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k > 0) {
            auto c = left.top(); left.pop();
            k--;
            right.push(c);
        }
        return leftLetters();
        
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k > 0) {
            auto c = right.top(); right.pop();
            k--;
            left.push(c);
        }
        return leftLetters();
    }
    
    string leftLetters() {
        int i = 0; string res = "";
        while(!left.empty() && i < 10) {
            auto c = left.top(); left.pop();
            res = c + res;
            i++;
        }
        
        for(auto ch : res) {
            left.push(ch);
        }
        return res;    
    }
    
    
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */