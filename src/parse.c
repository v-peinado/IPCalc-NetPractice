/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:19:33 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/11 23:23:29 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/calc.h"

int valid_args(char *ip, char *subnet)
{
    (void)subnet;
    int i;
    int dots;
    int slash;

    i = 0;
    dots = 0;
    slash = 0;
    while (ip[i])
    {
        if (ip[i] == '.')
            dots++;
        i++;
    }
    i = 0;
    if (dots != 3 || slash != 1)
        return (0);
    return (1);
}