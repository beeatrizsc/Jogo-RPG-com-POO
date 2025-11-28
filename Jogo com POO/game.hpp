#pragma once
#include "Player.hpp"

class Game {
private:
    Player* jogador;

public:
    Game(Player* p) : jogador(p) {}

    void passarTurno() {
        for (auto& h : jogador->getClasse()->getHabilidades())
            h.novoDia();
        std::cout << "Um novo dia começou! Voce pode treinar suas habilidades novamente.\n";
    }
};
