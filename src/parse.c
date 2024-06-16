/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:19:33 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/16 17:16:50 by vpeinado         ###   ########.fr       */
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

int valid_subnet(char *subnet)
{
    struct in_addr addr;
    
    /*
    * Usaremos la función 'inet_pton' para convertir la dirección IP en formato de cadena en una estructura de dirección de red en formato binario.
     Sus argumentos son:
         - AF_INET: Indica que la dirección IP es de tipo IPv4.
        - subnet: La dirección IP en formato de cadena.
        - &addr: La dirección de la estructura de dirección de red en formato binario.
    */
    if (inet_pton(AF_INET, subnet, &addr) == -1)
        return (1);
    if (is_cidr(subnet))
        return (1);
    return (0);
}

int valid_args(char *ip, char *subnet)
{
    struct in_addr addr;
    
    if (ip == NULL || subnet == NULL)
    {
        printf("Error: Missing arguments\n");
        return (0);
    }
    if (inet_pton(AF_INET, ip, &addr) == -1)
    {
        printf("Error: Invalid IP\n");
        return (0);
    }
    if (!valid_subnet(subnet))
    {
        printf("Error: Invalid Subnet\n");
        return (0);
    }
    return (1);
}