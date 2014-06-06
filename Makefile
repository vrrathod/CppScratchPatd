# makefile

binaries= arraySpiral

GXX=g++ -O2 -Wall 

all: arraySpiral

arraySpiral:
	$(GXX) arraySpiral.cpp -o $@

clean:
	rm -f $(binaries)