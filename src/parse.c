/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:19:33 by vpeinado          #+#    #+#             */
/*   Updated: 2025/05/06 22:47:53 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

int is_cidr(char *subnet)
{
    int i = 1;
    int nbr = 0;

    if (subnet[0] != '/')
        return (0);
    while (subnet[i])
    {
        if (!isdigit(subnet[i]))
            return (0);
        nbr = nbr * 10 + subnet[i] - '0';
        i++;
    }
    if (nbr < 1 || nbr > 32)
        return (0);
    return (1);
}

char *cidr_to_subnet(char *cidr)
{
    int prefix;
    uint32_t subnet_int = 0;
    char *subnet_str = malloc(16); // Suficiente para "xxx.xxx.xxx.xxx\0"
    struct in_addr subnet_addr;
    
    if (!subnet_str)
        return NULL;
    
    // Convertir el prefijo CIDR a un entero
    prefix = atoi(cidr + 1); // Saltar el carácter '/'
    
    // Crear la máscara basada en el prefijo
    // Ejemplo: /24 -> 0xFFFFFF00 (255.255.255.0)
    if (prefix == 0)
        subnet_int = 0;
    else
        subnet_int = 0xFFFFFFFF << (32 - prefix);
    
    // Convertir a formato de red (big-endian)
    subnet_addr.s_addr = htonl(subnet_int);
    
    // Convertir a formato string
    inet_ntop(AF_INET, &subnet_addr, subnet_str, 16);
    
    return subnet_str;
}

int valid_subnet(char *subnet)
{
    struct in_addr addr;
    
    if (is_cidr(subnet))
        return (1);
    
    /*
    * inet_pton convierte una IP en formato texto a formato binario
    * Retorna 1 en caso de éxito, 0 si la IP no es válida, -1 en caso de error
    */
    if (inet_pton(AF_INET, subnet, &addr) <= 0)
        return (0);
    
    return (1);
}

int valid_args(char *ip, char *subnet)
{
    struct in_addr addr;
    
    if (ip == NULL || subnet == NULL)
    {
        printf("%sError:%s Missing arguments\n", RED, RESET);
        return (0);
    }
    
    if (inet_pton(AF_INET, ip, &addr) <= 0)
    {
        printf("%sError:%s Invalid IP\n", RED, RESET);
        return (0);
    }
    
    if (!valid_subnet(subnet))
    {
        printf("%sError:%s Invalid Subnet\n", RED, RESET);
        return (0);
    }
    
    return (1);
}