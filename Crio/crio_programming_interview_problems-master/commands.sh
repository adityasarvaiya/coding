# generate the util jar file
./make_jar.sh

# compile and execute a given problem
cd RemoveNthNodeFromEndOfList
javac -cp ..:crio.jar RemoveNthNodeFromEndOfList.java
java -cp .:..:crio.jar RemoveNthNodeFromEndOfList