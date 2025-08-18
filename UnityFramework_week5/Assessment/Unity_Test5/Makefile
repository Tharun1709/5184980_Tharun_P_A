
object.o: main.c swap.c unity.c
	gcc $^ -c
out:main.o swap.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -rf *.o*.out