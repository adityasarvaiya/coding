# LongestSubstringWithoutRepeatingCharacter Solution
def lengthOfLongestSubstring(s):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    longestSubstringLength = 0
    startIndex = 0
    # to maintain seen char index
    alreadySawChar = {}

    # iterate over input string
    for index in range(len(s)):
        # if we have already seen current character is then update startIndex of ans substring
        if (s[index] in alreadySawChar):
            startIndex = max(alreadySawChar[s[index]], startIndex)
        longestSubstringLength = max(longestSubstringLength, index - startIndex + 1)
        # update dictionary for current character
        alreadySawChar[str(s[index])] = index + 1

    return longestSubstringLength 
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = input()
    result = lengthOfLongestSubstring(s)
    print(result)
