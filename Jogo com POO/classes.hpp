#pragma once
#include "ClasseBase.hpp"

class Guerreiro : public ClasseBase {
public:
    Guerreiro()
        : ClasseBase("Guerreiro", 15, 12, 13, 10, 10, 110)
    {
        habilidadesBasicas.push_back(Habilidade("Treinar Espada"));
        habilidadesBasicas.push_back(Habilidade("Colocar Armadura"));
    }

    std::string desbloqueioHabilidade(const std::string& h) override {
        if (h == "Treinar Espada") return "Vida aumentada em +10!";
        if (h == "Colocar Armadura") return "Vida aumentada em +10!";
        return "Nada desbloqueado";
    }
};

class Mago : public ClasseBase {
public:
    Mago()
        : ClasseBase("Mago", 8, 12, 15, 11, 14, 80)
    {
        habilidadesBasicas.push_back(Habilidade("Treinar Magia"));
        habilidadesBasicas.push_back(Habilidade("Ler Grimorio"));
    }

    std::string desbloqueioHabilidade(const std::string& h) override {
        if (h == "Treinar Magia") return "Vida aumentada em +10!";
        if (h == "Ler Grimorio") return "Vida aumentada em +10!";
        return "Nada desbloqueado";
    }
};

class Clerigo : public ClasseBase {
public:
    Clerigo()
        : ClasseBase("Clerigo", 8, 11, 14, 12, 15, 100)
    {
        habilidadesBasicas.push_back(Habilidade("Oracao"));
        habilidadesBasicas.push_back(Habilidade("Treinar Magia"));
    }

    std::string desbloqueioHabilidade(const std::string& h) override {
        if (h == "Oracao") return "Vida aumentada em +10!";
        if (h == "Treinar Magia") return "Vida aumentada em +10!";
        return "Nada desbloqueado";
    }
};

class Barbaro : public ClasseBase {
public:
    Barbaro()
        : ClasseBase("Barbaro", 15, 14, 15, 8, 8, 140)
    {
        habilidadesBasicas.push_back(Habilidade("Limpar arma"));
        habilidadesBasicas.push_back(Habilidade("Exercitar"));
    }

    std::string desbloqueioHabilidade(const std::string& h) override {
        if (h == "Limpar arma") return "Vida aumentada em +10!";
        if (h == "Exercitar") return "Vida aumentada em +10!";
        return "Nada desbloqueado";
    }
};

class Bardo : public ClasseBase {
public:
    Bardo()
        : ClasseBase("Bardo", 8, 14, 11, 15, 12, 80)
    {
        habilidadesBasicas.push_back(Habilidade("Treinar Carisma"));
        habilidadesBasicas.push_back(Habilidade("Tocar Instrumento"));
    }

    std::string desbloqueioHabilidade(const std::string& h) override {
        if (h == "Treinar Carisma") return "Vida aumentada em +10!";
        if (h == "Tocar Instrumento") return "Vida aumentada em +10!";
        return "Nada desbloqueado";
    }
};
