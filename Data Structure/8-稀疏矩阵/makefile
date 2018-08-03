# 文件名: makefile
CC = gcc
OBJS=demo.o SparseMatrix.o
main: $(OBJS)
				$(CC) $(OBJS) -o get
demo.o: demo.c SparseMatrix.h
				$(CC) -c demo.c
SparseMatrix.o: SparseMatrix.c SparseMatrix.h
				$(CC) -c SparseMatrix.c
clean:
				rm -rf main $(OBJS)
