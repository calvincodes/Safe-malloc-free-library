CC=gcc
WARNING_FLAGS = -Wall -Wextra -g -O0
SCAN_BUILD_DIR = scan-build-out
EXE=output

all: main.o 537malloc.o TreeNode.o
	$(CC) -o $(EXE) main.o 537malloc.o TreeNode.o

# main.c is your testcase file name
main.o: advanced_testcase1.c
	$(CC) -Wall -Wextra -o main.o -c advanced_testcase1.c

# Include all your .o files in the below rule
obj: 537malloc.o TreeNode.o

537malloc.o: 537malloc.c 537malloc.h
	$(CC) $(WARNING_FLAGS) -c 537malloc.c

TreeNode.o: TreeNode.c TreeNode.h
	$(CC) $(WARNING_FLAGS) -c TreeNode.c

clean:
	-rm *.o $(EXE)

scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html