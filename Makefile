main: src/main.c
	gcc -o main.exe src/main.c src/linked_list.c src/array_list.c
clean:
	rm "main.exe"
	echo "Removed 'main.exe'"
