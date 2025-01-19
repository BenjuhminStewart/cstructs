main: src/main.c
	gcc -o main src/main.c
	./main
clean:
	rm main
	echo "Removed './main'"
