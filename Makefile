all: task_1 task_2 task_3 task_5 task_6 task_7 task_8
task_1: base64.o hex.o
task_2: base64.o hex.o crypto.o
task_3: base64.o hex.o crypto.o
task_5: base64.o hex.o crypto.o
task_6: base64.o hex.o crypto.o
task_7: task_7.cpp
	g++ hex.cpp -c -o hex.o
	g++ task_7.cpp -c -o task_7.o
	g++ task_7.o hex.o -o task_7 -lssl -lcrypto
task_8: task_8.cpp

clean:
	rm -f *.o task_1 task_2 task_3 task_5 task_6 task_7 task_8
