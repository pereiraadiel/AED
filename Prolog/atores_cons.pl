:-dynamic(ator/4).

inicio :-
	repeat,
	consult('atores.pl'),
	write('[1] Listar atores'),nl,
	write('[2] Adicionar ator'),nl,
	write('[3] Remover ator'),nl,
	write('[4] Quantidade de filmes do ator')
	write('[0] SAIR'),nl,
	write('Opcao: '),
	le_atomo(OP),
	(OP=0, write('Flw'), nl;
	executa(OP),fail).

executa(1) :-
	listing(ator/4).

executa(2) :-
	write('Nome do ator: '),
    le_atomo(X),nl,
    write('Nome do filme: '),
    le_atomo(Y),nl,
    write('Ano do filme: '),
    le_atomo(Z),nl,
    write('Digite po rank: '),
    le_atomo(W),nl,
    assertz(ator(X,Y,Z,W)),
    tell('atores.pl'),
    listing(ator/4),
    told.

executa(3) :-
	write('Nome do ator: '),
    le_atomo(X),nl,
    write('Nome do filme: '),
    le_atomo(Y),nl,
    retract(ator(X,Y,_,_)),
    tell('atores.pl'),
    listing(ator/4),
    told.

executa(4) :-
	write('Nome do ator: '),
    le_atomo(X),nl,
    assertz(ator(X,_,_,_)),
    
    tell('atores.pl'),
    listing(ator/4),
    told.

le_atomo(Atomo) :-
    le_str(String),
    name(Atomo, String).

le_str(String) :-
    get0(Char),
    le_str_aux(Char, String).
    le_str_aux(-1, []) :- !. % EOF
    le_str_aux(10, []) :- !. % EOL(UNIX)
    le_str_aux(13, []) :- !. % EOL (DOS)
    le_str_aux(Char, [Char|Resto]) :-
    le_str(Resto).

