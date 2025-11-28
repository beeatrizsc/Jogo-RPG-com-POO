#ifndef CLASSEBASE_HPP
#define CLASSEBASE_HPP

#include <string>
#include <vector>
#include<iostream>
#include "atributos.hpp"
#include "Habilidade.hpp"

class ClasseBase {
protected:
    std::string nome;
    int forca, agilidade, energia, carisma, inteligencia, vida;
    std::vector<Habilidade> habilidadesBasicas;

public:
    ClasseBase(std::string n, int f, int ag, int en, int ca, int inte, int hp)
        : nome(n), forca(f), agilidade(ag), energia(en), carisma(ca),
          inteligencia(inte), vida(hp) {}

    virtual ~ClasseBase() {}
    std::string getNome() const { return nome; }
    std::vector<Habilidade>& getHabilidades() { return habilidadesBasicas; }
    int getForca() const { return forca; }
    int getAgilidade() const { return agilidade; }
    int getEnergia() const { return energia; }
    int getCarisma() const { return carisma; }
    int getInteligencia() const { return inteligencia; }
    int getVida() const { return vida; }


    virtual std::string desbloqueioHabilidade(const std::string& h) = 0;

    void listarHabilidades() {
        for (auto& hab : habilidadesBasicas)
            std::cout << hab.getNome() << " XP: " << hab.getXP() << "/" << hab.getXPMax()<< "";
    }
};

#endif // CLASSEBASE_HPP
