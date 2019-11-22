#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include<QString>
#include<QVector>


class Equipamento
{
public:
    Equipamento();

    QString getEquipamento() const;
    void setEquipamento(const QString &valeu);

    float getPotencia()const;
    void setPotencia(const float &valeu);


    float getTempo() const;
    void setTempo(const float &valeu);


    float getTarifa()const;
    void setTarifa(const float &valeu);


    float getIluminacao()const;
    void setIluminacao(const float &valeu);

    float calcularEnergia();

private:

    QString aparelho;
    float potencia;
    float iluminacao;
    float tarifa;
    float tempo;
};

#endif // EQUIPAMENTO_H
