#include "grupo_equipamento.h"

Grupo_Equipamento::Grupo_Equipamento()
{

}

double Grupo_Equipamento::getMaiorPotencia(){

   Equipamento *a = std::max_element(casa.begin(),casa.end(),compararPorPotencia);
    return  a->getPotencia();
}

double Grupo_Equipamento::getMenorPotencia(){

    Equipamento *a = std::min_element(casa.begin(),casa.end(),compararPorPotencia);
    return  a->getPotencia();
}

double Grupo_Equipamento::getPotenciaMedia(){
    double media = 0;
    for(auto e : casa){
        media+=e.getPotencia();
    }
    return  media/casa.size();
}

void Grupo_Equipamento::inserirCadastro(Equipamento a){
    casa.push_back(a);
}

void Grupo_Equipamento::ordenarPorNome(){
    std::sort(casa.begin(),casa.end(),[](Equipamento a, Equipamento b){
        return a.getEquipamento()<b.getEquipamento();

    });
}

void Grupo_Equipamento::ordenarPorPotencia(){
    std::sort(casa.begin(),casa.end(),[](Equipamento a, Equipamento b){
        return a.getPotencia()<b.getPotencia();

    });
}

int Grupo_Equipamento::size(){
    return casa.size();
}

Equipamento Grupo_Equipamento::operator[](int indice){
    return casa[indice];
}

bool compararPorPotencia(Equipamento a, Equipamento b){

    return a.getPotencia()<b.getPotencia();
}

void Grupo_Equipamento::salvarDados(QString file)
{
    QFile arquivo(file);

    arquivo.open(QIODevice::WriteOnly);

    for(auto a:casa){
        QString linha = a.getEquipamento() + "," +  QString::number(a.getPotencia()) + "," + QString::number(a.calcularEnergia()) +"\n";
        arquivo.write(linha.toLocal8Bit());
    }
    arquivo.close();

}


void Grupo_Equipamento::carregarDados(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::ReadOnly);


    QString linha;
    QStringList dados;
    while(!arquivo.atEnd()){
        Equipamento casa;
        linha = arquivo.readLine();
        dados = linha.split(",");
        casa.setEquipamento(dados[0]);
        casa.setPotencia(dados[1].toFloat());
        //casa.calcularEnergia(dados[2].toFloat());
        inserirCadastro(casa);
    }
    arquivo.close();

}

void Grupo_Equipamento::remover(int i){

    casa.erase(casa.begin()+i);
}
