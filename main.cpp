#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Client.h"
#include "Comanda.h"
#include "Produs.h"
#include "functions.h"

int main(int argc, char* argv[]) {

    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    int nrProduseFile = 0, nrClientiFile = 0;
    Produs* vec_Produse = nullptr;
    Client* vec_Clienti = nullptr;

    citire_din_fisiere(argc, argv, nrClientiFile, nrProduseFile, vec_Clienti, vec_Produse);

    procesare_comenzi(vec_Produse, nrProduseFile, vec_Clienti, nrClientiFile);

    afisare_in_fisiere(argc, vec_Produse, nrProduseFile, vec_Clienti, nrClientiFile);


    //TODO: nu scrieti cod functional aici, implementati clasele sau functii care sa rezolve
    // pastrati main-ul cat mai curat si simplu de inteles

    return 0;
}