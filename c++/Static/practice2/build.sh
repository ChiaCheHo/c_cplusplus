# g++ a.cpp b.cpp main.cpp --std=c++11 -g -Wall -o test
# 產出 main.o
g++ -c main.cpp
# 產出 a.o
g++ -c a.cpp
# 產出 b.o 
g++ -c b.cpp
# 把 main.o, a.o, b.o link 成 main
g++ -o main main.o a.o b.o