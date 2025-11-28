#pragma once
#include <string>
#include <vector>
#include <iostream>

enum class EstadoMissao {
    Ativa,
    Concluida,
    Falhada
};

class Missao {
private:
    std::string nome;
    std::string descricao;

    int progressoAtual;
    int progressoNecessario;

    EstadoMissao estado;

    int recompensaXP;
    int recompensaOuro;
    int recompensaFama;

public:

    Missao(const std::string& nome,
           const std::string& descricao,
           int progressoNecessario,
           int recompensaXP,
           int recompensaOuro,
           int recompensaFama)
        : nome(nome),
          descricao(descricao),
          progressoAtual(0),
          progressoNecessario(progressoNecessario),
          estado(EstadoMissao::Ativa),
          recompensaXP(recompensaXP),
          recompensaOuro(recompensaOuro),
          recompensaFama(recompensaFama)
    {}


    std::string getNome() const { return nome; }
    std::string getDescricao() const { return descricao; }
    int getProgressoAtual() const { return progressoAtual; }
    int getProgressoNecessario() const { return progressoNecessario; }
    EstadoMissao getEstado() const { return estado; }

    int getRecompensaXP() const { return recompensaXP; }
    int getRecompensaOuro() const { return recompensaOuro; }
    int getRecompensaFama() const { return recompensaFama; }


    void adicionarProgresso(int qtd = 1) {
        if (estado != EstadoMissao::Ativa) return;

        progressoAtual += qtd;
        if (progressoAtual >= progressoNecessario)
            estado = EstadoMissao::Concluida;
    }


    void falhar() {
        if (estado == EstadoMissao::Ativa)
            estado = EstadoMissao::Falhada;
    }
};


class Player;


class MissaoManager {
private:
    std::vector<Missao> missoesAtivas;
    std::vector<Missao> missoesConcluidas;
    std::vector<Missao> missoesFalhadas;

public:


    void adicionarMissao(const Missao& m) {
        missoesAtivas.push_back(m);
    }

    bool existeMissao(const std::string& nome) const {
        for (auto& m : missoesAtivas)
            if (m.getNome() == nome) return true;
        return false;
    }


    Missao* getMissao(const std::string& nome) {
        for (auto& m : missoesAtivas)
            if (m.getNome() == nome)
                return &m;
        return nullptr;
    }


    void darRecompensa(Player& p, const Missao& m);


    void atualizar(Player& p) {
        for (int i = 0; i < (int)missoesAtivas.size(); i++) {
            auto& m = missoesAtivas[i];

            if (m.getEstado() == EstadoMissao::Concluida) {
                darRecompensa(p, m);

                missoesConcluidas.push_back(m);
                missoesAtivas.erase(missoesAtivas.begin() + i);
                i--;
            }
            else if (m.getEstado() == EstadoMissao::Falhada) {
                missoesFalhadas.push_back(m);
                missoesAtivas.erase(missoesAtivas.begin() + i);
                i--;
            }
        }
    }


    const std::vector<Missao>& getAtivas() const { return missoesAtivas; }
    const std::vector<Missao>& getConcluidas() const { return missoesConcluidas; }
    const std::vector<Missao>& getFalhadas() const { return missoesFalhadas; }
};

