APP=./app
all:
	gcc main.c -o app
	gcc unit.c -o tester
tests:
	rm output.txt 2>/dev/null
	./tester $(APP)
clean:
	rm tester app
