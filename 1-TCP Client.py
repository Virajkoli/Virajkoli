import socket

def start_tcp_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('127.0.0.1', 9999))  # Change IP to server's IP address
    
    while True:
        try:
            # Input operation and numbers
            operation = input("Enter operation (+, -, *, / ,%): ")
            num1 = input("Enter first number: ")
            num2 = input("Enter second number: ")

            # Send operation and numbers to the server
            client.send(f"{operation},{num1},{num2}".encode('utf-8'))

            # Receive the result from the server
            result = client.recv(1024).decode('utf-8')
            print(f"Result: {result}")
        
        except KeyboardInterrupt:
            print("Client disconnected")
            break

    client.close()

if __name__ == "__main__":
    start_tcp_client()
