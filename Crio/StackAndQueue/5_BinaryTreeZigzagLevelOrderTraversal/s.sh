for((i = 1; i <= 15 ; ++i)); do
   java BinaryTreeZigzagLevelOrderTraversal < ./tests/base-input-$i.txt  > ./tests/base-output-$i.txt
   java BinaryTreeZigzagLevelOrderTraversal < ./tests/sample-input-$i.txt  > ./tests/sample-output-$i.txt
   java BinaryTreeZigzagLevelOrderTraversal < ./tests/edge-input-$i.txt  > ./tests/edge-output-$i.txt
   java BinaryTreeZigzagLevelOrderTraversal < ./tests/perf-input-$i.txt  > ./tests/perf-output-$i.txt
done