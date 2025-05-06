/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:31:23 by vpeinado          #+#    #+#             */
/*   Updated: 2025/05/06 22:45:45 by vpeinado         ###   ########.fr       */
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

/* Definiciones de colores */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int valid_args(char *ip, char *subnet);
void ipcalc(char *ip, char *subnet);
char *cidr_to_subnet(char *cidr);
int is_cidr(char *subnet);