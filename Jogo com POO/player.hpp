#pragma once
#include "ClasseBase.hpp"
#include "attack.hpp"
#include "item.hpp"
#include "inventory.hpp"
#include "enemy.hpp"
#include "Missao.hpp"
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <map>

struct Filho {
    std::string nomeFilho;
    std::string progenitor1;
    std::string progenitor2;
    bool adotado;
};

class Player {
private:
    std::string nome;
    std::string genero;
    int nivel;
    int vidaMax;
    int vidaAtual;
    int xpAtual = 0;
    int xpParaProximoNivel = 50;
    int fama = 0;
    int ouro = 0;

    std::unique_ptr<ClasseBase> classe;
    std::vector<Ataque> ataques;
    std::vector<Missao> missoes;
    Inventario inventario;
    int turnosNoDia = 0;
    int diaAtual = 1;

    // Romance
    std::map<std::string, int> relacionamentos;
    std::vector<Filho> filhos;
    //Elina
    int relElina = 0;
    bool elinaConhece = false;
    int diasNamorandoElina = 0;
    bool namorandoElina = false;
    bool casadoElina = false;
    bool conversaElina1 = false;
    bool conversaElina2 = false;
    bool conversaElina3 = false;
    bool conversaElina4 = false;
    bool conversaElina5 = false;

    //Arryn
    int relArryn = 0;
    bool arrynConhece = false;
    int diasNamorandoArryn = 0;
    bool namorandoArryn = false;
    bool casadoArryn = false;
    bool conversaArryn1 = false;
    bool conversaArryn2 = false;
    bool conversaArryn3 = false;
    bool conversaArryn4 = false;
    bool conversaArryn5 = false;

public:
    Player(const std::string& n, const std::string& g, std::unique_ptr<ClasseBase> c)
        : nome(n), genero(g), nivel(1), classe(std::move(c)), inventario(15)
    {
        // Inicializa vida do player
        vidaMax = classe->getVida();
        vidaAtual = vidaMax;

    std::string cname = classe->getNome();

    if (cname == "Guerreiro") {

        // --- CORTE VIGOROSO ---
        ataques.emplace_back("Corte Vigoroso", 6, DANO, 10);
        Ataque& atk1 = ataques.back();
        atk1.calculaDano = [this, &atk1]() {
            return atk1.baseDmg + (this->nivel * 2) + (atk1.nivel * 1) + (classe->getForca() % 10);
        };

        // --- PANCADA DE AÇO ---
        ataques.emplace_back("Pancada de Aco", 10, DANO, 2);
        Ataque& atk2= ataques.back();
        atk2.calculaDano = [this, &atk2]() {
            return atk2.baseDmg + (this->nivel * 2) + (atk2.nivel * 1) + (classe->getForca() % 10);
        };

        inventario.adicionar(Equipamento("Cota de Malha Basica", ARMADURA));
        inventario.adicionar(Equipamento("Espada Curta Basica", ARMA));
        inventario.adicionar(Equipamento("Saco de Dormir", ITEM_UTIL));
    }


    else if (cname == "Mago") {
        ataques.emplace_back("Chama Vacilante", 6, DANO, 10);
        Ataque& atk1 = ataques.back();
        atk1.calculaDano = [this, &atk1]() {
            return atk1.baseDmg + (this->nivel * 2) + (atk1.nivel * 1) + (classe->getInteligencia() % 10);
        };

        ataques.emplace_back("Missil Magico", 10, DANO, 2);
        Ataque& atk2= ataques.back();
        atk2.calculaDano = [this, &atk2]() {
            return atk2.baseDmg + (this->nivel * 2) + (atk2.nivel * 1) + (classe->getInteligencia() % 10);
        };

        inventario.adicionar(Equipamento("Robe Magico", ARMADURA));
        inventario.adicionar(Equipamento("Cajado de Aprendiz", ARMA));
        inventario.adicionar(Equipamento("Saco de Dormir", ITEM_UTIL));
    }


    else if (cname == "Clerigo") {
        ataques.emplace_back("Curar Feridas", 8, CURA, 2);
        Ataque& cura= ataques.back();
        cura.calculaDano = [this, &cura]() {
            return cura.baseDmg + (this->nivel * 2) + (cura.nivel * 1) + (classe->getEnergia() % 10);
        };

        ataques.emplace_back("Chama Sagrada", 6, DANO, 10);
        Ataque& atk1 = ataques.back();
        atk1.calculaDano = [this, &atk1]() {
            return atk1.baseDmg + (this->nivel * 2) + (atk1.nivel * 1) + (classe->getEnergia() % 10);
        };

        ataques.emplace_back("Mao Esmagadora", 10, DANO, 2);
        Ataque& atk2= ataques.back();
        atk2.calculaDano = [this, &atk2]() {
            return atk2.baseDmg + (this->nivel * 2) + (atk2.nivel * 1) + (classe->getEnergia() % 10);
        };

        inventario.adicionar(Equipamento("Vestes Clericas", ARMADURA));
        inventario.adicionar(Equipamento("Colar de Fiel", ITEM_UTIL));
        inventario.adicionar(Equipamento("Saco de Dormir", ITEM_UTIL));
    }


    else if (cname == "Barbaro") {
        ataques.emplace_back("Quebra-Ossos", 6, DANO, 10);
        Ataque& atk1 = ataques.back();
        atk1.calculaDano = [this, &atk1]() {
            return atk1.baseDmg + (this->nivel * 2) + (atk1.nivel * 1) + (classe->getForca() % 10);
        };

        ataques.emplace_back("Furia Selvagem", 10, DANO, 2);
        Ataque& atk2= ataques.back();
        atk2.calculaDano = [this, &atk2]() {
            return atk2.baseDmg + (this->nivel * 2) + (atk2.nivel * 1) + (classe->getForca() % 10);

        inventario.adicionar(Equipamento("Gibao de Peles", ARMADURA));
        inventario.adicionar(Equipamento("Machado de Guerra", ARMA));
        inventario.adicionar(Equipamento("Saco de Dormir", ITEM_UTIL));
    };
    }


    else if (cname == "Bardo") {
        ataques.emplace_back("Corte Silencioso", 6, DANO, 10);
        Ataque& atk1 = ataques.back();
        atk1.calculaDano = [this, &atk1]() {
            return atk1.baseDmg + (this->nivel * 2) + (atk1.nivel * 1) + (classe->getCarisma() % 10);
        };

        ataques.emplace_back("Onda Sonora Trovejante", 10, DANO, 2);
        Ataque& atk2 = ataques.back();
        atk2.calculaDano = [this, &atk2]() {
            return atk2.baseDmg + (this->nivel * 2) + (atk2.nivel * 1) + (classe->getCarisma() % 10);
        };

        inventario.adicionar(Equipamento("Roupas de Artista", ARMADURA));
        inventario.adicionar(Equipamento("Rapieira Basica", ARMA));
        inventario.adicionar(Equipamento("Saco de Dormir", ITEM_UTIL));
    }
}


    // ======== Getters ========
    ClasseBase* getClasse() { return classe.get(); }
    int getNivel() const { return nivel; }
    int getVida() const { return vidaAtual; }
    int getVidaMax() const { return vidaMax; }
    int getTurnos() const { return turnosNoDia; }

    std::string getNome() {return nome;}

    void listarHabilidades() { classe->listarHabilidades(); }

    // ======== Habilidades ========
    void treinarHabilidade(int index) {
        if (turnosNoDia >= 10) {
            std::cout << "Voce ja treinou 10 vezes hoje, passe o turno.\n";
            return;
        }

        auto& habs = classe->getHabilidades();
        if (index < 0 || index >= (int)habs.size()) return;

        bool desbloqueou = habs[index].treinar();

        std::cout << "Treinou " << habs[index].getNome() << ". XP: "
                  << habs[index].getXP() << "/" << habs[index].getXPMax() << "\n";

        if (desbloqueou) {
            std::cout << "Habilidade " << habs[index].getNome() << " atingiu 100 XP!\n";
            std::cout << classe->desbloqueioHabilidade(habs[index].getNome()) << "\n";
        }
    }

    // ======== Batalha ========
    int usarAtaque(int index) {
    if (index < 0 || index >= (int)ataques.size())
        return 0;

    Ataque& atk = ataques[index];

    if (atk.tipo == CURA) {
        int cura = atk.calculaDano();
        vidaAtual += cura;
        if (vidaAtual > vidaMax) vidaAtual = vidaMax;

        std::cout << "Voce recuperou " << cura << " de vida!\n";
        atk.ganharXpAtaque(5);
        atk.usosRestantes--;
        return 0;
    }
    else {
        int dano = atk.calculaDano();
        std::cout << "Voce causou " << dano << " de dano!\n";
        atk.ganharXpAtaque(5);
        atk.usosRestantes--;
        return dano;
    }
    }


    void batalha(Enemy& inimigo) {
        std::cout << "\n--- BATALHA CONTRA " << inimigo.getNome() << " ---\n";

        resetAtaques(); // reseta usos no inicio da batalha

        while (vidaAtual > 0 && inimigo.estaVivo()) {
            // Turno do jogador
            listarAtaques();
            int escolha;
            std::cout << "Escolha ataque: ";
            std::cin >> escolha;

            int dano = usarAtaque(escolha - 1);
            inimigo.receberDano(dano);

            if (!inimigo.estaVivo()) break;

            // Turno do inimigo
            int atk = rand() % inimigo.getNumAtaques();
            int danoE = inimigo.usarAtaque(atk);

            std::cout << inimigo.getNome() << " causa " << danoE << " de dano!\n";
            receberDano(danoE);

            if (vidaAtual <= 0) {
                std::cout << "\nVoce foi derrotado!\n";
                break;
            }
        }

        if (vidaAtual > 0){
            std::cout << "Voce venceu o " << inimigo.getNome() << "!\n";
            int xpGanho = 10 + inimigo.getNivel() * 5;
            ganharXP(xpGanho);
            fama +=5;
            ouro += 5*nivel;
        }
    }

    void iniciarEncontroAleatorio() {
        std::vector<std::string> nomes = {
            "Slime", "Esqueleto", "Lobo", "Goblin", "Bandido", "Cultista Fanatico"
        };

        std::string nome = nomes[rand() % nomes.size()];

        Enemy inimigo(nome, nivel);

        std::cout << "\nVoce encontrou um " << nome
                  << " (Nv " << nivel << ")!\n";

        batalha(inimigo);
    }

    //========= Taverna =========

    void visitarTaverna() {
    std::cout << "\nVoce encontrou a taverna The Ivory Wall.\n";
    std::cout << "\nAo entrar, o ambiente aconchegante te acolhe e voce sente seus musculos relaxarem \npor estar em um lugar seguro.\n";
    std::cout << "\nSentado, comendo e se divertindo estao seres de todas as racas possiveis.\n";
    std::cout << "\nAo balcao, uma linda mulher com longos cabelos ruivos e ondulados, cuida da caixa registradora.\n";

    if (!elinaConhece) {
        std::cout << "\t\"Bem vindo a taverna The Ivory Wall, o que deseja?\"\n";
    } else {
        std::cout << "Elina sorri ao te ver novamente.\n";
        std::cout << "\t\"Bem vindo de volta "<<nome<< "! O que deseja?\"\n";
    }

    std::cout << "1 - Alugar quarto\n";
    std::cout << "2 - Algo para beber\n";
    std::cout << "3 - Ir embora\n";

    int e;
    std::cin >> e;
    int op;
    std::string opcao;

    if (e == 1) {
        std::cout << "Voce descansa e recupera o dia.\n";
        turnosNoDia = 10; // força fechar o dia
        return;
    }
    else if (e == 2) {
        if (!elinaConhece) {
            std::cout << "Ela se apresenta gentilmente.\n";
            std::cout << "\t\"Meu nome e Elina Byne, sou a dona da taverna.\"\n";
            std::cout << "Com um sorriso delicado e um simples aceno, voce entende que seria impossivel esquecer Elina.\n";
            elinaConhece = true;
            relElina += 5;
            std::cout << "Relacionamento com Elina: +" << 5 << " (" << relElina << "%)\n";
            relacionamentos["Elina Byne"] = relElina;
        }
        else {
            if(relElina<25 && conversaElina1==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nEla sorri gentilmente.\n";
                std::cout << "\t\"Voce voltou! E bom ver um rosto conhecido por aqui.\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - So queria relaxar um pouco.\n";
                std::cout << "\t2 - Vim para ver voce.\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEla acena a cabeca empaticamente.\n";
                    std::cout << "\t\"Ser um aventureiro deve ser bem cansativo.\"\n";
                    std::cout << "\nEla te faz a bebida que voce aponta do menu com um pequeno sorriso.\n";
                    relElina += 8;
                    std::cout << "Relacionamento com Elina: +" << 8 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (op==2){
                    std::cout << "\nSeus olhos se arregalam e suas bochechas atingem um rubor adoravel.\n";
                    std::cout << "\t\"Voce veio me ver?\"\n";
                    std::cout << "\nEla pergunta timidamente antes de rapidamente se distrair fazendo \na mesma bebida que voce pediu da outra vez.\n";
                    std::cout << "\nVoce sorri ao perceber que ela lembrou seu ultimo pedido.\n";
                    std::cout << "\nTalvez voce nao tenha sido o unico esperando por esse momento.\n";
                    relElina += 10;
                    std::cout << "Relacionamento com Elina: +" << 10 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
            conversaElina1 = true;
            }
            else if(relElina>=25 && relElina<50 && conversaElina2==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nEla acena com um grande sorriso ao ver voce aproximando.\n";
                std::cout << "\t\"Voce parece cansado...tem treinado muito, nao? Posso preparar algo especial para voce, se quiser.\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - Eu aceitaria algo especial.\n";
                std::cout << "\t2 - Voce se preocupa comigo?\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEla sorri antes de comecar a preparar uma bebida habilidosamente.\n";
                    std::cout << "\t\"Quando eu estou cansada, tem uma bebida que eu amo tomar.\"\n";
                    std::cout << "\nEla coloca uma xicara de uma bebida quente amarronzada em sua frente.\n";
                    std::cout << "\t\"Te apresento o chocolate quente.\"\n";
                    std::cout << "\nEla fala com um sorriso antes de empurrar levemente em sua direcao.\n";
                    relElina += 10;
                    std::cout << "Relacionamento com Elina: +" << 8 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (op==2){
                    std::cout << "\nEla sorri timidamente e se inclina no balcao para ficar mais proxima de voce.\n";
                    std::cout << "\t\"Claro. Somos amigos agora, nao?\"\n";
                    std::cout << "\nEla pergunta timidamente.\n";
                    std::cout << "\t\"Amigos se preocupam uns com os outros. Eu me preocupo com voce.\"\n";
                    std::cout << "\nEla fala baixinho timida antes de fazer a mesma bebida que voce sempre pede.\n";
                    relElina += 12;
                    std::cout << "Relacionamento com Elina: +" << 12 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                conversaElina2 =true;
            }
            else if(relElina>=50 && relElina<75 && conversaElina3==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nEla sorri ja iniciando a preparar sua bebida de sempre.\n";
                std::cout << "\t\"Ja faz um tempo que nos encontramos aqui, nao e? Eu...gosto da sua companhia.\"\n";
                std::cout << "\nEla revela e tenta disfarcar suas bochechas rosadas olhando para baixo.\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - Tambem gosto da sua companhia.\n";
                std::cout << "\t2 - Voce e uma boa amiga.\n";
                std::cout << "\t3 - Serio?\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEla tenta esconder um sorriso mas seu rosto mostrava a felicidade que estava sentindo facilmente.\n";
                    std::cout << "\t\"Voce deveria vir mais vezes.\"\n";
                    std::cout << "\nEla diz antes de colocar seu pedido em sua frente.\n";
                    if (fama>=50){
                        std::cout << "\t\"Ouvi dizer que esta ficando famoso. Nao se esqueca de mim!\"\n";
                        std::cout << "\nEla fala com um pequeno riso mudando o assunto.\n";
                    }
                    relElina += 15;
                    std::cout << "Relacionamento com Elina: +" << 15 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (op==2){
                    std::cout << "\nEla te olha e te da um pequeno sorriso que nao chega aos olhos dela.\n";
                    std::cout << "\t\"Ah, claro. Voce tambem e uma boa amizade.\"\n";
                    std::cout << "\nEla fala colocando seu pedido em sua frente.\n";
                    relElina += 10;
                    std::cout << "Relacionamento com Elina: +" << 10 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (op==3){
                    std::cout << "\nO sorriso dela vacila e entao se fecha completamente.\n";
                    std::cout << "\t\"Porque a pergunta? Era para eu nao gostar de voce?\"\n";
                    std::cout << "\nEla pergunta um pouco frustrada antes de te dar seu pedido.\n";
                    relElina -= 15;
                    std::cout << "Relacionamento com Elina: -" << 15 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                conversaElina3 = true;
            }
            else if(relElina>=75 && relElina<100 && conversaElina4==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nElina esta limpando o balcao, sozinha. Seu rosto parece transtornado \ne ela nao percebe voce se aproximando ate que voce senta em frente a ela \n ela pula com um susto e abre um sorriso pequeno que nao chega aos seus olhos.\n";
                std::cout << "\t\"Ah...nem vi voce entrando.\"\n";
                std::cout << "\nEla fala mas sua animacao contagiante nao esta presente em seu rosto.\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - Deixe-me te ajudar com o balcao.\n";
                std::cout << "\t2 - Tem algo te incomodando?\n";
                std::cout << "\t3 - Voce esta linda hoje.\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEla tenta te parar mas entao desiste uma vez que percebe que voce nao vai desistir em ajuda-la.\n";
                    std::cout << "\t\"Obrigada.\"\n";
                    std::cout << "\nEla diz baixinho como se quisesse que apenas voce visse ela vulneravel.\n";
                    relElina += 15;
                    std::cout << "Relacionamento com Elina: +" << 15 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (op==2){
                    std::cout << "\nEla te olha e te da um pequeno sorriso que nao chega aos olhos dela.\n";
                    std::cout << "\t\"Muitas coisas, na verdade, mas nao quero te preocupar.\"\n";
                    std::cout << "\nEla fala mas percebe seu olhar de que nao esta convencido com a resposta dela.\n";
                    std::cout << "\t\"Certo...meu pai esta doente. Todos os curandeiros da regiao falaram que o unico jeito\n\t dele sobreviver seria consumir um remedio feito com a pele de um dragao triturada.\"\n";
                    if (this->inventario.temItem("Pele de Dragao triturada")){
                        std::cout << "\nVoce retira o pequeno pote de pele de dragao triturada de sua bolsa \ne estende em direcao de Elina.\n";
                        std::cout << "\nElina arregala os olhos antes de pegar com as maos tremulas e olhos lacrimejados.\n";
                        std::cout << "\nDe repente ela contorna o balcao antes de te dar um abraco apertado.\n";
                        std::cout << "\t\"Obrigada, muito obrigada.\"\n";
                        std::cout << "\nEla diz com uma voz chorosa ainda te abracando.\n";
                        this->inventario.removeItem("Pele de Dragao triturada");
                        relElina += 25;
                        std::cout << "Relacionamento com Elina: +" << 25 << " (" << relElina << "%)\n";
                        relacionamentos["Elina Byne"] = relElina;
                    }
                    else{
                        std::cout << "\nVoce diz que ira tentar de tudo para conseguir a pele de dragao triturada.\n";
                        std::cout << "\nElina te da um pequeno sorriso antes de te agradecer.\n";
                        relElina += 10;
                        std::cout << "Relacionamento com Elina: +" << 10 << " (" << relElina << "%)\n";
                        relacionamentos["Elina Byne"] = relElina;
                    }

                }
                else if (op==3){
                    std::cout << "\nO pequeno sorriso dela vacila e entao se fecha completamente.\n";
                    std::cout << "\t\"Nao e o melhor momento para isso. Porem agradeco.\"\n";
                    relElina -= 15;
                    std::cout << "Relacionamento com Elina: -" << 15 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                conversaElina4 = true;
            }
            else if(relElina>=100 && conversaElina5==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nNo momento que voce entra na taverna, Elina olha para a porta como se ja estivesse te esperando.\n";
                std::cout << "\nEla entao abre um lindo sorriso timido que faz seu coracao acelerar.\n";
                std::cout << "\nAo se aproximar dela, que aparenta um pouco ansiosa.\n";
                std::cout << "\t\""<<nome<< " eu...tenho pensado muito em voce ultimamente. \n\tQuando voce entra por aquela porta...meu dia melhora.\"\n";
                std::cout << "\nEla revela e tenta disfarcar suas bochechas rosadas olhando para baixo.\n";
                std::cout << "\t\"Eu...gosto muito de voce.\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\tVoce deseja pedir Elina em namoro? (1=sim/2=nao)\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEla olha para voce com olhos arregalados antes de abrir um lindo sorriso.\n";
                    std::cout << "\t\"Sim! E claro que eu quero.\"\n";
                    std::cout << "\nEla diz dando pequenos pulinhos animados.\n";
                    relElina += 40;
                    namorandoElina = true;
                    std::cout << "Relacionamento com Elina: +" << 40 << " (" << relElina << "%)\n";
                    diasNamorandoElina++;
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (op==2){
                    std::cout << "\nVoce diz que tambem gosta muito dela.\n";
                    std::cout << "\nEla sorri com suas palavras.\n";
                    relElina += 10;
                    std::cout << "Relacionamento com Elina: +" << 10 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                conversaElina5 = true;
            }
            else if (relElina >= 100 && conversaElina5 == true && !namorandoElina) {
                std::cout << "Elina parece olhar para voce de um jeito diferente...\n";
                std::cout << "Deseja pedir ela em namoro? (1=sim, 2=nao)\n";
                std::cin >> op;
                std::cout << "\nEla olha para voce com olhos arregalados antes de abrir um lindo sorriso.\n";
                std::cout << "\t\"Sim! E claro que eu quero.\"\n";
                std::cout << "\nEla diz dando pequenos pulinhos animados.\n";
                relElina += 40;
                namorandoElina = true;
                std::cout << "Relacionamento com Elina: +" << 40 << " (" << relElina << "%)\n";
                diasNamorandoElina++;
                relacionamentos["Elina Byne"] = relElina;
            }
            else if (diaAtual==20 && this->inventario.temItem("Flores")){
                std::cout << "\nVoce estende as flores para ela. Os olhos dela arregalam-se e um sorriso abre no rosto dela.\n";
                std::cout << "\t\"Para mim?\"\n";
                relElina += 30;
                std::cout << "Relacionamento com Elina: +" << 30 << " (" << relElina << "%)\n";
                relacionamentos["Elina Byne"] = relElina;
                this->inventario.removeItem("Flores");
            }

            else if (namorandoElina && diasNamorandoElina<30){
                int chance = rand() % 101;
                if(chance==1 || chance==100){
                    std::cout << "\n Evento RARO com Elina! \n";
                    std::cout << "\nAo visitar a taverna, ela te puxa discretamente pela mao para os fundos.\nVoces compartilham um momento inesperadamente intimo.\n";
                    relElina += 30;
                    std::cout << "Relacionamento com Elina: +" << 30 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (chance>1 && chance<=10){
                    std::cout << "\n Evento NEGATIVO com Elina.\n";
                    std::cout << "\nEla parece distante hoje. Responde curto, evitando contato visual.\nTalvez esteja estressada com a taverna.\n";
                    relElina -= 5;
                    std::cout << "Relacionamento com Elina: -" << 5 << " (" << relElina << "%)\n";
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (chance > 10 && chance <= 25) {
                    std::cout << "\nElina te manda uma cesta de paes doces da taverna.\n";
                    std::cout << "+3 Relacionamento com Elina.\n";
                    relElina += 3;
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (chance > 25 && chance <= 40) {
                    std::cout << "\nElina te envia uma carta escrita a mao:\n";
                    std::cout << "\n\"Espero que seu dia esteja brilhando. Pensei em voce hoje.\"\n";
                    std::cout << "+5 Relacionamento com Elina.\n";
                    relElina += 5;
                    relacionamentos["Elina Byne"] = relElina;
                }
                else if (chance > 40 && chance <= 55) {
                    std::cout << "\nEvento especial! Elina te chama para ajudar na Taverna.\n";
                    std::cout << "\nVoces passam um tempo juntos conversando e rindo.\n";
                    std::cout << "+10 Relacionamento com Elina.\n";
                    relElina += 10;
                    relacionamentos["Elina Byne"] = relElina;
                }
            }
            else if (namorandoElina && diasNamorandoElina>=30 && !casadoElina){
                std::cout << "\nElina parece olhar para voce de um jeito diferente...\n";
                std::cout << "\t\"\nEu nunca pensei que um aventureiro mudaria minha vida assim...\n\tVoce aceitaria... uma vida ao meu lado?\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1=sim/2=nao\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nElina sorri lindamente e te puxa para um beijo.\n";
                    std::cout << "\nVoce e Elina agora estao casados.\n";
                    casadoElina=true;
                }
                if (op==2){
                    std::cout << "\nVoce realmente quer quebrar o coracao dela?! Qual seu problema?!.\n";
                    std::cout << "\nVoce e Elina agora estao casados.\n";
                    casadoElina=true;
                }
            }
            else {
                std::cout << "Voces conversam um pouco.\n";
                relElina += 10;
                relacionamentos["Elina Byne"] = relElina;
            }
        }
    }

    }

    void visitarMercado(){
    std::cout << "\nVoce encontrou o Mercado Finchey.\n";
    std::cout << "\nAo entrar, o ambiente borbulha com clientes fazendo suas compras.\n";
    std::cout << "\nConversando e olhando produtos, estavam seres de todas as racas possiveis.\n";
    std::cout << "\nAo balcao, um belo homem com cabelos pretos e baguncados com o vento, cuida da caixa registradora.\n";

    if (!elinaConhece) {
        std::cout << "\t\"Bem vindo ao Mercado Finchey, o que deseja?\"\n";
    } else {
        std::cout << "Arryn sorri e acena ao te ver novamente.\n";
        std::cout << "\t\"Bem vindo de volta "<<nome<< "! O que deseja?\"\n";
    }

    std::cout << "1 - Comprar Comida\n";
    std::cout << "2 - Conversar com Arryn\n";
    std::cout << "3 - Ir embora\n";

    int e;
    std::cin >> e;
    int op;
    std::string opcao;

    if (e == 1) {
        std::cout << "Voce compra comida e sua fome e saciada.\n";
        vidaAtual +=30;
        if(vidaAtual>vidaMax){
            vidaAtual=vidaMax;
        }
        return;
    }
    else if (e == 2) {
        if (!arrynConhece) {
            std::cout << "Ele se apresenta com uma voz amigavel.\n";
            std::cout << "\t\"Meu nome e Arryn Fincher, sou o dono do mercado.\"\n";
            std::cout << "Com um sorriso confiante e uma aura extrovertida, voce entende que seria impossivel esquecer Arryn.\n";
            arrynConhece = true;
            relArryn += 5;
            std::cout << "Relacionamento com Arryn: +" << 5 << " (" << relArryn << "%)\n";
            relacionamentos["Arryn Fincher"] = relArryn;
        }
        else {
            if(relArryn<25 && conversaArryn1==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nEle sorri ao te ver.\n";
                std::cout << "\t\"Voce voltou! E bom ver um rosto conhecido por aqui.\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - So olhando mesmo.\n";
                std::cout << "\t2 - Vim por sua causa.\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEle acena a cabeca com um grande sorriso.\n";
                    std::cout << "\t\"Acabou de chegar frutas fresquinhas, vou trazer algumas para voce.\"\n";
                    std::cout << "\nEle te traz algumas uvas, macas e morangos.\n";
                    relArryn += 8;
                    std::cout << "Relacionamento com Arryn: +" << 8 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (op==2){
                    std::cout << "\nArryn solta uma risada alta e feliz.\n";
                    std::cout << "\t\"Voce veio por minha causa? Nao me diga que se apaixonou a primeira vista?\"\n";
                    std::cout << "\nEle pergunta brincalhao antes de trazer morangos, a mesma fruta que voce comprou da outra vez.\n";
                    std::cout << "\nVoce sorri ao perceber que ele lembrou sua ultima compra.\n";
                    std::cout << "\nTalvez voce nao tenha sido o unico esperando por esse momento.\n";
                    relArryn += 10;
                    std::cout << "Relacionamento com Arryn: +" << 10 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
            conversaArryn1 = true;
            }
            else if(relArryn>=25 && relArryn<50 && conversaArryn2==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nAo entrar no mercado voce percebe um lindo cachecol ao lado de uma das caixas de ovos.\n";
                std::cout << "\nVoce pega o cachecol antes de decidir deixa-lo com Arryn para caso o dono volte a procurar por ele.\n";
                std::cout << "\nAo te ver aproximando com o cachecol em maos, Arryn parece surpreso antes de dar a volta no balcao \n e se aproximar de voce com um sorriso.\n";
                std::cout << "\t\"Achei que tinha perdido meu cachecol! Muito obrigado meu grande heroi.\"\n";
                std::cout << "\nArryn fala brincalhao antes de pegar o cachecol de suas maos e piscar para voce.\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - Heroi?\n";
                std::cout << "\t2 - De nada, principe.\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEle sorri antes de retornar para tras do balcao.\n";
                    std::cout << "\t\"Claro, quem salva o pobre indefeso de perder seu amado cachecol so poderia ser um heroi.\"\n";
                    std::cout << "\nArryn fala antes de colocar o cachecol no pescoco dele.\n";
                    std::cout << "\t\"Eu nao teria aguentado o dia inteiro sem ter ele, obrigado.\"\n";
                    std::cout << "\nEle fala com um sorriso antes de se virar e trazer morangos para voce.\n";
                    relArryn += 10;
                    std::cout << "Relacionamento com Arryn: +" << 8 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (op==2){
                    std::cout << "\nEle parece ficar um pouco surpreso com voce brincando de volta e depois ri.\n";
                    std::cout << "\t\"Principe? Gostei.\"\n";
                    std::cout << "\nEle fala tentando esconder o rubor em suas orelhas colocando o cachecol.\n";
                    std::cout << "\t\"Voce tem uma labia e tanto. Cuidado que eu apaixono facil.\"\n";
                    std::cout << "\nEle zoa antes de retornar para tras do balcao.\n";
                    relArryn += 12;
                    std::cout << "Relacionamento com Arryn: +" << 12 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                conversaArryn2 =true;
            }
            else if(relArryn>=50 && relArryn<75 && conversaArryn3==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nVoce chega ao mercado uma hora antes do normal apenas para encontra-lo fechado.\n";
                std::cout << "\nOlhando ao redor voce encontra Arryn se aproximando segurando chaves e parecendo surpreso.\n";
                std::cout << "\t\"O que voce esta fazendo aqui tao cedo? Vamos, entre.\"\n";
                std::cout << "\nEle pergunta antes de destrancar a porta e abri-la deixando passagem para voce antes de fechar a porta.\n";
                std::cout << "\t\"O mercado so abre daqui uma hora, entao espero que voce nao se incomode esperando um pouco.\"\n";
                std::cout << "\nEle fala com um sorriso antes de comecar a carregar algumas caixas que estavam no canto.\n";
                std::cout << "\t\"Vou te deixar por aqui enquanto abasteco o estoque, limpo o chao e arrumo o restante das coisas.\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - Precisa de ajuda com isso?\n";
                std::cout << "\t2 - Voce faz isso todo dia sozinho?\n";
                std::cout << "\t3 - Nossa, que trabalheira!\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEle sorri no momento em que voce pega algumas das caixas.\n";
                    std::cout << "\t\"Nao e que voce e mais forte do que eu pensava?\"\n";
                    std::cout << "\nEle fala brincalhao rindo.\n";
                    if (fama>=50){
                        std::cout << "\t\"Sua fama esta por todo lugar, sabia? Todo mundo fala de voce.\"\n";
                        std::cout << "\nEle fala com um sorriso mudando o assunto.\n";
                    }
                    relArryn += 15;
                    std::cout << "Relacionamento com Arryn: +" << 15 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (op==2){
                    std::cout << "\nEle te olha e te da um pequeno sorriso.\n";
                    std::cout << "\t\"Poise. Um pouco solitario, nao?\"\n";
                    std::cout << "\nEle fala antes de caminhar para fora do seu campo visual.\n";
                    relArryn += 10;
                    std::cout << "Relacionamento com Arryn: +" << 10 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (op==3){
                    std::cout << "\nO sorriso dele vacila e entao se fecha completamente.\n";
                    std::cout << "\t\"Nem me fala.\"\n";
                    std::cout << "\nEle diz rapidamente antes de caminhar para fora do seu campo visual.\n";
                    relArryn -= 5;
                    std::cout << "Relacionamento com Arryn: -" << 5 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                conversaArryn3 = true;
            }
            else if(relArryn>=75 && relArryn<100 && conversaArryn4==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nArryn esta fechando o mercado quando voce se aproxima. Ele te olha e entao te da um sorriso.\n";
                std::cout << "\t\"Chegou na hora certa. Estou indo para o festival das luzes na pracinha. Quer me acopanhar?\"\n";
                std::cout << "\nEle pergunta com um sorriso expectante como se esperasse o seu sim.\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1 - Claro!\n";
                std::cout << "\t2 - Com voce eu vou a qualquer lugar.\n";
                std::cout << "\t3 - Deixa para a proxima.\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEle sorri antes de segurar sua mao e puxar voce para andar com ele.\n";
                    std::cout << "\t\"Vamos! Eu ouvi dizer que vai ter barraquinhas de comida de graca\"\n";
                    std::cout << "\nEle diz com um sorriso antes de te guiar ate o festival ocorrendo na pracinha.\n";
                    std::cout << "\nDurante o evento, voce e Arryn brincam nas barracas de jogos, comem comidas e conversam.\n";
                    relArryn += 15;
                    std::cout << "Relacionamento com Arryn: +" << 15 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (op==2){
                    std::cout << "\nEle te olha e te da um pequeno sorriso timido antes de revirar os olhos.\n";
                    std::cout << "\t\"Uma verdadeira labia surpreendente.\"\n";
                    std::cout << "\nEle fala antes de seguir em frente andando.\n";
                    std::cout << "\t\"Vamos entao, voce vai ter que me pagar pelo menos uma porcao de ensopado.\"\n";
                    std::cout << "\nDurante o evento, voce e Arryn brincam nas barracas de jogos, comem comidas e conversam.\n";
                    std::cout << "\nArryn aproveita a porcao de ensopado sentado em um dos bancos do parque. Voce senta ao lado dele.\n";
                    std::cout << "\nDe repente o show de luzes inicia, com moradores deixando baloes iluminados voar no ceu noturno.\n";
                    std::cout << "\t\"Linda vista, nao e?\"\n";
                    std::cout << "\nEle diz olhando as luzes no ceu que iluminam o belo rosto.\n";
                    std::cout << "\nVoce nao olha para as luzes, mas ainda assim a vista parece linda aos seus olhos.\n";
                    relArryn += 25;
                    std::cout << "Relacionamento com Arryn: +" << 25 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;

                }
                else if (op==3){
                    std::cout << "\nO sorriso dele vacila e entao se fecha completamente.\n";
                    std::cout << "\t\"Ah...certo. Te vejo depois entao.\"\n";
                    relArryn -= 15;
                    std::cout << "Relacionamento com Arryn: -" << 15 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                conversaArryn4 = true;
            }
            else if(relArryn>=100 && conversaArryn5==false){
                std::cout << "\t\n================ NOVO DIALOGO =====================\n";
                std::cout << "\nNo momento que voce entra no mercado, Arryn preparava tudo para fechar.\n";
                std::cout << "\nEle olha em sua direcao e entao abre um lindo sorriso que faz seu coracao acelerar.\n";
                std::cout << "\nEle se aproxima calmamente antes ajeitar o proprio cabelo que estava levemente baguncado.\n";
                std::cout << "\t\""<<nome<< " eu ja estava fechando tudo. Me acompanha ate o parque depois que eu terminar aqui?\"\n";
                std::cout << "\nEle pergunta com um sorriso. Apos terminar tudo e fechar o mercado voces andam em direcao ao parque.\n";
                std::cout << "\nAo chegar no parque, ele senta em um banco antes de olhar para voce com um pequeno sorriso.\n";
                std::cout << "\t\""<<nome<< " nao sei mais esconder...voce ja faz parte da minha rotina, sabe?\"\n";
                std::cout << "\t\"Voce...gostaria de namorar comigo?\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\tVoce deseja aceitar o pedido de Arryn? (1=sim/2=nao)\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nEle olha para voce antes de abrir um lindo sorriso.\n";
                    std::cout << "\t\"Fico feliz que tenha aceitado. Depois de tantas brincadeiras eu realmente me apaixonei.\"\n";
                    std::cout << "\nEle diz rindo antes de te abracar.\n";
                    relArryn += 40;
                    namorandoArryn = true;
                    std::cout << "Relacionamento com Arryn: +" << 40 << " (" << relArryn << "%)\n";
                    diasNamorandoArryn++;
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (op==2){
                    std::cout << "\nO sorriso de Arryn vacila e entao se fecha completamente.\n";
                    std::cout << "\nEle se levanta do banco e vai embora.\n";
                    relArryn -= 10;
                    std::cout << "Relacionamento com Arryn: -" << 10 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                conversaArryn5 = true;
            }
            else if (relArryn >= 100 && conversaArryn5 == true && !namorandoArryn) {
                std::cout << "Arryn parece olhar para voce de um jeito diferente...\n";
                std::cout << "Deseja pedir ele em namoro? (1=sim, 2=nao)\n";
                std::cin >> op;
                std::cout << "\nEle olha para voce com olhos arregalados antes de abrir um lindo sorriso.\n";
                std::cout << "\t\"Sim! E claro que eu quero.\"\n";
                std::cout << "\nEle diz antes de te abracar.\n";
                relArryn += 40;
                namorandoArryn = true;
                std::cout << "Relacionamento com Arryn: +" << 40 << " (" << relArryn << "%)\n";
                diasNamorandoArryn++;
                relacionamentos["Arryn Fincher"] = relArryn;
            }
            else if (diaAtual==25 && this->inventario.temItem("Torta de Morango")){
                std::cout << "\nVoce mostra a torta de morango para ele. Os olhos dele arregalam-se e um sorriso abre no rosto dele.\n";
                std::cout << "\t\"Para mim?\"\n";
                relArryn += 30;
                std::cout << "Relacionamento com Arryn: +" << 30 << " (" << relArryn << "%)\n";
                relacionamentos["Arryn Fincher"] = relArryn;
                this->inventario.removeItem("Torta de Morango");
            }

            else if (namorandoArryn && diasNamorandoArryn<30){
                int chance = rand() % 101;
                if(chance==1 || chance==100){
                    std::cout << "\n Evento RARO com Arryn! \n";
                    std::cout << "\nAo passar pelo mercado, Arryn te abraça inesperadamente e te puxa para um beijo atras do balcao\n";
                    relArryn += 30;
                    std::cout << "Relacionamento com Arryn: +" << 30 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (chance>1 && chance<=10){
                    std::cout << "\n Evento NEGATIVO com Arryn.\n";
                    std::cout << "\nEle esta irritado com fornecedores e acaba sendo seco com voce.\nEle se desculpa de leve, mas o clima ficou estranho.\n";
                    relArryn -= 5;
                    std::cout << "Relacionamento com Arryn: -" << 5 << " (" << relArryn << "%)\n";
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (chance > 10 && chance <= 25) {
                    std::cout << "Arryn passa no seu caminho e te entrega algumas frutas frescas.\n";
                    std::cout << "+3 Relacionamento com Arryn.\n";
                    relArryn += 3;
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (chance > 25 && chance <= 40) {
                    std::cout << "\nArryn te envia um bilhete:\n";
                    std::cout << "\n\"Pensei em voce hoje. Nao vejo a hora de te ver.\"\n";
                    std::cout << "+5 Relacionamento com Arryn.\n";
                    relArryn += 5;
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
                else if (chance > 40 && chance <= 55) {
                    std::cout << "\nEvento especial! Arryn te convida para ajudar no mercado.\n";
                    std::cout << "\nVoces arrumam prateleiras e conversam num clima descontraido.\n";
                    std::cout << "+10 Relacionamento com Arryn.\n";
                    relArryn += 10;
                    relacionamentos["Arryn Fincher"] = relArryn;
                }
            }
            else if (namorandoArryn && diasNamorandoArryn>=30 && !casadoArryn){
                std::cout << "\nArryn parece olhar para voce de um jeito diferente...\n";
                std::cout << "\t\"\nEu nunca pensei que encontraria alguem como voce...\n\tMas aqui estamos. Quer dividir uma vida comigo?\"\n";
                std::cout << "\t\n=====================================\n";
                std::cout << "\t1=sim/2=nao\n";
                std::cin >> op;
                if (op==1){
                    std::cout << "\nArryn sorri lindamente e te puxa para um beijo.\n";
                    std::cout << "\nVoce e Arryn agora estao casados.\n";
                    casadoArryn=true;
                }
                if (op==2){
                    std::cout << "\nVoce realmente quer quebrar o coracao dele?! Qual seu problema?!.\n";
                    std::cout << "\nVoce e Arryn agora estao casados.\n";
                    casadoArryn=true;
                }
            }
            else {
                std::cout << "Voces conversam um pouco.\n";
                relArryn += 10;
                relacionamentos["Arryn Fincher"] = relArryn;
            }
        }
    }

    }


    // ======== Turnos ========
    void passarTurno() {
        turnosNoDia++;
        std::cout << "\n=== Dia " << diaAtual << ", Turno " << turnosNoDia << "/10 ===\n";
        if(turnosNoDia == 9 && diaAtual==20 && elinaConhece){
            std::cout << "Hoje e aniversario da Elina! Deseja colher flores como presente? (1=sim/ 2=nao)";
            int op;
            std::cin >> op;
            if (op==1){
            inventario.adicionar(Equipamento("Flores", ITEM_UTIL));
            visitarTaverna();
            }
            return;
        }
        if(turnosNoDia == 5 && diaAtual==25 && arrynConhece){
            std::cout << "Voce faz uma torta de morangos e se lembra que e o doce favorito de Arryn! \nDeseja levar para ele como presente? (1=sim/ 2=nao)";
            int op;
            std::cin >> op;
            if (op==1){
            inventario.adicionar(Equipamento("Torta de Morango", ITEM_UTIL));
            visitarMercado();
            }
            return;
        }
        int chance = rand() % 100; // 0..99
        if (chance < 35) { // 35% de chance
            iniciarEncontroAleatorio();
        }

        //Mercado=Arryn
        if (turnosNoDia == 4 || turnosNoDia == 5) {
            if (rand() % 100 < 35) {
                visitarMercado();
            }
        }

        //Taverna=Elina
        if ((turnosNoDia == 9 || turnosNoDia == 10)) {
            if (rand() % 100 < 35) {
                visitarTaverna();
            }
        }

        if (turnosNoDia >= 10) {
            vidaAtual= vidaAtual+ (vidaMax%100) + 30;
            if (vidaAtual>vidaMax){
                vidaAtual=vidaMax;
            }
            diaAtual++;
            if (namorandoElina){
                diasNamorandoElina++;
            }
            if (namorandoArryn){
                diasNamorandoArryn++;
            }
            turnosNoDia = 0;
            for (auto& h : classe->getHabilidades()) h.novoDia();
            std::cout << "\n>> O dia acabou. Agora e Dia " << diaAtual << ".\n";
            std::cout << "Voce pode treinar habilidades novamente.\n";
            if (casadoElina){
                std::cout << "Elina te da um beijo de bom dia antes de te deixar sair da cama.\n";
                if (diaAtual%10==2 || diaAtual%10==4 || diaAtual%10==6 || diaAtual%10==8 || diaAtual%10==0){
                    prole();
                }
            }
            if (casadoArryn){
                std::cout << "Arryn nao te deixou sair da cama enquanto voce nao deu um beijo de bom dia nele.\n";
                if (diaAtual%10==2 || diaAtual%10==4 || diaAtual%10==6 || diaAtual%10==8 || diaAtual%10==0){
                    prole();
                }
            }
            std::cout << "Dormir te faz recuperar " << (vidaMax%100)<<"de vida.";
        }
    }

    // ======== Ataques ========
    void listarAtaques() {
        std::cout << "\n== Ataques disponiveis ==\n";
        for (size_t i = 0; i < ataques.size(); i++) {
            std::cout << i+1 << " - " << ataques[i].nome
                      << " (Usos restantes: " << ataques[i].usosRestantes
                      << "/" << ataques[i].maxUsosPorBatalha << ")\n";
        }
    }

    void resetAtaques() {
        for (auto& a : ataques) a.usosRestantes = a.maxUsosPorBatalha;
    }

    // ======== Inventario ========
    void listarInventario() { inventario.listar(); }

    void receberDano(int d) {
        vidaAtual -= d;
        if (vidaAtual < 0) vidaAtual = 0;
    }

    // ======== XP ========
    void ganharXP(int xp) {
        xpAtual += xp;
        std::cout << "Ganhou " << xp << " XP! (Atual: " << xpAtual << "/" << xpParaProximoNivel << ")\n";
        while (xpAtual >= xpParaProximoNivel) {
            xpAtual -= xpParaProximoNivel;
            subirNivel();
        }
    }

    void subirNivel() {
    nivel++;
    vidaMax += 35;
    vidaAtual = vidaMax;
    xpParaProximoNivel = nivel * 50;
    std::cout << "Parabens! Voce subiu para o nivel " << nivel << "!\n";

    }

    //====== Status =======

    void mostrarStatus(const MissaoManager& mm) const {
    std::cout << "\n=====================================================\n";
    std::cout << "                       STATUS\n";
    std::cout << "=====================================================\n";

    // ------------------------------------------
    // Informaçoes basicas
    // ------------------------------------------
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Genero: " << genero << "\n";
    std::cout << "Classe: " << classe->getNome()
              << " (Lvl. " << nivel << ")\n";

    std::cout << "PV: " << vidaAtual << "/" << vidaMax << "\n";

    std::cout << "Forca: " << classe->getForca() << "\n";
    std::cout << "Agilidade: " << classe->getAgilidade() << "\n";
    std::cout << "Energia: " << classe->getEnergia() << "\n";
    std::cout << "Carisma: " << classe->getCarisma() << "\n";
    std::cout << "Inteligencia: " << classe->getInteligencia() << "\n";

    std::cout << "Fama: " << fama << "\n";
    std::cout << "Ouro: " << ouro << "\n";
    std::cout << "XP: " << xpAtual << "/" << xpParaProximoNivel << "\n";

    std::cout << "-----------------------------------------------------\n";

    // ------------------------------------------
    // Habilidades
    // ------------------------------------------
    std::cout << "Habilidades:\n";

    for (const auto& h : classe->getHabilidades()) {
        std::cout << "  - " << h.getNome()
                  << " (Lvl. " << h.getLevel() << ") "
                  << "(" << h.getXP() << "/" << h.getXPMax() << " XP)\n";
    }

    std::cout << "-----------------------------------------------------\n";

    // ------------------------------------------
    // Ataques
    // ------------------------------------------
    std::cout << "Ataques:\n";

    for (const auto& atk : ataques) {
        std::cout << "  - " << atk.nome
                  << " (Dano Base:" << atk.baseDmg << ") "
                  << "(Lvl. " << atk.nivel << ") "
                  << "(" << atk.xp << "/" << atk.xpMax << " XP)\n";
    }

    std::cout << "-----------------------------------------------------\n";

    // ------------------------------------------
    // Inventario
    // ------------------------------------------
    std::cout << "Inventario (" << inventario.getItens().size()
              << "/" << inventario.getCapacidade() << "):\n";

    for (const auto& item : inventario.getItens()) {
        std::cout << "  - " << item.nome << "\n";
    }

    if (inventario.getItens().empty())
        std::cout << "  (vazio)\n";

    std::cout << "-----------------------------------------------------\n";

    // ------------------------------------------
    // Relacionamentos
    // ------------------------------------------
    std::cout << "Relacionamentos:\n";

    if (relacionamentos.empty()) {
        std::cout << "  (Nenhum NPC conhecido ainda)\n";
    }
    else {
        for (auto& par : relacionamentos) {
            std::cout << "  - " << par.first
                      << " (" << par.second << "/100 Love Points)\n";
        }
    }

    std::cout << "-----------------------------------------------------\n";

    std::cout << "Filhos:\n";
    if (filhos.empty()) {
        std::cout << "  (Nenhum filho ainda)\n";
    }
    else {
        mostrarFilhos();
    }
    std::cout << "-----------------------------------------------------\n";

    // ------------------------------------------
    // Missoes
    // ------------------------------------------
    std::cout << "Missoes Ativas:\n";
    if (mm.getAtivas().empty()) {
        std::cout << "  (Nenhuma)\n";
    } else {
        for (auto& m : mm.getAtivas()) {
            std::cout << "  - " << m.getNome()
                      << " (" << m.getProgressoAtual()
                      << "/" << m.getProgressoNecessario() << ")\n";
        }
    }

    std::cout << "Missoes Concluidas:\n";
    if (mm.getConcluidas().empty()) {
        std::cout << "  (Nenhuma)\n";
    } else {
        for (auto& m : mm.getConcluidas()) {
            std::cout << "  - " << m.getNome() << "\n";
        }
    }

    std::cout << "Missoes Falhadas:\n";
    if (mm.getFalhadas().empty()) {
        std::cout << "  (Nenhuma)\n";
    } else {
        for (auto& m : mm.getFalhadas()) {
            std::cout << "  - " << m.getNome() << "\n";
        }
    }

    std::cout << "=====================================================\n\n";
}

    //======== Filhos ==========
    void adicionarFilho(const std::string& nomeFilho, const std::string& nomeProgenitor, bool adotado) {
        Filho f;
        f.nomeFilho = nomeFilho;
        f.progenitor1 = nome;        // o player e o pai
        f.progenitor2 = nomeProgenitor;
        f.adotado= adotado;
        filhos.push_back(f);
    }

    void mostrarFilhos() const {
        if (filhos.empty()) {
            std::cout << "Voce nao tem filhos registrados.\n";
            return;
        }

        std::cout << "\n--- Registro de Filhos ---\n";
        for (const auto& f : filhos) {
            if (f.adotado){
            std::cout << "Nome: " << f.nomeFilho
                      << " | Progenitor 1: " << f.progenitor1
                      << " | Progenitor 2: " << f.progenitor2 << "| Adotado\n";
            }
            else{
            std::cout << "Nome: " << f.nomeFilho
                      << " | Progenitor 1: " << f.progenitor1
                      << " | Progenitor 2: " << f.progenitor2 << "\n";
            }
        }
        std::cout << "--------------------------\n";
    }

    void prole(){
        if (casadoArryn && (genero=="F" || genero=="f")){
            int prole = rand()%2;
            if (prole==1){
            int filho= rand() % 100;
            if (filho<50){
                std::cout << "Voce agora tem uma filha com Arryn. Escolha o nome da menina:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Arryn", 0);
                }
            if (filho>=50){
                std::cout << "Voce agora tem um filho com Arryn. Escolha o nome do menino:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Arryn", 0);
                }
            }
        }
        if (casadoArryn && (genero=="M" || genero=="m")){
            int prole = rand()%2;
            if (prole==1){
            int filho= rand() % 100;
            if (filho<50){
                std::cout << "Voce agora tem uma filha com Arryn. Escolha o nome da menina:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Arryn", 1);
                }
            if (filho>=50){
                std::cout << "Voce agora tem um filho com Arryn. Escolha o nome do menino:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Arryn", 1);
                }
            }
        }
        if (casadoElina && (genero=="F" || genero=="f")){
            int prole = rand()%2;
            if (prole==1){
            int filho= rand() % 100;
            if (filho<50){
                std::cout << "Voce agora tem uma filha com Elina. Escolha o nome da menina:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Elina", 1);
                }
            if (filho>=50){
                std::cout << "Voce agora tem um filho com Elina. Escolha o nome do menino:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Elina", 1);
                }
            }
        }
        if (casadoElina && (genero=="M" || genero=="m")){
            int prole = rand()%2;
            if (prole==1){
            int filho= rand() % 100;
            if (filho<50){
                std::cout << "Voce agora tem uma filha com Elina. Escolha o nome da menina:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Elina", 0);
                }
            if (filho>=50){
                std::cout << "Voce agora tem um filho com Elina. Escolha o nome do menino:\n";
                std::string nomefilho;
                std::getline(std::cin, nomefilho);
                adicionarFilho(nomefilho, "Elina", 0);
                }
            }
        }
    }
};
