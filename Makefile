# makefile

binaries= arraySpiral.out fibo.out heaps.out permuteChars.out Top4.out floodfill.out

GXX=g++ -O2 -Wall

all: arraySpiral fibo heaps permuteChars Top4 floodfill

arraySpiral:
	$(GXX) arraySpiral.cpp -o $@.out

fibo:
	$(GXX) fibo.cpp -o $@.out

heaps:
	$(GXX) heaps.cpp -o $@.out

permuteChars:
	$(GXX) permuteChars.cpp -o $@.out

Top4:
	$(GXX) Top4.cpp -o $@.out

floodfill:
	$(GXX) floodfill.cpp -o $@.out

clean:
	rm -f $(binaries)
