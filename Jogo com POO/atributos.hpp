#ifndef ATRIBUTOS_HPP
#define ATRIBUTOS_HPP

struct Atributos {
    int forca;
    int agilidade;
    int energia;
    int carisma;
    int inteligencia;
    int vida;

    Atributos() : forca(0), agilidade(0), energia(0),
                  carisma(0), inteligencia(0), vida(0) {}

    Atributos(int f, int a, int e, int c, int i, int v)
        : forca(f), agilidade(a), energia(e), carisma(c),
          inteligencia(i), vida(v) {}
};

#endif // ATRIBUTOS_HPP
