lab06: lab06.o cobra.o
	gcc lab06.o cobra.o -lm -o lab06

lab06.o: lab06.c cobra.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c lab06.c

cobra.o: cobra.c cobra.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c cobra.c

clean:
	rm *.o lab06

.PHONY: testar_tudo
testar_tudo: lab06
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "*****************************************************************" ; \
		echo "Crie ou copie o diretório 'testes' para a mesma pasta do Makefile" ; \
		echo "*****************************************************************" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*_in.txt ; do \
		saida=$$(echo "$$entrada" | sed -re 's/\_in.txt$$/_ans.txt/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\_in.txt$$/_out.txt/' ) ; \
		./lab06 < "$$entrada" > "$$saida" ; \
		echo ; \
		echo "Testando $$entrada: " ; \
		if diff "$$resposta" "$$saida" ;  then \
			echo "OK" ; \
		else \
			echo "***********************************"; \
			echo "Falhou para $$entrada" ; \
			echo "***********************************"; \
			exit 1; \
		fi ; \
	done
