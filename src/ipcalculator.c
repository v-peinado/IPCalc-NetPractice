/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipcalculator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:55:29 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/13 10:39:24 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

void ipcalc(char *ip, char *subnet)
{
    struct in_addr ip_addr;
    struct in_addr subnet_addr;
    struct in_addr network_addr;
    struct in_addr broadcast_addr;
    struct in_addr first_host;
    struct in_addr last_host;

    inet_aton(ip, &ip_addr); // inet_aton convierte la dirección IP en formato de cadena en una estructura de dirección de red en formato binario.
    inet_aton(subnet, &subnet_addr); // inet_aton convierte la dirección IP en formato de cadena en una estructura de dirección de red en formato binario.
    network_addr.s_addr = ip_addr.s_addr & subnet_addr.s_addr;
    broadcast_addr.s_addr = network_addr.s_addr | ~subnet_addr.s_addr;
    first_host.s_addr = network_addr.s_addr + 1;
    last_host.s_addr = broadcast_addr.s_addr - 1;;
    printf("IP Address: %s\n", inet_ntoa(ip_addr));
    printf("Subnet Mask: %s\n", inet_ntoa(subnet_addr));
    printf("Network Address: %s\n", inet_ntoa(network_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
    printf("First Host: %s\n", inet_ntoa(first_host));
    printf("Last Host: %s\n", inet_ntoa(last_host));
}
