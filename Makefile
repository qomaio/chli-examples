all:
	gcc -I${FAME} -Wall hello.c -L${FAME}/64 -lchli -o hello