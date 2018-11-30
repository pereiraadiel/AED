data ClienteQChega = Nao | Sim TempoQChegou TempoPAtend
type TempoQChegou  = Int
Type TempoPAtend   = Int

data ClienteQSai   = Nenhum
                    |Liberado TempoQChegou TempoDEsp TempoPAtend
type TempoDEsp  = Int

type Fila = [Int]


-- Implemetacao da fila por uma lista
estaVazia :: Fila -> Bool
estaVazia [] = True
estaVazia _  = False

enfileira :: Int -> Fila -> Fila
enfileira a x = x++[a]

desenfileira :: Fila -> (Int,Fila)
desenfileira x
            | not (estaVazia x) = (head x, tail x)
            | otherwise         = error "Erro: A fila esta vazia"


{-- Implementacao da fila por duas listas
 estaVazia ([], []) = True
 estaVazia _        = False

 enfileira a (l,r)  = (l,(a:r))

 desenfileira ((a:l),r) = (a,(l,r))
 desenfileira ([], [])  = error "Erro: A fila esta vazia"
 desenfileira ([], r)   = desenfileira (reverse r, [])

--}
adicionaCliente :: ClienteQChega -> EstadoDaFila -> EstadoDaFila
adicionaCliente m (tempo, tempoPatend, ml) = (tempo, tempoPatend, ml++[m])

processaFila :: EstadoDaFila -> (EstadoDaFila,[ClienteQSai])
processaFila (tempo, tempoPatend, (Sim a tempoNeededPatend:resto)
  | tempoPatend < tempoNeededPatend = 
    ((tempo+1),tempoNeededPatend+1,((Sim a tempoNeededPatend::resto),[]))
  | otherwise =
    ((tempo+1,0,resto),[Liberado a (tempo-tempoNeededPatend-a) tempoNeededPatend])

processaFila (tempo, tempoPatend, []) = ((tempo+1, tempoPatend, []),[])

filaDeInicio :: EstadoDaFila 
filaDeInicio  = (0,0,[])

tamanhoDaFila :: EstadoDaFila -> Int
tamanhoDaFila (tempo, tempoPatend, l) = length l

filaVazia :: EstadoDaFila -> Bool
filaVazia (t,s,q) = (q == [])

type Tempo            = Int 
type EstadoDaFila     = (Tempo, TempoPAtend, [ClienteQChega])
type EstadoDoServidor = [EstadoDaFila]

colocaNumaFila :: Int -> ClienteQChega -> EstadoDoServidor -> EstadoDoServidor
colocaNumaFila n im st
        = take n st
          ++ [novoEstadoDaFila]
          ++ drop (n+1) st
          where
          	novoEstadoDaFila = adicionaCliente im (st!!n)

processaServidor :: EstadoDoServidor -> (EstadoDoServidor,[ClienteQSai])
processaServidor [] = ([], [])
processaServidor (q:qs) = ((nq:nqs),mess ++messes)
                 where
                 	(nq,mess) = processaFila q
                 	(nqs, messes) = processaServidor qs

processaSimulacao :: EstadoDoServidor -> ClienteQChega -> (EstadoDoServidor,[ClienteQSai])
processaSimulacao estServ im = (adicionaNovoObjeto im estServ1 , clienteQSai)
                  where
                  	(estServ1,clienteQSai) = processaServidor estServ

adicionaNovoObjeto :: ClienteQChega -> EstadoDoServidor -> EstadoDoServidor
adicionaNovoObjeto Nao estServ = estServ
adicionaNovoObjeto (Sim tempoChegada tempoNeededPatend) estServ = 
                   colocaNumaFila (menorFila estServ) (Sim tempoChegada tempoNeededPatend)

tamanhoDoServidor :: EstadoDoServidor -> Int

menorFila :: EstadoDoServidor -> Int
