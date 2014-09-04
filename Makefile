# makefile

binaries= arraySpiral fibo

GXX=g++ -O2 -Wall

all: arraySpiral fibo

arraySpiral:
	$(GXX) arraySpiral.cpp -o $@

fibo:
	$(GXX) fibo.cpp -o $@

clean:
	rm -f $(binaries)
