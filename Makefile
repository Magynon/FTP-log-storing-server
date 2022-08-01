all: build

build: client.cpp
	g++ lib_netsockets/src/socket.cc lib_netsockets/src/ftp.cc client.cpp -o client