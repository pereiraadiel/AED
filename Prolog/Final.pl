:- dynamic distancia/3.
:- dynamic goal/1.

abri_arquivo:-
	open('cidades.txt',read, Stream),
	ler_arquivo(Stream),
	close(Stream).

ler_arquivo(Stream):-
	at_end_of_stream(Stream),!.

ler_arquivo(Stream):-
	/+ at_end_of_stream(Stream),
	ler_palavra(Stream,PCidade),
	ler_palavra(Stream,SCidade),
	ler_palavra(Stream,Dist),
	atom_number(Dist,Distancia),
	assert(distacia(PCidade, SCidade, Distancia)),
	ler_arquivo(Stream).

ler_palavra(Stream, Palavra):-
	get_code(Stream, Caracter),
	ler_resto(Caracter, Caracteres, Stream),
	atom_codes(Palavra, Caracteres).

ler_resto(10, [], _):- !. % new line
ler_resto(32, [], _):- !. % space
ler_resto(-1, [], _):- !. % End
ler_resto(Caracter,[Caracter|Caracteres], Stream):-
	get_code(Stream,Proximo),
	ler_resto(Proximo,Caracteres,Stream).


caminho(CidadeA, CidadeB):-
	distancia(CidadeA,CidadeB,_).

caminho(CidadeA, CidadeB):-
	distancia(CidadeA, CidadeB, _),
	caminho(CidadeB, CidadeA).

distancia_caminhos(CidadeA, CidadeB, Distancia):-
	distancia(CidadeA, CidadeB, Distancia).

distancia_caminhos(CidadeA, CidadeB, Distancia):-
	distancia(CidadeA, CidadeC, Dist),
	distancia_caminhos(CidadeC, CidadeB, Dist1),
	Distancia is Dist1 + Dist. 

caminhos(CidadeA, CidadeB, Caminho):-
	findall(Caminho1,distancia_caminhos(CidadeA,CidadeB,Caminho1),Caminho).

menor_caminho(CidadeA, CidadeB, Menor):-
	caminhos(CidadeA, CidadeB, Caminho),
	menor_lista(Caminho, Menor).

menor_lista([X],X).

menor_lista([Head|Tail],Menor):-
	menor_lista(Tail, Menor1),
	Head < Menor1,
	Menor is Head.

menor_lista([Head|Tail], Menor):-
	menor_lista(Tail, Menor1),
	Head > Menor1,
	Menor is Menor1.

maior_caminho(CidadeA, CidadeB, Caminho):-
	caminhos(CidadeA, CidadeB, Temp),
	maior_lista(Temp, Caminho).

maior_lista([X],X).

maior_lista([Head|Tail],Maior):-
	maior_lista(Tail, Temp),
	Head < Temp,
	Maior is Temp.

maior_lista([Head|Tail], Maior):-
	maior_lista(Tail, Temp),
	Head > Temp,
	Maior is Head.
	
buscar_menor:-
	new(Janela, frame('Buscar menor caminho')),
	new(Caixa, dialog),
	send(Caixa, append, new(CidadeA, text_item('Primeira cidade:'))),
	send(Caixa, append, new(CidadeB, text_item('Segunda cidade:'))),
	send(Caixa, append(button(buscar, and(message(@prolog, mostra_distancia,
		CidadeA?selection, CidadeB?selection), message(CidadeA, clear),
	    message(CidadeB, clear))))),
	send(Caixa, append, button(sair,message(Janela, destroy))),
	send(Janela, append, Caixa),
	send(Janela, open).

mostra_distancia(CidadeA, CidadeB):-
	menor_caminho(CidadeA, CidadeB, Temp),
	new(Janela, frame('Distancia')),
	new(Caixa, dialog),
	atom_number(Distancia,Temp),
	send(Caixa, append(text_item('Origem: ',CidadeA))),
	send(Caixa, append(text_item('Destino: ',CidadeB))),
	send(Caixa, append(text_item('Menor distancia: ',Distancia))),
	send(Janela, append, Caixa),
	send(Janela, open).


retirar_ocor(_,[],[]).
retirar_ocor(X,[X|Y],R):-
retirar_ocor(X,Y,R).
retirar_ocor(X,[Y|Z],R):-
X\=Y,
retirar_ocor(X,Z,R1),
inserir_cabeca(Y,R1,R).

comprimir([],[]).
comprimir([X|Y],R):-
comprimir(Y,R2),
retirar_ocor(X,R2,R1),
inserir_cabeca(X,R1,R).

inserir_cabeca(X,R,[X|R]).

listar_cidades:-
	setof(X,Y^caminho(X,Y),L1),
	setof(X1,Y1^caminho(Y1,X1),L2),
	concatena(L1,L2,L3),
	comprimir(L3,L),
	length(L,Tam),!,
	new(J, frame('quantidade_de_cidades')),
	new(D, dialog),
	send(D, append(text_item('N de cidades :', Tam))),
	send(J, append, D),
	send(J,open).
	

concatena([], L, L). 
concatena([X | R1], L, [X | R]):-
     concatena(R1, L, R). 

inverter([],[]).
inverter([X|Y],R):-
inverter(Y,R1),
append(R1,[X],R).

solve_prof(Node, Solution):-
	depthfirst([],Node,Solution1),
	inverter(Solution1,Solution).

depthfirst(Path, Node, [Node|Path]):-
	goal(Node).

depthfirst(Path, Node, Sol):-
	distancia(Node,Node1,_),
	\+ member(Node1, Path),
	depthfirst([Node|Path],Node1, Sol).


todos_caminhos(X,Y):-
	assert(goal(Y)),
	setof(H,X^solve_prof(X,H),L),
	distancia_lista(L, Lista_dist),
%	separar(L,Lista_dist,Fim),
	string_to_list(A,L),
	string_to_list(B,Lista_dist),
	janela_caminhos(A, B),
	retractall(goal(_)).
	
janela_caminhos(L, Distancias):-
	new(J, frame('Caminhos')),
	new(D,dialog),
	send(D, append(text_item('Cidades: ', A)),
	send(J, append, D),
	send(J, open).

%separar([],[],[]).
%separar([H|T],[H1|T1],R):-
%	append([H1],[],L1),
%	append([H],L1,L),
%	separar(T,T1,R1),
%	juntar(L,R1,R).


distancia_lista([],[]).
distancia_lista([H|T],R):-
	distanciar(H,R1),
	distancia_lista(T,R2),
	juntar(R1,R2,R).

juntar(R1,R2,[R1|R2]).

distanciar([_],0).
distanciar([H|T],R):-
	retira_cabeca(T,H1),
	distancia(H,H1,Dist1),
	distanciar(T,Dist2),
	R is Dist1 + Dist2.


retira_cabeca([H|_],H).