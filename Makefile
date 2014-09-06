# makefile

binaries= arraySpiral fibo heaps permuteChars Top4 floodfill

GXX=g++ -O2 -Wall

all: arraySpiral fibo heaps permuteChars Top4 floodfill

arraySpiral:
	$(GXX) arraySpiral.cpp -o $@

fibo:
	$(GXX) fibo.cpp -o $@

heaps:
	$(GXX) heaps.cpp -o $@

permuteChars:
	$(GXX) permuteChars.cpp -o $@

Top4:
	$(GXX) Top4.cpp -o $@

floodfill:
	$(GXX) floodfill.cpp -o $@

clean:
	rm -f $(binaries)
