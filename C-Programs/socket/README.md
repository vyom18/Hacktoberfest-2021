# Basic Socket Program
It's a basic socket program where server continously listen for a message and when it receives it will response with ok.
Whereas client can only send a single message after that it will close the connection. The purpose of this program is to demonstrate
how to create socket, bind address, listen for new connection and accept it.

# Usage
## Server
* Compile the server
```bash
./build_server.sh
```
* And run it by passing it port num as arg
```bash
./server 2058
```

## Client
* Compile the client
```bash
./build_client
```

* And run it by passing the host and port num where server is listening
```bash
./client 127.0.0.1 2058
```
