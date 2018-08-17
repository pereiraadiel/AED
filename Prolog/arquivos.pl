copia(A1,A2):-
    see(A1),
    tell(A2),
    processa_arquivo,
    seen,    
    told.

processa_arquivo:-
    read(X),
    processa_termo(X).

processa_termo(end_of_file):- !.
processa_termo(X):-
    write(X),
    write('.'),nl,
    processa_arquivo.


 teste :-
 %	tell('dados.pl'), apaga o conteudo atual e escreve novamente
 	append('dados.pl'), % coloca os novos dados no final do arquivo
 	read(Termo),nl,
 	write(Termo),
 	told.

 % get msm de 'c' le um caracter

resposta(R):-
	nl,
	write('Voce eh retardado? (s ou n): '),
	get(Resp),get0(_),
	verifica(Resp,R),!.
resposta(R):-nl,
	write('You cego feladaputa - digite S ou N'),
	resposta(R).

verifica(115,percebe-se).
verifica(83,percebe-se).
verifica(110,ata).
verifica(78,ata).

dobro(X,Y):-
	Y is 2*X.

calcula_dobro:-
	read(X),
	%leia_atomo(X), %usando este nao precisa de colocar o '.' no fim do numero basta teclar enter
	Y is 2*X,
	write('o dobro de '),
	write(X),
	write(' eh '),
	write(Y),
	write('  '),!.

le_atomo(A):-
	le_str(String),
	name(A,String).
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												.																																																																																																														.																																																																																							.																																																			.																																																																																																																																																																																																																																																																																																		