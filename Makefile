# Projekt: Algoritmy Math Expression Evaulation
# Autor:   Přemysl Poláš
# Datum:   15.05.2022

CC = g++
CFLAGS = -Wall -Wextra -g
 
main: main.o Solution.o ExpressionParser.o Queue.o Stack.o Node.o
	$(CC) $(CFLAGS) -o main main.o Solution.o ExpressionParser.o Queue.o Stack.o Node.o
