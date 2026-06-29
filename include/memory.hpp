#pragma once
#include <windows.h>
#include <string>
#include <stdexcept>

class MemoryMappedFile
{
private:
    HANDLE hFile = INVALID_HANDLE_VALUE;
    HANDLE hMap = NULL;
    void *mappedData = nullptr;
    size_t fileSize = 0;

public:
    MemoryMappedFile(const std::string &filename)
    {
        hFile = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            throw std::runtime_error("Impossibile aprire il file");

        LARGE_INTEGER size;
        GetFileSizeEx(hFile, &size);
        fileSize = static_cast<size_t>(size.QuadPart);

        hMap = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
        if (!hMap)
            throw std::runtime_error("Impossibile creare mapping");

        mappedData = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
        if (!mappedData)
            throw std::runtime_error("Impossibile mappare la view");
    }

    ~MemoryMappedFile()
    {
        if (mappedData)
            UnmapViewOfFile(mappedData);
        if (hMap)
            CloseHandle(hMap);
        if (hFile != INVALID_HANDLE_VALUE)
            CloseHandle(hFile);
    }

    void *data() const { return mappedData; }
    size_t size() const { return fileSize; }
};