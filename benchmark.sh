# g++ ./stress/stress.cpp -o ./build/stresstest --std=c++14 -pthread
# ./build/stresstest

g++ -Wall -std=c++14 BenchmarkTest.cpp -o BechmarkTest -pthread -lbenchmark -g
./BechmarkTest