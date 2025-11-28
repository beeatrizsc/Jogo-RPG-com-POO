#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "item.hpp"

class Inventario {
private:
    std::vector<Equipamento> itens;
    int capacidadeMax;
    std::string tipoBolsa;

public:
    Inventario(int capacidade, const std::string& bolsa = "Bolsa Pequena") : capacidadeMax(capacidade), tipoBolsa(bolsa){}

    bool adicionar(const Equipamento& eq) {
        if ((int)itens.size() >= capacidadeMax) return false;
        itens.push_back(eq);
        return true;
    }

    void listar() const {
        std::cout << "=== Inventario (capacidade " << capacidadeMax << ") ===\n";
        std::cout << "Bolsa: " << tipoBolsa << "\n";
        for (auto& e : itens)
            std::cout << e.nome << " ";
        std::cout << "\n";
    }

    int getCapacidade() const { return capacidadeMax; }

    const std::vector<Equipamento>& getItens() const { return itens; }

    bool temItem(const std::string& nomeItem) const {
        for (const auto& e : itens) {
            if (e.nome == nomeItem)
                return true;
        }
        return false;
    }

    bool removeItem(const std::string& nomeItem) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if (it->nome == nomeItem) {
            itens.erase(it);
            return true;
        }
    }
    return false; // item não encontrado
}

};

