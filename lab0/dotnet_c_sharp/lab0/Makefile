APP=./app.exe
all:
	mcs main.cs -out:$(APP)
	gcc unit.c -o tester
tests:
	./tester $(APP)
clean:
	rm tester $(APP)
