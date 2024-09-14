import socket

def start_udp_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('127.0.0.1', 9998)  # Change IP to server's IP address

    while True:
        try:
            # Input operation and numbers
            operation = input("Enter operation (+, -, *, /): ")
            num1 = input("Enter first number: ")
            num2 = input("Enter second number: ")

            # Send operation and numbers to the server
            client.sendto(f"{operation},{num1},{num2}".encode('utf-8'), server_address)

            # Receive the result from the server
            data, addr = client.recvfrom(1024)
            print(f"Result: {data.decode('utf-8')}")
        
        except KeyboardInterrupt:
            print("Client disconnected")
            break

    client.close()

if __name__ == "__main__":
    start_udp_client()
