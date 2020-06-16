#! /bin/bash

# Small script to execute the runner over the problems.
# TODO: 
# 1. Allow concept ME to specified from command line.
# 2. Print only the offending files.
# 3. Output a % done, runner takes sometime if there are a lot of problems.

# Concept ME problems
concept_array_problems=(RemoveDuplicatesFromSortedArray ThreeSum ContainerWithMostWater ShortestUnsortedContinuousSubarray LongestSubstringWithAtMostKDistinctCharacter FindAllAnagramsInAString FruitIntoBaskets LongestSubstringWithoutRepeatingCharacter SearchInRotatedSortedArray MedianOfTwoSortedArrays SearchA2DMatrix FindFirstAndLastPositionOfElementInSortedArray NextNumber SwapAllOddAndEvenBits Conversion)
langs=(c++14 python java)

for problem in ${concept_array_problems[@]}
do
  for lang in ${langs[@]}
  do
    cmd="python3 runner.py --problem $problem --lang $lang --run"
    eval $cmd
  done
done

