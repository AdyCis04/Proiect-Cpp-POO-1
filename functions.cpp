#include "functions.h"
#include <iostream>
#include <cstring>

void citire_din_fisiere(int argc, char* argv[], int& nrClientiFile, int& nrProduseFile, Client*& vec_Clienti, Produs*& vec_Produse)
{
    std::ifstream read_from_clienti(argv[2]);
    std::ifstream read_from_produse(argv[1]);

    if (!read_from_clienti.is_open()) // Verificam daca fisierele pot fi deschise sau nu.
    {
        std::cerr << "Error opening file!" << std::endl;
        exit(0);
    }
    if (!read_from_produse.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        exit(0);
    }

    // Citim datele aflate in fisierul produse.txt

    if (read_from_produse >> nrProduseFile) // Punem conditia daca este gol sau nu fisierul de citire
    {
        vec_Produse = new Produs[nrProduseFile];

        for (int i=0;i<nrProduseFile;i++)
        {
            new (&vec_Produse[i]) Produs(i,"",0.0,0); // Folosesc constructorul Produs pentru initialuzarea lui id care este de tip const int.

            read_from_produse >> vec_Produse[i]; // Citesc ceilalti parametri fiecare Produs din vectorul alocat dinamic.
        }
    }



    /*------------------------------------------------------------*/

    // Citim datele aflate in fisierul clienti.txt

    if (read_from_clienti >> nrClientiFile) // Punem conditia daca este gol sau nu fisierul de citire
    {
        vec_Clienti = new Client[nrClientiFile];

        for (int i=0;i<nrClientiFile;i++)
        {
            read_from_clienti >> std::ws;

            char nume[60];
            
            //Citim si setam numele clientului
            read_from_clienti.getline(nume,60);
            vec_Clienti[i].set_nume(nume);
            //-------------------------------//

            //Citim datele despre comanda clientului
            int zi, luna, an, nrProduse;
            read_from_clienti >> zi >> luna >> an >> nrProduse; 
            Produs* produse = new Produs[nrProduse];

            for (int j=0;j<nrProduse;j++)
            {
                //Citim datele despre fiecare produs

                char denumire[50];
                read_from_clienti >> denumire;

                int cantitate;
                read_from_clienti >> cantitate;

                new (&produse[j]) Produs(0,denumire,0.0,cantitate);

            }

            vec_Clienti[i].set_comanda(i,zi,luna,an,nrProduse,produse);

            //Eliberez de memorie vectorul alocat dinamic de produse pentru comanda clientului
            delete[] produse;
            produse = nullptr;
        }
    }


    /*------------------------------------------------------------*/


    read_from_clienti.close();
    read_from_produse.close();

}

void procesare_comenzi(Produs*& vec_Produse, int nrProduseFile, Client*& vec_Clienti, int nrClientiFile)
{
    for (int i=0;i<nrClientiFile;i++)
    {
        int nr_prod_client = vec_Clienti[i].get_comanda().get_nrProduse(); // Numarul de tipuri de produse comandate de client


        for (int j=0;j<nr_prod_client;j++)
        {
            for (int k=0;k<nrProduseFile;k++)
            {
                if (strncmp(vec_Clienti[i].get_comanda().get_produse()[j].get_denumire(),vec_Produse[k].get_denumire(),50)==0)
                {
                    // Luam fiecare tip de produs comandat de client, si actualizam toate stocurile dupa fiecare comanda facuta
                    int stoc_ramas = vec_Produse[k].get_cantitate() - vec_Clienti[i].get_comanda().get_produse()[j].get_cantitate();

                    //Vedem daca clientul cere mai mult decat exista in depozit.
                    if (stoc_ramas < 0)
                    {
                        vec_Produse[k].set_cantitate(0);

                        int cant_init;
                        cant_init = vec_Clienti[i].get_comanda().get_produse()[j].get_cantitate();
                        cant_init = cant_init + stoc_ramas;

                        vec_Clienti[i].get_comanda().get_produse()[j].set_cantitate(cant_init);
                    }
                    else
                        vec_Produse[k].set_cantitate(stoc_ramas);

                    // Atribuim parametrului pret din fiecare element din vectorul alocat dinamic de clasa Produs
                    // valoarea produsului cumparat pe bucata
                    int cant_final = vec_Clienti[i].get_comanda().get_produse()[j].get_cantitate();
                    
                    if (cant_final > 0)
                    {
                        float pret = vec_Produse[k].get_pret();
                        vec_Clienti[i].get_comanda().get_produse()[j].set_pret(pret);
                    }
                }
            }
        }
    }
}

void afisare_in_fisiere(int argc, Produs*& vec_Produse, int nrProduseFile, Client*& vec_Clienti, int nrClientiFile)
{
    std::ofstream print_to_stoc_ramas("output_stoc_ramas.txt");
    std::ofstream print_to_comenzi("output_comenzi.txt");

    if (!print_to_stoc_ramas.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        exit(0);
    }
    if (!print_to_comenzi.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        exit(0);
    }

    print_to_stoc_ramas << "Stoc ramas";

    for (int i=0;i<nrProduseFile;i++)
    {
        //Afisam fiecare tip de produs imparte din "depozitul magazinului" si detaliile despre fiecare
        print_to_stoc_ramas << "\n" << vec_Produse[i];
    }

    print_to_stoc_ramas.close();

    if (nrClientiFile == 0)
        // In caz ca fisierul "clienti.txt" nu a continut nimic, afisam mesajul de mai jos."
        print_to_comenzi << "Nu exista clienti in magazin.";
    else
    {
        for (int i=0;i<nrClientiFile;i++)
        {
            print_to_comenzi << "Nume: " << vec_Clienti[i].get_nume() << "\n";
            print_to_comenzi << "Comanda ID: "<< vec_Clienti[i].get_comanda().get_id() << "\n";
            print_to_comenzi << "Data comenzii: " << vec_Clienti[i].get_comanda().get_zi() << "/";
            print_to_comenzi << vec_Clienti[i].get_comanda().get_luna() << "/";
            print_to_comenzi << vec_Clienti[i].get_comanda().get_an() << "\n";
            print_to_comenzi << "Produse comandate:\n";

            float pret_total = 0.0;
            int nrProduse = vec_Clienti[i].get_comanda().get_nrProduse();

            for (int j=0;j<nrProduse;j++)
            {
                int cantitate = vec_Clienti[i].get_comanda().get_produse()[j].get_cantitate();
                float pret = vec_Clienti[i].get_comanda().get_produse()[j].get_pret();

                print_to_comenzi << cantitate;
                print_to_comenzi << " X " << vec_Clienti[i].get_comanda().get_produse()[j].get_denumire();
                print_to_comenzi << " (" << pret << ")\n";

                // calculam pretul total achitat de fiecare client imparte
                pret_total = pret_total + cantitate * pret;
            }

            print_to_comenzi << "Total comanda: " << pret_total << " RON";

            // Aici ne asiguram ca continutul din fisierul output_comenzi.txt este identic cu fisierele dn folderele test.
            if (i < nrClientiFile - 1)
                print_to_comenzi << "\n\n";
        }
    }

    print_to_comenzi.close();

    // Eliberam memoria din fiecare vector alocat dinamic de tip Client, respectiv Produse.
    delete[] vec_Clienti;
    vec_Clienti = nullptr;
    delete[] vec_Produse;
    vec_Produse = nullptr;

}