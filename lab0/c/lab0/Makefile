APP=./app
all:
	gcc main.c -o app
	gcc unit.c -o tester
tests:
	./tester $(APP)
clean:
	rm tester app
