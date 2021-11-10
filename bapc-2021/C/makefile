SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

tests=$(sort $(patsubst %.in,%.t,$(wildcard *.in)))

%.t: %.in
	time $(RUN) < $*.in | tee $*.test
	diff $*.test $*.ans && echo OK

cpp: RUN=./C
cpp: buildcpp $(tests)

buildcpp:
	g++ -x c++ -Wall -O2 -std=c++17 -pipe -o C C.cpp

python: RUN=python3 C.py
python: $(tests)
