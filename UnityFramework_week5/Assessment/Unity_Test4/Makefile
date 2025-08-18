
object.o: main.c average.c unity.c
	gcc $^ -c
out:main.o average.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -rf *.o*.out