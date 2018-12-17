#!/bin/bash
# tornar executavel: chmod a+x Run.sh
# -----------------------------------
# Adiel Pereira
# -----------------------------------
#
clear
sair=0;
info="Executando script...";

while [ $sair != "1" ]; do
	clear
	echo "$info"
	echo "Selecione uma opcao"
	echo "[1] - Compilar"
	echo "[2] - Executar"
	echo "[3] - Limpar Execucao"
	echo "[0] - Sair"

	read opcao;

	if [ $opcao == "1" ]; then
		# compilar todo codigo
		echo "Compilando..."
		javac *.java -Xlint
		javac Negocio/*.java
		javac GUI/*.java
		javac Dados/*.java
		javac Dados/Generico/*.java

		# mover as classes para executar
		mv *.class ./bin
		mv Negocio/*.class ./bin
		mv GUI/*.class ./bin
		mv Dados/*.class ./bin
		mv Dados/Generico/*.class ./bin
		info="Compilado!";
	elif [ $opcao == "2" ]; then
		# mudar para o diretorio com as classes
		cd bin

		# Executar a classe principal
		echo "Iniciando classe principal..."
		java TestaElementos
		info="Fim da execucao";

		# voltar ao diretorio anterior
		cd ..
	elif [ $opcao == "3" ]; then
		echo "Removendo database"
		rm ALUNO.DB
		echo "Removendo classes"
		rm bin/*.class
		info="Pronto!";
	elif [ $opcao == "0" ]; then
		clear
		sair=1;
		echo "Tchau!"
	elif [ $info != "Executando script..." ]; then
		info="Executando script..."
	fi
done 