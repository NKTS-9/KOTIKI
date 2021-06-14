#! /bin/bash

echo "#include <iostream>" >./main.cpp
echo "using namespace std;" >>./main.cpp
echo "int main ()" >>./main.cpp
echo "{" >>./main.cpp
echo "cout <<\"Hello,Bogdan!\"<< endl;" >>./main.cpp
echo "return 0;" >>./main.cpp
echo "}" >>./main.cpp


g++ main.cpp -o main.out;
./main.out
