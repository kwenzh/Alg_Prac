# 文件名: makefile
SHELL=cmd.exe
OBJS=main.o HelloWorld.o
main: $(OBJS)
        g++ -o hello $(OBJS)
main.o:main.cpp HelloWorld.h
        g++ -c main.cpp
HelloWorld.o: HelloWorld.cpp HelloWorld.h
        g++ -c HelloWorld.cpp
clean:
        del $(OBJS)