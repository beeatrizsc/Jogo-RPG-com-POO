#pragma once
#include <string>

enum TipoEquipamento { ARMA, ARMADURA, ITEM_UTIL, BOLSA, COMIDA };

struct Equipamento {
    std::string nome;
    TipoEquipamento tipo;
    int bonusVida = 0;
    int bonusForca = 0;
    int bonusAgilidade = 0;
    int bonusEnergia = 0;
    int bonusCarisma = 0;
    int bonusInteligencia = 0;
    int capacidadeBolsa = 0;

    Equipamento(std::string n, TipoEquipamento t)
        : nome(n), tipo(t) {}
};
