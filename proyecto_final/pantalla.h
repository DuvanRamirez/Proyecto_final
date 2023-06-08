#ifndef PANTALLA_H
#define PANTALLA_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "puntos.h"
#include "personaje.h"
#include "personaje2.h"
#include "fantasma.h"
#include "bloque.h"
#include "bloquemenu.h"
#include "caja.h"
#include "carro.h"
#include "corazon.h"
#include "botones.h"
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
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

signals:
    void aviso(int);
    void aviso2(int);
    void aviso3(int);

public slots:
    void caidadelsalto();
    void animar();
    void reducciontime();
    void muerte();
    void seleccion();
    void seleccion2();
    void temporizador();
    void temporizador2();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    personaje* boy;
    personaje2* boy2;
    Fantasma* fantasma;

    Botones* boton1;
    Botones* boton2;

    Bloque* bloque;
    Bloque* bloque2;
    Bloque* bloque3;
    Bloque* bloque4;
    Bloque* bloque5;
    Bloque* bloque6;
    Bloque* bloque7;
    Bloque* bloque8;
    Bloquemenu* bloquemenu;
    Corazon* corazon;
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
    QTimer *Temporizador;
    QTimer *Temporizador2;
    QTimer* Timertecla;

    int marcador1=1;
    int vmundo=8;
    int exit=1;
    int nivel=0;
    int puntosparaganar=0;
    int Ntemporizador=25;
    int Ntemporizador2=5;
    int Ntemporizador3=30;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;
    bool moverXY;


    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

};

#endif // PANTALLA_H
