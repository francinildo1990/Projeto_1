#ifndef GRUPO_EQUIPAMENTO_H
#define GRUPO_EQUIPAMENTO_H

#include<QString>
#include<QVector>
#include<algorithm>
#include<equipamento.h>
#include <QFile>
#include <QStringList>
#include <QObject>


class Grupo_Equipamento
{

private:
    QVector<Equipamento> casa;

public:
   Grupo_Equipamento();
    float getMaiorPotencia();
    float getMenorPotencia();
    float getPotenciaMedia();
    void inserirCadastro(Equipamento a);
    void ordenarPorNome();
    void ordenarPorPotencia();
    void remover(int i);
    int size();
    void salvarDados(QString file);
    void carregarDados(QString file);


    Equipamento operator[](int indice);

};

   bool compararPorPotencia(Equipamento a, Equipamento b);


#endif // GRUPO_EQUIPAMENTO_H



