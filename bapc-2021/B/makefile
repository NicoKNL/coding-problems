SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

tests=$(sort $(patsubst %.in,%.t,$(wildcard *.in)))

%.t: %.in
	time $(RUN) < $*.in | tee $*.test
	diff $*.test $*.ans && echo OK

cpp: RUN=./B
cpp: buildcpp $(tests)

buildcpp:
	g++ -x c++ -Wall -O2 -std=c++17 -pipe -o B B.cpp

python: RUN=python3 B.py
python: $(tests)
