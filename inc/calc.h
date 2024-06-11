/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:31:23 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/11 23:19:05 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
arpa/inet.h es una biblioteca de C que proporciona funciones para manipular direcciones de red en formato binario y de texto.
*/
#include <arpa/inet.h>

void ipcalc(char *ip, char *subnet);