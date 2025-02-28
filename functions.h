#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Client.h"
#include "Comanda.h"
#include "Produs.h"

void citire_din_fisiere(int, char**, int&, int&, Client*&, Produs*&);

void procesare_comenzi(Produs*&, int, Client*&, int);

void afisare_in_fisiere(int, Produs*&, int, Client*&, int);

#endif