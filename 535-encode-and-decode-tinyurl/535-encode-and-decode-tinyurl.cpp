class Solution {
    map<string, string> m;
    string s = "";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        s += (char) (rand()/RAND_MAX);
        while(m.find(s) != m.end()) 
            s += (char) (rand()/RAND_MAX);
        
        m.insert({s, longUrl});
        
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));