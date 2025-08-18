object.o: main.c all_fun.c unity.c
	gcc $^ -c
out:main.o all_fun.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -rf *.o*.out