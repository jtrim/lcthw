FLAGS=-Wall -g

all: \
	fun_with_sockets/server \
	ex1/ex1 \
	ex3/ex3 \
	ex4/ex4 \
	ex5/ex5 \
	ex6/ex6 \
	ex7/ex7 \
	ex8/ex8 \
	ex9/ex9 \
	ex10/ex10 \
	ex11/ex11 \
	ex12/ex12 \
	ex13/ex13 \
	ex13/ex13-2 \
	ex14/ex14 \
	ex15/ex15 \
	ex15/pointers \
	ex16/ex16 \
	ex16/ex16-2 \
	ex17/ex17
	ctags -R

clean:
	rm -f \
		fun_with_sockets/server \
		ex1/ex1 \
		ex3/ex3 \
		ex4/ex4 \
		ex5/ex5 \
		ex6/ex6 \
		ex7/ex7 \
		ex8/ex8 \
		ex9/ex9 \
		ex10/ex10 \
		ex11/ex11 \
		ex12/ex12 \
		ex13/ex13 \
		ex13/ex13-2 \
		ex14/ex14 \
		ex15/ex15 \
		ex15/pointers \
		ex16/ex16 \
		ex16/ex16-2 \
		ex17/ex17 \

server: fun_with_sockets/server

