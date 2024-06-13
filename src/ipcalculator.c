/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcalculator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:29 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/13 11:17:23 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

/*
* la libreria 'arpa/inet.h' es una biblioteca de C que proporciona funciones para manipular direcciones de red en formato binario y de texto.
* 'inet_aton' convierte la dirección IP en formato de cadena en una estructura de dirección de red en formato binario.
* 'inet_ntoa¡ convierte la dirección de red en formato binario en una dirección IP en formato de cadena.
* 's_addr' es un campo de la estructura in_addr que contiene la dirección IP en formato binario.
* 'inet_pton' convierte la dirección IP en formato de cadena en una estructura de dirección de red en formato binario.
* usaremos ntohl para convertir la dirección IP de formato network a formato de host, para realizar la operacion aritmetica.
* una vez hecha la operacion aritmetica, usaremos htonl para convertir la dirección IP de formato host a formato de red.
Que significa formato de host y formato de network?
Formato de Host y Formato de Red:
 * - Formato de Red (Network Byte Order): Big-endian, donde el byte más significativo 
 *   (MSB) se almacena en la dirección de memoria más baja. Este es el estándar para 
 *   la transmisión de datos a través de redes.
 * - Formato de Host (Host Byte Order): Puede ser big-endian o little-endian, 
 *   dependiendo de la arquitectura del sistema. En sistemas little-endian (como x86), 
 *   el byte menos significativo (LSB) se almacena en la dirección de memoria más baja.
 * 
 * Las funciones 'htonl' y 'ntohl' se usan para convertir entre estos dos formatos:
 * - 'htonl': Convierte un número de 32 bits del formato de host al formato de red.
 * - 'ntohl': Convierte un número de 32 bits del formato de red al formato de host.
 
*/

void ipcalc(char *ip, char *subnet)
{
    struct in_addr ip_addr;
    struct in_addr subnet_addr;
    struct in_addr network_addr;
    struct in_addr broadcast_addr;
    struct in_addr first_host;
    struct in_addr last_host;

    inet_aton(ip, &ip_addr);
    inet_aton(subnet, &subnet_addr); 
    network_addr.s_addr = ip_addr.s_addr & subnet_addr.s_addr;
    broadcast_addr.s_addr = network_addr.s_addr | ~subnet_addr.s_addr;
    first_host.s_addr = htonl(ntohl(network_addr.s_addr) + 1);
    last_host.s_addr = htonl(ntohl(broadcast_addr.s_addr) - 1);
    printf("IP Address: %s\n", inet_ntoa(ip_addr));
    printf("Subnet Mask: %s\n", inet_ntoa(subnet_addr));
    printf("Network Address: %s\n", inet_ntoa(network_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
    printf("First Host: %s\n", inet_ntoa(first_host));
    printf("Last Host: %s\n", inet_ntoa(last_host));
}
