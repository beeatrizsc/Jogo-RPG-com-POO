#pragma once
#include <string>

class Habilidade {
private:
    std::string nome;
    int xp;
    int xpMax;
    int treinosHoje;
    int level;

public:
    Habilidade(std::string n, int xpMax = 100)
        : nome(n), xp(0), xpMax(xpMax), treinosHoje(0), level(1) {}

    bool treinar() {
        if (treinosHoje >= 1) return false; // 1 treino/dia
        xp += 10;
        treinosHoje++;
        if (xp >= xpMax) {
            level++;
            xp-=xpMax;
            return true;
        }
        return false;
    }

    void novoDia() { treinosHoje = 0; }

    std::string getNome() const { return nome; }
    int getXP() const { return xp; }
    int getXPMax() const { return xpMax; }
    int getLevel() const {return level;}
};
