#ifndef LISTE_H
#define LISTE_H

#include <string>
#include <iostream>

using namespace std;

template<typename T> class Element;
template<typename T> class Iterateur;

template<typename T>
class Liste {
public:
    // constructeur
    Liste();
    Liste(const Liste<T>&);
    ~Liste();

    // ajouter s a la fin de la liste
    void ajouter(const T& s);

    // ajouter s avant la position pos
    void inserer(Iterateur<T>& pos, const T& s);

    // supprimer l'element a la position pos
    void supprimer(Iterateur<T>& pos);
    void afficher();
    Liste<T> &operator=(const Liste<T> &v);

    // la premiere position
    Iterateur<T> debut() const;

    // la fin de la liste (apres la derniere position)
    Iterateur<T> fin() const;

private:
    // pointeurs vers le premier et le dernier element
    Element<T>* premier;
    Element<T>* dernier;
};


template <typename T>
class Iterateur {
public:
    // constructeur
    Iterateur();

    // retourne la valeur dans cette position
    T& operator*() const;

    // avance a la position suivante
    T operator++();
    T operator++(int);

    // recule a la position precedente
    T operator--();
    T operator--(int);

    // compare deux iterateurs
    bool operator==(const Iterateur<T>& b) const;
    bool operator!=(const Iterateur<T>& b) const;

    friend class Liste<T>;


private:
    // pointeur vers l'element courant
    Element<T>* position;

    // pointeur vers le dernier element de la liste
    Element<T>* dernier;
};

#endif
