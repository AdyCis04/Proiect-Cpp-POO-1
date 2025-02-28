[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/dWp6iS_E)

Numele: Cismaru Adrian
Grupa: 323AB
Sistemul de operare utilizat: Windows 11
IDE-ul utilizat: Visual Studio Code

Descrierea temei:

Exista clasele Client, Comanda si Produs.
Un obiect de clasa Produs stocheaza date despre id(const int), denumire(char[50]), pretul pe bucata(float) si cantitatea / numarul de bucati 
ramase in depozitul cu marfa (int).
Un obiect de clasa Comanda stocheaza date despre id(const int), ziua, luna, anul plasarii comenzii(int, int, int), numarul de tipuri de produse
cerute (int) si lista de tipuri de produse sub forma de vector alocat dinamic (Produs*).
Un obiect de clasa Client stocheaza date despre numele clientului(char[60]), si comanda acestuia (comanda).

Despre biblioteca functions.h:

In cadrul functiei citire_din_fisiere, citesc din fiserele "produse.txt" si "clienti.txt" efectiv datele despre fiecare tip de produs imparte pe 
care le stochez intr-un vector de tip Produs* vec_Produse alocat dinamic in interiorul functiei. Asa procedez si cu clientii. De asemenea, cei doi 
vectori de tip vec_Produse si vec_Clienti sunt transmisi ca parametri de intrare prin referinta pentru a le aloca memorie si pentru a stoca date   
in interiorul lor.

In cadrul functiei procesare_comenzi, procesez evident fiecare comanda, actualizand si verificand stocurile fiecarui tip de produs din depozit, adica actualizez valorile din campul cantitate de la fiecare element din vectorul vec_Produse dupa plasarea fiecarei comenzi.

In cadrul functiei afisare_in_fisiere, afisez detalii despre fiecare tip de produs ramas in depozit in fisierul "output_stoc_ramas.txt", respectiv 
afisez detalii despre fiecare client si comanda fiecaruia in fisierul "output_comenzi". In cazul in care nu exita niciun produs in depozit, 
fiserul "output_stoc_ramas.txt" va ramane gol. In cazul in care nu exista nicio comanda, in fisierul "output_comenzi.txt" se va afisa mesajul
"Nu exista clienti in magazin.". La finalul acestei functii, se va elibera toata memoria alocata celor doi vectori "dinamici" transmisi de asemenea prin referinta.

Functia int main() creeaza cei doi vectori "dinamici" Produs* vec_Produse si Client* vec_Clienti pe care ii initializeaza cu nullptr si care sunt procesati in functiile din biblioteca "functions.h". De asemenea sunt creati si procesati variabilele de tip int nrProduseFile si nrClientiFile care ne spun cate elemente are fiecare vector.