all: task_1 task_2
task_1: base64.o hex.o
task_2: base64.o hex.o
clean:
	rm -f *.o task_1 task_2
