PY = python3
PYFLAGS = 
DOC = doxygen
DOCFLAGS = 
DOCCONFIG = docConfig

SRC = partner/testCalc.py

.PHONY: all test doc clean

test: 
	$(PY) $(PYFLAGS) $(SRC)

doc: 
	$(DOC) $(DOCFLAGS) $(DOCCONFIG)
	cd latex && $(MAKE)

all: test doc

clean:
	rm -rf html
	rm -rf latex
