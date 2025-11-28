#pragma once
#include <string>
#include <iostream>
#include <vector>

struct EnemyAttack {
    std::string nome;
    int danoBase;

    EnemyAttack(std::string n, int dmg)
        : nome(n), danoBase(dmg) {}
};

class Enemy {
private:
    std::string nome;
    int nivel;
    int vidaMax;
    int vidaAtual;
    int xpDado;
    std::vector<EnemyAttack> ataques;

public:
    Enemy(std::string tipo, int nivelJogador)
        : nome(tipo),
          nivel(nivelJogador),
          vidaMax(25 + nivelJogador * 8),
          vidaAtual(25 + nivelJogador * 8)
    {
        if (tipo == "Slime") {
            ataques = {
                {"Borrifada Acida", 4 + nivel * 2},
                {"Pulo Pegajoso",   3 + nivel}
            };
            xpDado= 15+ nivel*5;
        }
        else if (tipo == "Esqueleto") {
            ataques = {
                {"Espadada Ossea", 6 + nivel * 2},
                {"Arremesso de Osso", 4 + nivel}
            };
            xpDado= 20+ nivel*5;
        }
        else if (tipo == "Lobo") {
            ataques = {
                {"Mordida", 5 + nivel * 2},
                {"Investida", 6 + nivel * 2}
            };
            xpDado= 20+ nivel*5;
        }
        else if (tipo == "Goblin") {
            ataques = {
                {"Faca Suja", 5 + nivel * 2},
                {"Pedrada", 4 + nivel}
            };
            xpDado= 15+ nivel*5;
        }
        else if (tipo == "Bandido") {
            ataques = {
                {"Punhalada", 6 + nivel * 2},
                {"Atirar Pedra", 4 + nivel}
            };
            xpDado= 20+ nivel*5;
        }
        else if (tipo == "Cultista Fanatico") {
            ataques = {
                {"Golpe Ritualistico", 6 + nivel},
                {"Praga Sombria", 8 + nivel * 2}
            };
            xpDado= 30+ nivel*5;
        }
    }

    std::string getNome() const { return nome; }
    int getNivel() const { return nivel; }
    int getVida() const { return vidaAtual; }
    int getVidaMax() const { return vidaMax; }
    int getXpDado() const { return xpDado; }

    void listarAtaques() const {
        for (size_t i = 0; i < ataques.size(); i++) {
            std::cout << i + 1 << " - " << ataques[i].nome
                      << " (dano base: " << ataques[i].danoBase << ")\n";
        }
    }

    int usarAtaque(int index) {
        return ataques[index].danoBase;
    }

    void receberDano(int dano) {
        vidaAtual -= dano;
        if (vidaAtual < 0) vidaAtual = 0;
    }

    bool estaVivo() const { return vidaAtual > 0; }

    int getNumAtaques() const {
    return ataques.size();
    }

};
