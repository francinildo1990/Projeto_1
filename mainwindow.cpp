#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipamento.h"
#include "grupo_equipamento.h"
#define MES 31

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonCadastrarEquipamento_clicked()
{
    Equipamento cadastro;

    cadastro.setEquipamento(ui->inputEquipamento->text());
    cadastro.setPotencia(ui->inputPotencia->text().toFloat());
    cadastro.setTempo(ui->inputTempo->text().toFloat());
    cadastro.setIluminacao(ui->inputIluminacao->text().toFloat());
    cadastro.setTarifa(ui->inputTarifa->text().toFloat());


  ui->inputEquipamento->clear();

  ui->inputPotencia->clear();

  ui->inputTempo->clear();

  ui->inputIluminacao->clear();

  ui->inputTarifa->clear();

  int quantidade_linhas = ui->tabela->rowCount();
  ui->tabela->insertRow(quantidade_linhas);
  inserirNaTabela(cadastro,quantidade_linhas);

  casa.inserirCadastro(cadastro);
  atualizarEstatisticas();

}

void MainWindow::inserirNaTabela(Equipamento a, int linha){


    ui->tabela->setItem(linha,0,new QTableWidgetItem(a.getEquipamento()));
    ui->tabela->setItem(linha,1,new QTableWidgetItem(QString::number(a.getPotencia())));
    ui->tabela->setItem(linha,2,new QTableWidgetItem(QString::number(a.getTempo())));
    energia.push_back(a.calcularEnergia());
    lista.push_back(a.getEquipamento());
}

void MainWindow::atualizarEstatisticas(){

    ui->MaiorPotencia->setText(QString::number(casa.getMaiorPotencia()));
    ui->MenorPotencia->setText(QString::number(casa.getMenorPotencia()));
    ui->PotenciaMedia->setText(QString::number(casa.getPotenciaMedia()));
}

void MainWindow::on_ButtonOrdenarPorNome_clicked()
{
    casa.ordenarPorNome();
    ui->tabela->clearContents();
    for(int i = 0; i<casa.size();i++){
        inserirNaTabela(casa[i],i);
    }
}

void MainWindow::on_ButtonOrdenarPorPotencia_clicked()
{
    casa.ordenarPorPotencia();
    ui->tabela->clearContents();
    for(int i = 0; i<casa.size();i++){
        inserirNaTabela(casa[i],i);
}
}


void MainWindow::on_ButtonConsumoTotal_clicked()
{
    Equipamento a;
    float b;
    float temp;
    for(int i = 0; i<energia.size();i++){
        temp+=energia[i];
    }
    b = (temp*MES);

 ui->Label_Consumo_total->setText((QString::number(b)));
}

void MainWindow::on_actionSalvar_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");
    casa.salvarDados(filename);
}

void MainWindow::on_actionCarregar_triggered()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");
    casa.carregarDados(filename);

    for(int i=0;i<casa.size();i++){
        ui->tabela->insertRow(i);
        inserirNaTabela(casa[i],i);
    }
    atualizarEstatisticas();
}

void MainWindow::on_ButtonRemover_clicked()
{
       Equipamento a;

    for(int i=0; i<casa.size(); i++){

        // if(ui->inputRemover->text() == lista[i]){

        ui->tabela->removeRow(i);
        inserirNaTabela(casa[i],i);
         atualizarEstatisticas();
}


}


