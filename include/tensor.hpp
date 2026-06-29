#pragma once
#include <vector>
#include <cstdint>

enum class TensorType
{
    F32,
    Q4_0, // Esempio di formato quantizzato
    Q8_0
};

class Tensor
{
public:
    Tensor(std::vector<int64_t> shape, TensorType type)
        : shape(shape), type(type), data(nullptr) {}

    // Metodi per accedere ai dati
    void *get_data() const { return data; }
    void set_data(void *ptr) { data = ptr; }

private:
    std::vector<int64_t> shape;
    TensorType type;
    void *data;
};