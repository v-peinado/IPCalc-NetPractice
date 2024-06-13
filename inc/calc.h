/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:31:23 by vpeinado          #+#    #+#             */
/*   Updated: 2024/06/13 10:27:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* 
arpa/inet.h es una biblioteca de C que proporciona funciones para manipular direcciones de red en formato binario y de texto.
*/
#include <arpa/inet.h>


int valid_args(char *ip, char *subnet);
void ipcalc(char *ip, char *subnet);