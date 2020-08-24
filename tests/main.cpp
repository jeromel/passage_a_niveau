#include <iostream>

#include "../PassageNiveauContexte.h"
#include "../PassageNiveauEtatAttente.h"


int main(void) {
    PassageNiveauContexte *contexte = new PassageNiveauContexte(new PassageNiveauEtatAttente());
    contexte->TraiterFonctionDuContexte();

    delete contexte;

    return EXIT_SUCCESS;
}