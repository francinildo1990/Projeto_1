#include "equipamento.h"

Equipamento::Equipamento()
{

}


QString Equipamento::getEquipamento() const
{
    return aparelho;
}

void Equipamento::setEquipamento(const QString &valeu)
{
    if(valeu.size()>3){
    aparelho = valeu;
    }
    else
        aparelho = "Nome inválido";
}

float Equipamento::getPotencia() const
{
    return potencia;

}

void Equipamento::setPotencia(const float &valeu)
{

    if(valeu > 0){
    potencia = valeu;
    }

}

float Equipamento::getTempo() const
{
    return tempo;
}

void Equipamento::setTempo(const float &valeu)
{

   if(valeu > 0){
   tempo = valeu;
    }
}


float Equipamento::getIluminacao()const
{
    return iluminacao;
}

void Equipamento::setIluminacao(const float &valeu)
{
    if(valeu > 0){
    iluminacao = valeu;
     }

}


float Equipamento::getTarifa()const
{
    return tarifa;
}

void Equipamento::setTarifa(const float &valeu)
{
    if(valeu > 0){
    tarifa = valeu;
     }

}


float Equipamento::calcularEnergia(){


    return (potencia*tarifa*tempo)/1000;

}
