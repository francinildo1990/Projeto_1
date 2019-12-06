#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include "equipamento.h"
#include "grupo_equipamento.h"
#include <QFileDialog>
#include<QString>
#include<QVector>
#include<QMap>
#include <algorithm>
#include <QFile>
#include <QStringList>
#include<QMessageBox>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonCadastrarEquipamento_clicked();

    void on_ButtonOrdenarPorNome_clicked();

    void on_ButtonOrdenarPorPotencia_clicked();

    void on_ButtonConsumoTotal_clicked();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_ButtonRemover_clicked();



    void on_tabela_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    Grupo_Equipamento casa;
    void atualizarEstatisticas();
    void inserirNaTabela(Equipamento a, int linha);
    float calcularEnergia();
    void removeRow(int row);
     QMap <QString,QString> lista;
     QVector<float> energia;
     Equipamento cadastro;
};
#endif // MAINWINDOW_H
