//
// Created by edvonaldoh on 30/09/16.
//
#pragma once // Na compilação, evita que chame que o mesmo arquivo nuvamente
#include "helpful_function.h"

int is_bit_i_set(unsigned char c, int i) // Verifica se o bit de posição i no caracter c está setado - a contagem dos bits começa em 0
{
    unsigned char mask = 1 << i; // O caracter mask é setado em 1 na posição i - os demais bits de posição dele são 0
    return mask & c; // Faz a operação booleana AND bit a bit entre mask e c;
}

unsigned char set_bit(unsigned char c, int i) // Seta o bit da posição i do caractere c
{
    unsigned char mask = 1 << i; // O caractere mask é setado em 1 na posição i - os demais bits de posição dele são 0
    return mask | c; // Realiza a operação OR bit a bit entre mask e c;
}
