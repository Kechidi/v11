#include <string>
#include <iostream>
#include "liste.cc"
using namespace std;

int main() {

    Liste<string> liste1;


    cout << " ajout des elements" << endl;
    liste1.ajouter("tete de liste");
    liste1.ajouter("element2");
    liste1.ajouter("element3");

    liste1.afficher();

    Liste<int> liste2;
    cout << " ajout des élément (entiers) " << endl;
    liste2.ajouter(1);
    liste2.ajouter(2);
    liste2.ajouter(3);
    liste2.afficher();



     cout << "\n\n inserer dans une liste vide" << endl;
       Liste<string> listeVide;
       Iterateur<string> it;
       listeVide.inserer(it, "element x (element inséré dans une liste vide)");
       listeVide.afficher();

       cout << "\n\n inserer des elements" << endl;

       Iterateur<string> it2;
       it2 = liste1.debut();
       //  it++;

       liste1.inserer(it2, "element inséré au debut");
       liste1.afficher();

       cout << "\n\n inserer des element" << endl;

       Iterateur<string> it3;
       it3 = liste1.debut();
       it3++;
       it3++;
       liste1.inserer(it3, "element inséré au milieu");
       liste1.afficher();


       Iterateur<string> it4;
       it4 = liste1.fin();
       liste1.inserer(it4, "element inséré a la fin");
       liste1.afficher();



    cout << "supprimer au debut( tete de liste)" << endl;
    Iterateur<string> ite;
    ite = liste1.debut();
    liste1.supprimer(ite);
    liste1.afficher();

    cout << "supprimer au milieu( element2)" << endl;
    Iterateur<string> it7;
    it7 = liste1.debut();
    it7++;

    liste1.supprimer(it7);
    liste1.afficher();







    //cout<<liste1<<endl;
       cout << "\n\n supprimer des elements   " << endl;
       cout << "supprimer au debut" << endl;
       Iterateur<string> it6 = liste1.debut();
       it6++;
       liste1.supprimer(it6);
       liste1.afficher();




       cout << "supprimer au milieu" << endl;
       Iterateur<string> it9;
       it9 = liste1.debut();
       it++;

       liste1.supprimer(it9);
       liste1.afficher();



      cout << "supprimer a la fin de la liste " << endl;
       Iterateur<string> it8;
       it8 = liste1.fin();
       it8--;
       liste1.supprimer(it8);
       liste1.afficher();

       cout << "\n\nTest de l'operateur d'affectation" << endl;
       liste1 = listeVide;
       liste1.afficher();






   }

/*

     cout << "\n\nTest du constructeur par recopie" << endl;
     testIns.ajouter("hello");
     testIns.ajouter("World");
     Liste<string> *tt = new Liste<string>(testIns);
     tt->afficher();
     delete tt;

     cout << "\n\nTest de l'operateur d'affectation" << endl;
     testAj = testIns;
     testAj.afficher();


     cout << "\n\nTest des templates" << endl;
     Liste<int> testTemp;
     testTemp.ajouter(1);
     testTemp.ajouter(72);
     testTemp.ajouter(2020);
     testTemp.afficher();

     Iterateur<int> nbr;
     nbr = testTemp.debut();
     testTemp.inserer(nbr, 26);
     testTemp.afficher();

     testTemp.supprimer(nbr);
     testTemp.afficher();

   */