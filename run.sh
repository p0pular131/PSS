g++ -o $1 $1.cpp
./$1 < input.txt > result.txt
echo "Your output: "
cat result.txt
echo
echo "============================"
echo "Answer: "
cat answer.txt
echo
rm -rf $1