#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

// Fonction pour ajouter une entrée JSON à un fichier JSON de type tableau
void AddJsonEntryToFile(const std::string &filename, const json &newEntry)
{
    json j;

    // Lire le fichier s'il existe
    std::ifstream fileIn(filename);
    if (fileIn)
    {
        try
        {
            fileIn >> j;
            if (!j.is_array())
            {
                std::cerr << "Le fichier JSON n'est pas un tableau." << std::endl;
                return;
            }
        }
        catch (...)
        {
            std::cerr << "Erreur lors du parsing JSON." << std::endl;
            return;
        }
    }
    else
    {
        j = json::array(); // Initialise un tableau vide si le fichier n'existe pas
    }

    // Ajouter la nouvelle entrée
    j.push_back(newEntry);

    // Sauvegarder le fichier
    std::ofstream fileOut(filename);
    fileOut << j.dump(4); // Indentation de 4 espaces

    std::cout << "Entrée ajoutée avec succès au fichier " << filename << std::endl;
}

int main()
{
    json newEntry = {
        {"Name", "TiTiRow"},
        {"PlayerName", "TiTi"},
        {"Score", 1080}};

    AddJsonEntryToFile("ranking.json", newEntry);

    return 0;
}
