#include "exceptionNrEtaj.h"

const char* exceptionNrEtaj::what() const throw(){
    return "Incercati sa initializati etaj cu un nr negativ. Nr etajului a fost reinitializat\n";
}
