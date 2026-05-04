int countAnagrams(string s, string p) {

    unordered_map<char, int> freq;

    for(char c : p){
        freq[c]++;
    }

    int count = freq.size();
    int left = 0, right = 0;
    int k = p.length();
    int ans = 0;

    while(right < s.length()){

        // EXPAND
        if(freq.find(s[right]) != freq.end()){
            freq[s[right]]--;
            if(freq[s[right]] == 0){
                count--;
            }
        }

        // WINDOW SIZE REACHED
        if(right - left + 1 == k){

            // CHECK
            if(count == 0){
                ans++;
            }

            // SHRINK
            if(freq.find(s[left]) != freq.end()){
                if(freq[s[left]] == 0){
                    count++;
                }
                freq[s[left]]++;
            }

            left++;
        }

        right++;
    }

    return ans;
}