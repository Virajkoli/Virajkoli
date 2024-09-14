import socket
import threading

def handle_client(client_socket):
    while True:
        try:
            # Receive the operation and numbers from the client
            data = client_socket.recv(1024).decode('utf-8')
            if not data:
                break

            print(f"Received from client: {data}")
            
            # Extract operation and numbers
            operation, num1, num2 = data.split(',')
            num1 = float(num1)
            num2 = float(num2)
            
            # Perform the operation
            if operation == '+':
                result = num1 + num2
            elif operation == '-':
                result = num1 - num2
            elif operation == '*':
                result = num1 * num2
            elif operation == '/':
                if num2 != 0:
                    result = num1 / num2
                else:
                    result = "Error: Division by zero"
            elif operation == '%':
                result = num1 % num2
            else:
                result = "Error: Invalid operation"
            
            # Send result back to client
            client_socket.send(str(result).encode('utf-8'))
        
        except Exception as e:
            print(f"Error: {e}")
            break

    client_socket.close()

def start_tcp_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('127.0.0.1', 9999))
    server.listen(5)
    print("Server listening on port 9999")

    while True:
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()

if __name__ == "__main__":
    start_tcp_server()
