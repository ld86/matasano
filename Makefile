all: task_1 task_2 task_3
task_1: base64.o hex.o
task_2: base64.o hex.o crypto.o
task_3: base64.o hex.o crypto.o

clean:
	rm -f *.o task_1 task_2 task_3
