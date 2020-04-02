#include <iostream>
#include "AncestorTree.h"

using namespace std;

int main() {

    family::Tree T("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov");  // Tells the tree that the father of Yosef is Yaakov.
    T.addMother("Yosef", "Rachel");  // Tells the tree that the mother of Yosef is Rachel.
    T.addFather("Yaakov", "Isaac");
    T.addMother("Yaakov", "Rivka");
    T.addFather("Isaac", "Avraham");
    T.addFather("Avraham", "Terah");

    T.display();
    return 0;
}
