#include "liste.h"
#include <cstring>

using namespace std;

/* ---------------------- Element ---------------------- */
template<typename T>
class Element {
public:
    // constructeur
    Element(const T& s);

    friend class Liste<T>;
    friend class Iterateur<T>;

private:
    T valeur;

    // pointeurs vers les voisins
    Element<T>* precedent;
    Element<T>* suivant;

};

template<typename T>
Element<T>::Element(const T& s) {
    valeur = s;
    precedent = suivant = NULL;
}



template<typename T> Iterateur<T>::Iterateur() {
    position = dernier = NULL;
}



template<typename T>
Iterateur<T> Liste<T>::debut() const {
    Iterateur<T> it;
    it.position = premier;
    it.dernier = dernier;
    return it;
}

template<typename T>
Iterateur<T> Liste<T>::fin() const {
    Iterateur<T> it;
    it.position = NULL;
    it.dernier = dernier;
    return it;
}


// construteur par defaut
template<typename T> Liste<T>::Liste() {
    premier = dernier = NULL;
}

// constructeur par recopie
template<typename T>
Liste<T>::Liste(const Liste<T>& l){
    if(l.premier == NULL){
        premier = dernier = NULL;
        cout<< "La liste a copier est null"<< endl;
    } else {
        Iterateur<T> it = l.debut();
        while(it.position != NULL){
            this -> ajouter(*it);
            it++;
        }
    }
}

template <typename T>
Liste<T>::~Liste(){ // destructeur
    while(premier != dernier){
        premier = premier->suivant;
        delete premier->precedent;
    }
    //premier = dernier ils sont donc tout les deux supprimés
    //via la ligne ci dessous
    delete premier;
}

template <typename T>
Liste<T>& Liste<T>::operator=(const Liste<T>& l) {
    if (this != &l) {
        Liste();
        Iterateur<T> it = l.debut();
        while (it.position != NULL) {
            this->ajouter(*it);
            it++;
        }

    }
    return *this;
}

template<typename T>
void Liste<T>::ajouter(const T& s) {
    Element<T> *elm = new Element<T>(s);
    if(premier == NULL){
        premier = dernier = elm;
    }else{
        dernier->suivant = elm;
        elm->precedent = dernier;
        dernier = elm;
    }
}

template<typename T>
void Liste<T>::inserer(Iterateur<T>& pos, const T& s){
    //si la liste est vide ou si pos vaut Null
    if(premier == NULL){
        this->ajouter(s);
    }else{
        Element<T> *elm = new Element<T>(s);
        if(pos.position == premier){
            elm->suivant = premier;
            premier->precedent =elm;
            premier = elm;
        } else {
            elm->suivant = pos.position;
            elm->precedent = pos.position->precedent;
            pos.position->precedent->suivant = elm;
            pos.position->precedent = elm;
        }
    }
}

template<typename T>
void Liste<T>::supprimer(Iterateur<T>& pos) {
    if (premier == NULL || pos.position == NULL) {//Si la liste est vide ou si pos vaut NULL
        cout << "aucun element a supprimer" << endl;
    } else {
        //Si on a un seule element dans la liste
        if (pos.position == premier && pos.position == dernier) {
            premier = dernier = NULL;
        } else if (pos.position == premier) {
            premier = premier->suivant;
            premier->precedent = NULL;
        } else if (pos.position == dernier) {
            dernier = dernier->precedent;
            dernier->suivant = NULL;
        } else {
            pos.position->suivant->precedent = pos.position->precedent;
            pos.position->precedent->suivant = pos.position->suivant;
        }
        delete pos.position;
    }
}

template<typename T>
void Liste<T>::afficher(){
    Element<T> *elm = premier;


    while (elm != NULL) {

        cout  <<  elm->valeur << endl;


        elm= elm->suivant;



    }

}

template<typename T> T& Iterateur<T>::operator*() const {
    return position->valeur;
}

//prefixe
template<typename T> T Iterateur<T>::operator++(int) {
    T temp(position->valeur);
    position = position->suivant;
    return temp;
}

template<typename T>
T Iterateur<T>::operator++() {
    position = position->suivant;
    return position->valeur;
}

// precedent

template<typename T>
T Iterateur<T>::operator--(int) {
    T temp(position->valeur);
    if (position == NULL) // fin de la liste
        position = dernier;
    else
        position = position->precedent;
    return temp;
}

template<typename T>
T Iterateur<T>::operator--() {
    if (position == NULL) // fin de la liste
        position = dernier;
    else
        position = position->precedent;
    return position->valeur;
}

// methode ==
template<typename T>
bool Iterateur<T>::operator==(const Iterateur<T>& b) const {
    return position == b.position;
}

template<typename T> bool Iterateur<T>::operator!=(const Iterateur<T>& b) const {
    return position != b.position;
    // return !(*this == b);
}


