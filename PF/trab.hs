{-
	TRABALHO DE PROGRAMACAO FUNCIONAL
	
	1. Obter tempo de espera em uma fila de caixa

	2. Obter numero necessario de caixas para que a espera seja zero

	3. Repetir 1 e 2 usando round-robin

	4. Modelar uma fila para varios caixas (usando EstadoDoServidor como fila)
	
	Aluno......... Adiel Pereira Prado 
	Matricula..... 11721BCC008
 -}


data ClienteQChega = Nao | Sim TempoQChegou TempoPAtend deriving(Show, Read, Eq, Ord)
data CLienteQSai = Nenhum|Liberado TempoQChegou TempoDEsp TempoPAtend deriving(Show, Read, Eq, Ord)

type TempoDEsp = Int
type TempoQChegou = Int
type EstadoDaFila = (Tempo, TempoPAtend,[ClienteQChega])
type EstadoDoServidor = [EstadoDaFila]
type EstadoDoServidor2 = ([EstadoDaFila],[ClienteQChega])
type TempoPAtend = Int
type Tempo = Int
type Fila = [Int]

-- Variaveis para aleatorizar
	seed :: Integer
	seed = 17489

	mult :: Integer
	mult = 25173

	incr :: Integer
	incr = 13849

	modul :: Integer
	modul = 65536

-- Fim Variaveis para aleatorizar 

-- Operacoes basicas da fila
	estaVazia :: Fila -> Bool
	estaVazia [] = True
	estaVazia _  = False

	enfileira :: Int -> Fila -> Fila
	enfileira num fila = fila ++ [num]

	desenfileira :: Fila -> (Int, Fila)
	desenfileira fila
		| not(estaVazia fila) = (head fila, tail fila)
		| otherwise = error "ERRO - A fila esta vazia"

	tamanhoFila :: EstadoDaFila -> Int -- versao menos eficiente
	tamanhoFila (tx,ta,[]) = 0
	tamanhoFila (tx,ta,(x:xs)) = 1 + tamanhoFila(tx, ta, xs)

	tamFila :: EstadoDaFila -> Int
	tamFila (tx,ta,fila) = length fila

	filaVazia :: EstadoDaFila -> Bool
	filaVazia (tx,ta,fila)
		| length fila == 0 = True
		| otherwise = False

	filaVaziaB :: EstadoDaFila -> Bool -- versao menos eficiente
	filaVaziaB (tx,ta,[]) = True
	filaVaziaB (tx,ta,[fila]) = False

-- Fim Operacoes basicas da fila


-- Manipulacao da fila
	adicionarCliente :: ClienteQChega -> EstadoDaFila -> EstadoDaFila
	adicionarCliente cliente(tempo, tempoDeAtendimento, cliente1) =
		(tempo, tempoDeAtendimento,cliente1 ++ [cliente])

	processaFila :: EstadoDaFila -> (EstadoDaFila,[CLienteQSai])
	processaFila(tempo, tempoDeAtendimento, []) = ((tempo+1,tempoDeAtendimento,[]),[])
	processaFila(tempo, tempoDeAtendimento,((Sim a tempoNecDAtend): resto))
		| tempoDeAtendimento < tempoNecDAtend = (((tempo+1),(tempoDeAtendimento+1),((Sim a tempoNecDAtend): resto)),[])
		| otherwise = ((tempo+1, 0, resto),[Liberado a (tempo-tempoNecDAtend-a) tempoNecDAtend])

	insereCliente :: Int -> ClienteQChega -> EstadoDoServidor -> EstadoDoServidor
	insereCliente num cliente servidor = take num servidor ++ [novoEstadoFila] ++ drop(num+1) servidor
		where
			novoEstadoFila = adicionarCliente cliente (servidor!!num)

	processaServidor :: EstadoDoServidor -> (EstadoDoServidor,[CLienteQSai])
	processaServidor [] = ([],[])
	processaServidor(x:xs) = (px:pxs), mess ++ messes)
		where
			(px, mess) = processaFila x
			(pxs,messes) = processaServidor xs

	adicionarObjeto :: ClienteQChega -> EstadoDoServidor -> EstadoDoServidor
	adicionarObjeto Nao estServ = estServ
	adicionarObjeto(Sim tempoChegada tempoNecAtend) estServ = 
		insereCliente(menorFila estServ)(Sim tempoChegada tempoNecAtend) estServ

	menorFila :: EstadoDoServidor -> Int
	menorFila [x] = 0
	menorFila(x:xs)
		| tamanhoFila(xs!!menor) <= tamanhoFila x = menor + 1
		| otherwise = 0
		where
			menor = menorFila xs

-- Fim Manipulacao da fila


-- Inicializacao
    filaInicial :: EstadoDaFila
    filaInicial = (0,0,[])

    estadoInicialServidor :: EstadoDoServidor
    estadoInicialServidor = copy numFilas filaInicial

    copy :: Int -> EstadoDaFila -> EstadoDoServidor -- inicializa numFilas de caixas vazios
    copy numFilas estServ | numFilas == 0 = []
                          | otherwise = [estServ] ++ copy(numFilas-1) estServ

    processaSimulacao :: EstadoDoServidor -> ClienteQChega -> (EstadoDoServidor , [CLienteQSai])
    processaSimulacao estServ cliente = (adicionarObjeto cliente estServ1, clienteQSai)
        where
            (estServ1, clienteQSai) = processaServidor estServ

    -- coloca os clientes que chega na fila de atendimento, processa e coloca em clientes que sai
    simule :: EstadoDoServidor -> [ClienteQChega] -> [CLienteQSai]
    simule estDServ (cliente:messes) = outmesses ++ simule proxEstDServ messes
        where (proxEstDServ, outmesses) = processaSimulacao estDServ cliente

    -- Funcoes randomicas
    	-- nao eh uniforme a geracao de valores e usa composicao de funcoes

    seqRandom :: (Integer -> [Integer])
    seqRandom = iterate proxNumRandom

    proxNumRandom :: Integer -> Integer
    proxNumRandom num = rem(mult*num+incr) modul

    gerarFuncao :: [(a,Float)] -> (Float->a)
    gerarFuncao dist = gerarFun dist 0.0
    gerarFun((ob,p):dist) nUlt aleat | nProx >= aleat && aleat > nUlt = ob
                                     | otherwise = gerarFun dist nProx aleat
                                     where nProx = (p*(fromInteger modul))+nUlt
    
    dist:: Num a => [(a, Float)] -- probabilidade de sair 1 minuto ,2 minutos , ... , etc (1 a 6 minutos)
    dist = [(1,0.2),(2,0.25),(3,0.25),(4,0.15),(5,0.1),(6,0.05)]

    seqTempos :: [TempoPAtend]
    seqTempos =  map((gerarFuncao dist).fromInteger)(seqRandom seed)                                 

    entradaSimulacao = zipWith Sim[1..]seqTempos

    maxClientes :: Int -- maximo de clientes que comporta o supermercado
    maxClientes = 100

    entradaSimulacaoB = take maxClientes entradaSimulacao ++ nots
        where
            nots = (Nao:nots)

-- Fim Inicializacao



-- EXERCICIO UM
    tempoDeEsperaTotal :: ([CLienteQSai]->Int)
    tempoDeEsperaTotal = sum map tempoDEsp
        where tempoDEsp(Liberado _ t _) = t

    --chamada da funcao 
    -- tempoDeEsperaTotal(take 50(simule estadoInicialServidor entradaSimulacao2))    

-- FIM EXERCICIO UM



-- EXERCICIO DOIS
	numFilas :: Int
	numFilas  = 5

	-- o numero de caixas precisa ser 5 para que o tempo de espera seja 0

-- FIM EXERCICIO DOIS



-- EXERCICIO TRES
	circular :: Int -> Int
	circular n = rem n  numFilas

	--definições das questoes anterioemente descritas mas usando o método Round-Robin
	adicionaObjetoCircular :: ClienteQChega -> EstadoDoServidor-> EstadoDoServidor
	adicionaObjetoCircular Nao estServ = estServ
	adicionaObjetoCircular (Sim tempoDeChegada tempoNecAtend) estServ = insereCliente (circular tempoDeChegada) (Sim tempoDeChegada tempoNecAtend) estServ

	processaSimulacaoCircular :: EstadoDoServidor -> ClienteQChega -> (EstadoDoServidor,[ClienteQSai])
	processaSimulacaoCircular estServ cliente = (adicionaObjetoCircular cliente estServ1,clientQSai)
	 where (estServ1,clientQSai) = processaServidor estServ

	simuleCircular :: EstadoDoServidor -> ([ClienteQChega] -> [ClienteQSai])
	simuleCircular estDoServ (cliente:messes) = outmesses ++ simuleCircular proxEstDoServ messes
	 where (proxEstDoServ,outmesses) = processaSimulacaoCircular estDoServ cliente

-- FIM EXERCICIO TRES



-- EXERCICIO QUATRO
-- FIM EXERCICIO QUATRO