HLI=${FAME}/hli

all: hello benchmark00

hello: hello.c
	gcc -I${HLI} -Wall hello.c -L${HLI} -lchli -o hello

benchmark00: benchmark00.c
	gcc -I${HLI} -Wall benchmark00.c -L${HLI} -lchli -o benchmark00
	