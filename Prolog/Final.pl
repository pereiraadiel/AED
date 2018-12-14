:- dynamic distancia/3.
:- dynamic goal/1.

abri_arquivo:-
	open('cidades.txt',read, Stream),
	ler_arquivo(Stream),
	close(Stream).

ler_arquivo(Stream):-
	at_end_of_stream(Stream),!.

ler_arquivo(Stream):-
	\+ at_end_of_stream(Stream),
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



retirar_ocorrencia(_,[],[]).
retirar_ocorrencia(Ocorrencia,[Ocorrencia|Resto],Resultado):-
	retirar_ocorrencia(Ocorrencia,Resto,Resultado).
retirar_ocorrencia(Ocorrencia,[Temp|Resto],Resultado):-
	Ocorrencia\=Temp,
	retirar_ocorrencia(Ocorrencia,Resto,R1),
	inserir_cabeca(Temp,R1,Resultado).

comprimir([],[]).
comprimir([Head|Tail],Resultado):-
	comprimir(Tail,R2),
	retirar_ocor(Head,R2,R1),
	inserir_cabeca(Head,R1,Resultado).

inserir_cabeca(Objeto,Resto,[Objeto|Resto]).

listar_cidades:-
	setof(X,Y^caminho(X,Y),Lista1),
	setof(X1,Y1^caminho(Y1,X1),Lista2),
	concatena(Lista1,Lista2,Lista3),
	comprimir(Lista3,Lista),
	length(Lista,Tam),!,
	new(Janela, frame('quantidade_de_cidades')),
	new(Caixa, dialog),
	send(Caixa, append(text_item('Numero de cidades :', Tam))),
	send(Janela, append, Caixa),
	send(Janela, open).
	
concatena([], Lista, Lista). 
concatena([Head |Tail], Lista, [Head | Resto]):-
     concatena(Tail, Lista, Resto). 

inverter([],[]).
inverter([Head|Tail],Resultado):-
inverter(Tail,Result),
append(Result,[Head],Resultado).

solve_prof(Node, Solution):-
	depthfirst([],Node,Solution1),
	inverter(Solution1,Solution).

depthfirst(Path, Node, [Node|Path]):-
	goal(Node).

depthfirst(Path, Node, Sol):-
	distancia(Node,Node1,_),
	\+ member(Node1, Path),
	depthfirst([Node|Path],Node1, Sol).


todos_caminhos(CidadeA,CidadeB):-
	assert(goal(CidadeB)),
	setof(Temp,CidadeA^solve_prof(CidadeA,Temp),List),
	distancia_lista(List, Lista_dist),
	separar(List,Lista_dist,Fim),
	string_to_list(A,List),
	string_to_list(B,Lista_dist),
	janela_caminhos(A, B),
	retractall(goal(_)).
	
janela_caminhos(L, Distancias):-
	new(Janela, frame('Caminhos')),
	%caminhos()
	new(Caixa, dialog),
	send(Caixa, append(text_item('Cidades: ')), % falta alguma coisa
	send(Janela, append, Caixa),
	%send(Janela, open).

%separar([],[],[]).
separar([Head|Tail],[Head1|Tail1],Resultado):-
	append([Head1],[],Lista1),
	append([Head],Lista1,Lista),
	separar(Tail,Tail1,Resultado1),
	%juntar(Lista,Resultado1,Resultado).

distancia_lista([],[]).
distancia_lista([Head|Tail],Resultado):-
	distanciar(Head,Resultado1),
	distancia_lista(Tail,Resultado2),
	juntar(Resultado1,Resultado2,Resultado).

juntar(R1,R2,[R1|R2]).
obter_cabeca([Head|_],Head).

distanciar([_],0).
distanciar([Head|Tail],Resultado):-
	obter_cabeca(Tail,Head1),
	distancia(Head,Head1,Dist1),
	distanciar(Tail,Dist2),
	Resultado is Dist1 + Dist2.




