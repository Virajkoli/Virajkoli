import socket

def start_udp_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(('0.0.0.0', 9998))
    print("UDP Server listening on port 9998")

    while True:
        try:
            # Receive data from client
            data, addr = server.recvfrom(1024)
            data = data.decode('utf-8')
            print(f"Received from {addr}: {data}")
            
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
            else:
                result = "Error: Invalid operation"
            
            # Send result back to client
            server.sendto(str(result).encode('utf-8'), addr)
        
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    start_udp_server()
