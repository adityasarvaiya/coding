// IT will return hash of pattern p
unordered_map <char, int> buildHashOfPattern(string p);

hash = buildHashOfPattern(p);

1 iterate over string s
    if char is present in hash
        reduce its count
        if count == 0
            match++ 
    
    if i > pattern size
        char c = s[i - p.size()]
        if c prsent in hash 
            hash[c] += 1

            if hash[c] == 1
                match--
    
    if match is equal to size of hash
        // that means current window contains all the char in pattern p
        add (i - p.size() + 1) to the ans
    

return ans


