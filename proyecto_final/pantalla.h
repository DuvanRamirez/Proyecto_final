#ifndef PANTALLA_H
#define PANTALLA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "puntos.h"
#include "personaje.h"
#include "bloque.h"
#include "bloquefinal.h"
#include "tubo.h"
#include "caja.h"
#include "carro.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsView>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);
    void aviso2(int);

public slots:
    void animar();
    void aumentarPunt();
    void muerte();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    personaje* boy;
    tubo* Tubo;
    tubo* Tubo2;
    tubo* Tubo3;
    tubo* Tubo4;
    tubo* Tubo5;
    tubo* Tubo6;
    tubo* Tubo7;
    tubo* Tubo8;
    Bloque* bloque;
    Bloque* bloque2;
    Bloque* bloque3;
    Bloque* bloque4;
    Bloque* bloque5;
    Bloque* bloque6;
    Bloque* bloque7;
    Bloque* bloque8;
    Bloquefinal* bloquefinal;
    Caja* caja;
    Caja* caja2;
    Caja* caja3;
    Caja* caja4;
    Caja* caja5;
    Caja* caja6;
    Carro* carro;
    puntos* punto;
    puntos* punto2;
    puntos* punto3;
    puntos* punto4;
    puntos* punto5;
    puntos* punto6;
    puntos* punto7;
    puntos* punto8;
    puntos* punto9;
    qreal boyPosX;
    qreal boyPosY;
    QTimer *tiempo;

    int puntuacion;
    int vmundo=8;
    int exit=1;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

};

#endif // PANTALLA_H
