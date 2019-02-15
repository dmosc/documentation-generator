#include <iostream>
#include <fstream>

using namespace std;

#include "Sentence.h"

void addTags(Sentence &sentence) {
    if (sentence.getTag() == "@progName") {
        sentence.addBeforeAndAfter("<h1 class=\"titles\">", "</h1>");
    } else if (sentence.getTag() == "@desc") {
        sentence.addBeforeAndAfter("<p><b>Descripción: </b>", "</p>");
    } else if (sentence.getTag() == "@author") {
        sentence.addBeforeAndAfter("<p><b>Autor: </b>", "</p>");
    } else if (sentence.getTag() == "@date") {
        sentence.addBeforeAndAfter("<p><b>Fecha de elaboración: </b>", "</p>");
    } else if (sentence.getTag() == "@funcName") {
        sentence.addBeforeAndAfter("<hr class=\"section-break\"><p><b>Nombre de la función: </b>", "</p>");
    } else if (sentence.getTag() == "@return") {
        sentence.addBeforeAndAfter("<p><b>Valor de retorno: </b>", "</p>");
    } else if (sentence.getTag() == "@param") {
        sentence.addBeforeAndAfter("<p><b>Parámetro(s): </b>", "</p>");
    }
}

int main() {
    ifstream inFile;
    ofstream outFile;

    string nomFile;
    cout << "Enter input file name: ";
    cin >> nomFile;

    string nuevo = nomFile;

    nomFile += ".cpp";

    cout << nomFile << endl;

    inFile.open(nomFile);

    nuevo += ".html";

    outFile.open(nuevo);

    outFile << "<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"documentation.css\"></head><body>";

    string word;
    while(inFile >> word){
        if (word == "/**") {
            do {
                inFile >> word;
                string s;
                getline(inFile, s);
                Sentence sentence(s, word);
                addTags(sentence);
                outFile << sentence.getContent();
            } while(word != "*/");
        }
    }

    outFile << "</body></html>";
    inFile.close();
    outFile.close();
}
