/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcalculator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:29 by vpeinado          #+#    #+#             */
/*   Updated: 2025/05/06 22:46:06 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

/*
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

void print_binary(unsigned int n)
{
    int i = 32;
    while (i--)
    {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0 && i != 0)
            printf(".");
    }
}


void ipcalc(char *ip, char *subnet)
{
    /*
    * 'struct in_addr' es una estructura que contiene una dirección IP en formato binario.
    *  dentro de esta estructura, 's_addr' es un campo que contiene la dirección IP en formato binario y
    *  en el orden de bytes de red (big-endian).
    *  uint32_t s_addr
    */
    struct in_addr ip_addr;
    struct in_addr subnet_addr;
    struct in_addr network_addr;
    struct in_addr broadcast_addr;
    struct in_addr first_host;
    struct in_addr last_host;

    /*
    * 'inet_aton' convierte la dirección IP en formato de cadena en una estructura de dirección de red en formato binario.
    Su argumentos son:
        - ip: La dirección IP en formato de cadena.
        - &ip_addr: La dirección de la estructura de dirección de red en formato binario.
    Su diferencia con 'inet_pton' es mas moderna y puedes diferenciar entre ipv4 y ipv6, mientras que inet_aton es especifica para ipv4.
    
    */
    inet_aton(ip, &ip_addr);
    inet_aton(subnet, &subnet_addr); 

    /*
    * Se realizaran diferentes operaciones para obtener la dirección de red, la dirección de broadcast, la primera dirección de host y la última dirección de host.
    * 'network_addr' es la dirección de red, que se obtiene aplicando la operación AND bit a bit entre la dirección IP y la máscara de subred.
    * 'broadcast_addr' es la dirección de broadcast, que se obtiene aplicando la operación OR bit a bit entre la dirección de red y la negación de la máscara de subred.
    * 'first_host' es la primera dirección de host, que es la dirección de red más uno.
    * 'last_host' es la última dirección de host, que es la dirección de broadcast menos uno.
    */
    network_addr.s_addr = ip_addr.s_addr & subnet_addr.s_addr;
    broadcast_addr.s_addr = network_addr.s_addr | ~subnet_addr.s_addr;
    /*
    * 'ntohl' convierte la dirección IP de formato network a formato de host, para realizar la operacion aritmetica.
    * 'htonl' convierte la dirección IP de formato host a formato de red.
    * Esto se hace para realizar la operacion aritmetica, porque la direccion IP esta en formato de red, es decir, 
    * cualquier operacion se hara en el bit mas significativo, y no en el bit menos significativo.
    * Ejemplo: 192.168.1.1 + 1 en formato de red, seria 193.168.1.1 y no conseguiremos el resultado esperado.
    * Por lo tanto, se convierte la direccion IP a formato de host, para realizar la operacion aritmetica y luego se convierte a formato de red.
    * Usaremos 'inet_ntoa' para convertir la direccion IP de formato binario a formato de cadena, para imprimirlo.
    */
    first_host.s_addr = htonl(ntohl(network_addr.s_addr) + 1);
    last_host.s_addr = htonl(ntohl(broadcast_addr.s_addr) - 1);
    printf("%s%sIP Address:%s %s\n", BOLD, BLUE, RESET, inet_ntoa(ip_addr));
    printf("%sIP en binario:%s\n ", BLUE, RESET);
    print_binary(ntohl(ip_addr.s_addr));
    printf("\n%s%sSubnet Mask:%s %s\n", BOLD, MAGENTA, RESET, inet_ntoa(subnet_addr));
    printf("%sSubnet en binario:%s\n ", MAGENTA, RESET);
    print_binary(ntohl(subnet_addr.s_addr));
    printf("\n%s%sNetwork Address:%s %s\n", BOLD, CYAN, RESET, inet_ntoa(network_addr));
    printf("%s%sBroadcast Address:%s %s\n", BOLD, YELLOW, RESET, inet_ntoa(broadcast_addr));
    printf("%s%sFirst Host:%s %s\n", BOLD, GREEN, RESET, inet_ntoa(first_host));
    printf("%s%sLast Host:%s %s\n", BOLD, GREEN, RESET, inet_ntoa(last_host));
}
