#include <iostream>
#include "Player.hpp"
#include "classes.hpp"
#include <ctime>

int main() {
    srand(time(NULL));
    std::cout << "=== Bem-vindo ao RPG ===\n";

    std::cout << "Nome do jogador: ";
    std::string nome;
    std::getline(std::cin, nome);

    std::cout << "Genero (M/F): ";
    std::string genero;
    std::getline(std::cin, genero);

    std::cout << "Escolha sua classe:\n";
    std::cout << "1 - Guerreiro\n2 - Mago\n3 - Clerigo\n4 - Barbaro\n5 - Bardo\n> ";

    int escolha;
    std::cin >> escolha;

    std::unique_ptr<ClasseBase> classe;
    switch (escolha) {
        case 1: classe = std::make_unique<Guerreiro>(); break;
        case 2: classe = std::make_unique<Mago>(); break;
        case 3: classe = std::make_unique<Clerigo>(); break;
        case 4: classe = std::make_unique<Barbaro>(); break;
        case 5: classe = std::make_unique<Bardo>(); break;
        default: std::cout << "Opcao invalida!\n"; return 0;
    }

    Player p(nome, genero, std::move(classe));
    MissaoManager mm;

    while (true) {
        std::cout << "\n== MENU ==\n";
        std::cout << "1 - Mostrar Status\n";
        std::cout << "2 - Treinar habilidade\n";
        std::cout << "3 - Passar turno\n";
        std::cout << "4 - Sair\n> ";

        int op;
        std::cin >> op;

        if (op == 1) {
            p.mostrarStatus(mm);
        }
        else if (op == 2) {
            std::cout << "\nQual habilidade quer treinar? (digite o numero)\n";
            p.listarHabilidades();
            int h; std::cin >> h;
            p.treinarHabilidade(h-1);
        }
        else if (op == 3) {
            p.passarTurno();
        }
        else break;
    }

    return 0;
}
