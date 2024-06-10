/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:29:54 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/10 21:47:14 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

int main(int argc, char **arg)
{
    if (arg == 3 && valid_args(arg[1], arg[2]))
        ipcalc(arg[1], arg[2]);
    else
    {
        printf("Invalid arguments\n");
        printf("Usage: ./IPcalculator [Ip] [Subnet or CDIR] \n");
    }
    return (0);
}

