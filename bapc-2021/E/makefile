SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

tests=$(sort $(patsubst %.in,%.t,$(wildcard *.in)))

%.t: %.in
	time $(RUN) < $*.in | tee $*.test
	diff $*.test $*.ans && echo OK

cpp: RUN=./E
cpp: buildcpp $(tests)

buildcpp:
	g++ -x c++ -Wall -O2 -std=c++17 -pipe -o E E.cpp

python: RUN=python3 E.py
python: $(tests)
