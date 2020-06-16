ROOT_DIR=/Users/hardik/Desktop/crio/ME_MASTER_SOLUTIONS/interview_problems_solution
mkdir -p ${ROOT_DIR}/build
cd crio
find . -name "*.java" | xargs javac -d ${ROOT_DIR}/build
cd ${ROOT_DIR}
jar cvf crio.jar -C ${ROOT_DIR}/build .
rm -rf ${ROOT_DIR}/build
