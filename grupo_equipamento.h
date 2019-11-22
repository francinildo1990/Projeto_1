#ifndef GRUPO_EQUIPAMENTO_H
#define GRUPO_EQUIPAMENTO_H

#include<QString>
#include<QVector>
#include<algorithm>
#include<equipamento.h>
#include <QFile>


class Grupo_Equipamento
{

private:
    QVector<Equipamento> casa;

public:
   Grupo_Equipamento();
    double getMaiorPotencia();
    double getMenorPotencia();
    double getPotenciaMedia();
    void inserirCadastro(Equipamento a);
    void ordenarPorNome();
    void ordenarPorPotencia();
    int size();
    void salvarDados(QString file);
    void carregarDados(QString file);


    Equipamento operator[](int indice);

};

   bool compararPorPotencia(Equipamento a, Equipamento b);


#endif // GRUPO_EQUIPAMENTO_H



