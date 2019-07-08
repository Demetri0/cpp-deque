all:
	g++ -Wall deque_test.cpp -o deque_test

test: deque_test
	./deque_test
