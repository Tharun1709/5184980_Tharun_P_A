object.0: main.c leapyear.c unity.c
	gcc $^ -c
out: main.o leapyear.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -f *.o*.exe