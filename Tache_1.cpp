/* This C++ program opens a file and asks the user to enter one or more letters.
These entered letters will be converted to uppercase in all the text contained in the file.
A new file containing the modifications will be created. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to check if a string contains only letters.
bool lettresSeulement(const string& mot)
{
    for (char c : mot)
    {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() 
{
    
    // Open and read the input file.
    ifstream T1E("Texte_1_entree.txt");
    ostringstream lecture;
    lecture << T1E.rdbuf();
    string texte = lecture.str();

    // User input and basic validation.
    string entree = "";
    cout << "Entrer la ou les lettres à convertir en majuscule : ";
    getline(cin, entree);
    while ((lettresSeulement(entree) == false) || (entree.empty()))
    {
        cout << "Il faut entrer quelque chose qui est seulement composé de lettres : ";
        getline(cin, entree);
    }

    // Modify the characters.
    string texte_mod = "";
    size_t i = 0;
    auto debut = high_resolution_clock::now(); // Start performance measurement of the processing.
    while (i < texte.size())
    {
        if (i + entree.size() <= texte.size() && texte.substr(i, entree.size()) == entree)
        {
            string maj_entree = entree;
            for (char &c : maj_entree)
            {
                c = toupper(c);
            }
            texte_mod += maj_entree;
            i += entree.size();
        }
        else
        {
            texte_mod += texte[i];
            i++;
        }
    }

    // Open/create and write to the output file.
    ofstream T1S("Texte_1_sortie.txt");
    T1S << texte_mod;

    // End performance measurement and display the result.
    auto fin = high_resolution_clock::now();
    auto duree = duration_cast<duration<double>>(fin - debut);
    cout << "Temps de traitement : " << duree.count() << " secondes" << endl;

    return 0;
}