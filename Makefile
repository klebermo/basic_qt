# Nome do projeto
TARGET=program

# Compilador
CC=g++

# Flags para o compilador
CFLAGS=-c -Wall -fPIC

# Diretórios para arquivos de cabeçalho
INCLUDES=-I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets

# Bibliotecas a serem linkadas
LIBS=-lQt5Core -lQt5Gui -lQt5Widgets

all: $(TARGET)

$(TARGET): menu.o toolbar.o statusbar.o main.o
	$(CC) menu.o toolbar.o statusbar.o main.o -o $(TARGET) $(LIBS)

menu.o: src/menu.cpp
	$(CC) $(CFLAGS) $(INCLUDES) src/menu.cpp -o menu.o

toolbar.o: src/toolbar.cpp
	$(CC) $(CFLAGS) $(INCLUDES) src/toolbar.cpp -o toolbar.o

statusbar.o: src/statusbar.cpp
	$(CC) $(CFLAGS) $(INCLUDES) src/statusbar.cpp -o statusbar.o

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) src/main.cpp -o main.o

clean:
	rm -rf *.o $(TARGET)
