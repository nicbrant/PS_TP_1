all: programa limpa

programa: main.o calendario.o leituraLocal.o leituraPalestra.o leituraPalestrante.o listaPalestra.o listaPalestrante.o persistencia.o tratamento.o tratamentoLocal.o
	gcc -o programa main.o calendario.o leituraLocal.o leituraPalestra.o leituraPalestrante.o listaPalestra.o listaPalestrante.o persistencia.o tratamento.o tratamentoLocal.o

main.o: main.c calendario.c calendario.h leituraLocal.c leituraLocal.h leituraPalestra.c leituraPalestra.h leituraPalestrante.c leituraPalestrante.h listaLocal.h listaPalestra.c listaPalestra.h listaPalestrante.c persistencia.c persistencia.h tratamento.c tratamento.h tratamentoLocal.c tratamentoLocal.h
	gcc -c main.c

calendario.o: calendario.c calendario.h listaLocal.h tratamento.h
	gcc -c calendario.c

leituraLocal.o: leituraLocal.c leituraLocal.h listaLocal.h
	gcc -c leituraLocal.c

leituraPalestra.o: leituraPalestra.c leituraPalestra.h listaPalestra.h listaLocal.h
	gcc -c leituraPalestra.c

leituraPalestrante.o: leituraPalestrante.c leituraPalestrante.h
	gcc -c leituraPalestrante.c

listaPalestra.o: listaPalestra.c listaPalestra.h
	gcc -c listaPalestra.c

listaPalestrante.o: listaPalestrante.c leituraPalestrante.h
	gcc -c listaPalestrante.c

persistencia.o: persistencia.c persistencia.h tratamento.h listaPalestra.h leituraPalestrante.h listaLocal.h
	gcc -c persistencia.c

tratamento.o: tratamento.c tratamento.h listaLocal.h listaPalestra.h leituraPalestrante.h
	gcc -c tratamento.c

tratamentoLocal.o: tratamentoLocal.c tratamentoLocal.h tratamento.h listaLocal.h
	gcc -c tratamentoLocal.c

limpa:
	rm *.o
