/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:29:54 by vpeinado          #+#    #+#             */
/*   Updated: 2025/05/06 22:47:06 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

int main(int argc, char **argv)
{
    if (argc == 3 && valid_args(argv[1], argv[2]))
    {
        // Convertir CIDR a subnet si es necesario
        if (is_cidr(argv[2]))
        {
            char *subnet = cidr_to_subnet(argv[2]);
            if (subnet) {
                ipcalc(argv[1], subnet);
                free(subnet);  // Liberar la memoria asignada
            }
        }
        else
            ipcalc(argv[1], argv[2]);
    }
    else
    {
        printf("%sInvalid arguments%s\n", RED, RESET);
        printf("%sUsage:%s ./IPcalculator [IP] [Subnet or CIDR] \n", YELLOW, RESET);
        printf("%sExample:%s ./IPcalculator 192.168.1.1 255.255.255.0\n", GREEN, RESET);
        printf("%sExample:%s ./IPcalculator 192.168.1.1 /24\n", GREEN, RESET);
    }
    return (0);
}

