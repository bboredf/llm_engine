#include <iostream>
#include "memory.hpp"

int main()
{
    std::cout << "LLM Engine inizializzato correttamente." << std::endl;

    // Test: prova a mappare un file (crea un file di testo 'test.txt' nella root per testarlo)
    try
    {
        MemoryMappedFile file("test.txt");
        std::cout << "File mappato con successo! Dimensione: " << file.size() << " bytes." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Errore: " << e.what() << " (Crea un file 'test.txt' per testare)" << std::endl;
    }

    return 0;
}