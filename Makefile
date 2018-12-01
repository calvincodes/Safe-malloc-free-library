CC=gcc
WARNING_FLAGS = -Wall -Wextra -g -O0
SCAN_BUILD_DIR = scan-build-out
EXE=output

all: main.o Driver.o TreeNode.o
	$(CC) -o $(EXE) main.o Driver.o TreeNode.o

# main.c is your testcase file name
main.o: main.c
	$(CC) -Wall -Wextra -c main.c

# Include all your .o files in the below rule
obj: Driver.o TreeNode.o

Driver.o: Driver.c Driver.h
	$(CC) $(WARNING_FLAGS) -c Driver.c

TreeNode.o: TreeNode.c TreeNode.h
	$(CC) $(WARNING_FLAGS) -c TreeNode.c

clean:
	-rm *.o $(EXE)

scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html