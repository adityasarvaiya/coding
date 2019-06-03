class Solution:
    # @param A : string
    # @return string
    def reverseWords(self, A):
        
        a = A.split(' ')
        i = 0;
        
        for word in reversed(a):
            if (i == 0) :
                s = word
            else :
                s = s + ' ' + word
        
            i += 1        
        return s
