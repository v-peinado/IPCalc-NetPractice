# IP Calculator

A simple command-line tool to calculate network parameters based on an IP address and subnet mask.

## Overview

This tool takes an IP address and subnet mask (in decimal or CIDR notation) and calculates:
- Network address
- Broadcast address
- First usable host address
- Last usable host address

## Network Concepts

### IP Addressing

IP addresses are 32-bit numbers (for IPv4) that uniquely identify devices on a network. They are typically represented in dotted-decimal notation (e.g., 192.168.1.1), where each number represents 8 bits (one byte).

### Subnet Masks

Subnet masks divide an IP address into network and host portions. They determine which part of the IP address identifies the network and which part identifies the host.

Example: 255.255.255.0 (11111111.11111111.11111111.00000000 in binary)
- The 1s represent the network portion
- The 0s represent the host portion

### CIDR Notation

CIDR (Classless Inter-Domain Routing) notation is a compact way to represent a subnet mask using a slash followed by the number of network bits.

Example: /24 is equivalent to 255.255.255.0
- /24 means the first 24 bits are the network portion
- The remaining 8 bits are the host portion

### Network Calculations

- **Network Address**: Bitwise AND of IP address and subnet mask
- **Broadcast Address**: Network address with all host bits set to 1
- **First Host**: Network address + 1
- **Last Host**: Broadcast address - 1

## C Libraries and Functions Used

### Network Functions (arpa/inet.h)

- `inet_aton()`: Converts IP address string to binary form
- `inet_ntoa()`: Converts binary IP address to string
- `inet_pton()`: Converts IP address string to binary form (supports IPv6)
- `inet_ntop()`: Converts binary IP address to string (supports IPv6)

### Byte Order Functions (arpa/inet.h)

- `htonl()`: Converts 32-bit integer from host to network byte order
- `ntohl()`: Converts 32-bit integer from network to host byte order

### Standard Library Functions

- `isdigit()`: Checks if a character is a digit (ctype.h)
- `atoi()`: Converts string to integer (stdlib.h)
- `malloc()`: Allocates memory dynamically (stdlib.h)
- `free()`: Frees dynamically allocated memory (stdlib.h)

## Usage

```
./ipcalc [IP] [Subnet or CIDR]
```

Examples:
```
./ipcalc 192.168.1.1 255.255.255.0
./ipcalc 192.168.1.1 /24
```

## Notes on Implementation

- The program handles both standard subnet notation (255.255.255.0) and CIDR notation (/24)
- Byte order conversion is necessary because network protocols use big-endian (network byte order) while some CPU architectures use little-endian (host byte order)
- The binary representations are printed to help visualize the network and host portions