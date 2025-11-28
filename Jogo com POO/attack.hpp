#pragma once
#include <string>
#include <functional>
#include <iostream>

enum TipoAtaque { DANO, CURA };

struct Ataque {
    std::string nome;
    int baseDmg;
    int nivel;
    int xp;
    int xpMax;
    TipoAtaque tipo;
    int maxUsosPorBatalha;
    int usosRestantes;

    // função para calcular dano real
    std::function<int()> calculaDano;

    Ataque(std::string n, int dmg, TipoAtaque t, int maxUsos=10, int xpMax=50)
        : nome(n),
          baseDmg(dmg),
          nivel(1),
          xp(0),
          xpMax(xpMax),
          maxUsosPorBatalha(maxUsos),
          usosRestantes(maxUsos),
          calculaDano(nullptr)
    {}

    // dar XP ao ataque
    void ganharXpAtaque(int quantidade) {
        xp += quantidade;
        if (xp >= xpMax) {
            xp = 0;
            nivel++;
            baseDmg += 2;
            xpMax = xpMax*nivel;
            std::cout << "[UPGRADE] O ataque " << nome << " subiu para nivel " << nivel
                      << "! Dano base aumentado para " << baseDmg << ".\n";
        }
    }
};
