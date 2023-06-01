#include "pantalla.h"
#include "ui_pantalla.h"
#include <QImage>
#include <QDebug>
#include "personaje.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QLabel>
#include <QTimer>
#include <QTime>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;
    //nivel 1
    if(nivel==1){
    this->setGeometry(450,20,402,4832);
    scene=new QGraphicsScene(450,20,402,4832);
    ui->graphicsView->setScene(scene);


    puntuacion = 0;

    ui->graphicsView->setFixedSize(402,4832);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Nivel1.png")));

    tiempo=new QTimer();

    connect(tiempo,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));
    connect(this,SIGNAL(aviso2(int)),this,SLOT(muerte()));

    tiempo->start(31);

    //personaje
    boy = new personaje;
    scene->addItem(boy);
    boy->setPos(126, 100);
    boyPosX = boy->x();
    boyPosY = boy->y();

    //carro
    carro = new Carro();
    scene->addItem(carro);
    carro->setPos(273,-5000);



    //bloques
    bloque = new Bloque();
    scene->addItem(bloque);
    bloque->setPos(273,-500);
    bloque2 = new Bloque();
    scene->addItem(bloque2);
    bloque2->setPos(193,-800);
    bloque3 = new Bloque();
    scene->addItem(bloque3);
    bloque3->setPos(193,-1500);
    bloque4 = new Bloque();
    scene->addItem(bloque4);
    bloque4->setPos(273,-3500);
    bloque5 = new Bloque();
    scene->addItem(bloque5);
    bloque5->setPos(193,-3800);
    bloque6 = new Bloque();
    scene->addItem(bloque6);
    bloque6->setPos(115,-4500);
    bloque7 = new Bloque();
    scene->addItem(bloque7);
    bloque7->setPos(279,3507);
    bloque8 = new Bloque();
    scene->addItem(bloque8);
    bloque8->setPos(195,3507);
    bloquefinal = new Bloquefinal();
    scene->addItem(bloquefinal);
    //bloque final
    bloquefinal->setPos(195,6000);

    //cajas
    caja = new Caja();
    scene->addItem(caja);
    caja->setPos(273,2500);
    caja2 = new Caja();
    scene->addItem(caja2);
    caja2->setPos(193,2800);
    caja3 = new Caja();
    scene->addItem(caja3);
    caja3->setPos(193,3500);


    //puntos
    punto = new puntos();
    scene->addItem(punto);
    punto->setPos(281,657);
    punto2 = new puntos();
    scene->addItem(punto2);
    punto2->setPos(185,1185);
    punto3 = new puntos();
    scene->addItem(punto3);
    punto3->setPos(113,1945);
    punto4 = new puntos();
    scene->addItem(punto4);
    punto4->setPos(273,2497);
    punto5 = new puntos();
    scene->addItem(punto5);
    punto5->setPos(197,2905);
    punto6 = new puntos();
    scene->addItem(punto6);
    punto6->setPos(233,3489);
    punto7 = new puntos();
    scene->addItem(punto7);
    punto7->setPos(129,4249);
    punto8 = new puntos();
    scene->addItem(punto8);
    punto8->setPos(225,4553);
    }
    //nivel 2
    else if(nivel==2){

    scene=new QGraphicsScene(0,0,8018,297);
    ui->graphicsView->setScene(scene);


    puntuacion = 0;

    ui->graphicsView->setFixedSize(8018,297);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Nivel2.png")));

    tiempo=new QTimer();

    connect(tiempo,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));
    connect(this,SIGNAL(aviso2(int)),this,SLOT(muerte()));

    tiempo->start(31);

    //personaje
    boy = new personaje;
    scene->addItem(boy);
    boy->setPos(69, 190);

    }

}


MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
void MainWindow::animar()
{
    //nivel 1
    if(nivel==1){
    QImage image(":/Imagenes/Nivel1rojo.png");
    //animacion movimiento del mundo
    if(exit==1)vmundo+=8;
    ui->graphicsView->setSceneRect(QRect(0,vmundo, ui->graphicsView->width(), ui->graphicsView->height()));

    //colision con los tubos
    QRgb pixelValueY = image.pixel(boyPosX, boyPosY+30);
    QRgb pixelValueX = image.pixel(boyPosX-30, boyPosY+15);
    QRgb pixelValueX2 = image.pixel(boyPosX+25, boyPosY+20);
    int r, g, b;
    int r2, g2, b2;
    int r3, g3, b3;
    QColor color(pixelValueY);
    QColor color2(pixelValueX);
    QColor color3(pixelValueX2);
    color.getRgb(&r, &g, &b);
    color2.getRgb(&r2, &g2, &b2);
    color3.getRgb(&r3, &g3, &b3);

    if(r==255 && g==255 && b==255 && r2==255 && g2==255 && b2==255 & r3==255 && g3==255 && b3==255){
        boy->setPos(boy->x(),boy->y()+8);//movimiento del personaje
        boyPosY+=8;
    }
    else emit aviso2(9);


    bloque->setPos(bloque->x(),bloque->y()+16);
    bloque2->setPos(bloque2->x(),bloque2->y()+16);
    bloque3->setPos(bloque3->x(),bloque3->y()+16);
    bloque4->setPos(bloque4->x(),bloque4->y()+16);
    bloque5->setPos(bloque5->x(),bloque5->y()+16);
    bloque6->setPos(bloque6->x(),bloque6->y()+16);
    caja->setPos(caja->x(),caja->y()-2);
    caja2->setPos(caja2->x(),caja2->y()-2);
    caja3->setPos(caja3->x(),caja3->y()-2);
    carro->setPos(carro->x(),carro->y()+16);
    //
    int z=30;//distancia centro objeto al bordo objeto

    if(moverIx1){
        QRgb pixelValueX = image.pixel(boyPosX-z, boyPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r==255 && g==255 && b==255 ){
            boy->setPos(boy->x()-6,boy->y());
            boyPosX-=6;
        }

    }
    if(moverDx1){
        QRgb pixelValueX = image.pixel(boyPosX+z, boyPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r==255 && g==255 && b==255 ){
            boy->setPos(boy->x()+6,boy->y());
            boyPosX+=6;
        }

    }


    //colision con bloques
    if(boy->collidesWithItem(bloque))emit aviso2(9);

    if(boy->collidesWithItem(bloque2))emit aviso2(9);

    if(boy->collidesWithItem(bloque3))emit aviso2(9);

    if(boy->collidesWithItem(bloque4))emit aviso2(9);

    if(boy->collidesWithItem(bloque5))emit aviso2(9);

    if(boy->collidesWithItem(bloque6))emit aviso2(9);

    if(boy->collidesWithItem(bloque7))emit aviso2(9);

    if(boy->collidesWithItem(bloque8))emit aviso2(9);

    //colision con bloquefinal
    if(boy->collidesWithItem(bloquefinal))emit aviso2(9);

    //colision con cajas
    if(boy->collidesWithItem(caja)) emit aviso2(9);

    if(boy->collidesWithItem(caja2)) emit aviso2(9);

    if(boy->collidesWithItem(caja3)) emit aviso2(9);

    //colision carro
    if(boy->collidesWithItem(carro))emit aviso2(9);

    //colision con puntos
    if(boy->collidesWithItem(punto))
    {
        if(punto->isVisible()){
            punto->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto2))
    {
        if(punto2->isVisible()){
            punto2->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto3))
    {
        if(punto3->isVisible()){
            punto3->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto4))
    {
        if(punto4->isVisible()){
            punto4->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto5))
    {
        if(punto5->isVisible()){
            punto5->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto6))
    {
        if(punto6->isVisible()){
            punto6->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto7))
    {
        if(punto7->isVisible()){
            punto7->hide();
            emit aviso(9);
        }
    }
    if(boy->collidesWithItem(punto8))
    {
        if(punto8->isVisible()){
            punto8->hide();
            emit aviso(9);
        }
    }
    }
    //nivel 2
    else if(nivel==2){
    QImage image(":/Imagenes/Nivel2rojo.png");
    //animacion movimiento del mundo
    if(exit==1)vmundo+=8;

    ui->graphicsView->setSceneRect(QRect(vmundo,0, ui->graphicsView->width(), ui->graphicsView->height()));

    QRgb pixelValueX = image.pixel(boyPosX+30, boyPosY);
    int r, g, b;
    QColor color(pixelValueX);
    color.getRgb(&r, &g, &b);

    if(r!=255 && g!=0 && b!=0 ){
        boy->setPos(boy->x()+6,boy->y());
        boyPosX+=6;
    }
    else if(r==255 && g==0 && b==0){ boy->setPos(boy->x(),boy->y());}

    //
    int z=30;//distancia centro objeto al bordo objeto
    if(moverIx1){
        QRgb pixelValueX = image.pixel(boyPosX-z, boyPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r!=0 && g!=0 && b!=0 ){
            boy->setPos(boy->x()-6,boy->y());
            boyPosX-=6;
        }

    }
    if(moverDx1){
        QRgb pixelValueX = image.pixel(boyPosX+z, boyPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r!=0 && g!=0 && b!=0 ){
            boy->setPos(boy->x()+6,boy->y());
            boyPosX+=6;
        }

    }
    /*if(moverUy1){
        QRgb pixelValueX = image.pixel(boyPosX+z, boyPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r!=0 && g!=0 && b!=0 ){
            boy->setPos(boy->x(),boy->y()-6);
            boyPosY+=6;
        }

    }*/


    }




}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=false;
    }

}

void MainWindow::aumentarPunt()
{
    puntuacion += 1;
    ui->lcdNumber->display(puntuacion);
}
void MainWindow::muerte()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/gameover.jpg")));
    exit=0;
    nivel=0;
}




