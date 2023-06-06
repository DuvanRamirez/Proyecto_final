#include "pantalla.h"
#include "ui_pantalla.h"
#include <QImage>
#include <QDebug>
#include "personaje.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPainter>
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
    //menu
    if(nivel==0){
        this->setGeometry(0,0,764,434);
        scene=new QGraphicsScene(0,0,764,434);
        ui->graphicsView->setScene(scene);

        ui->graphicsView->setFixedSize(764,434);
        ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Menu.png")));
        tiempo=new QTimer();

        connect(tiempo,SIGNAL(timeout()),this,SLOT(animar()));
        connect(this,SIGNAL(aviso3(int)),this,SLOT(seleccion()));


        tiempo->start(30);

        //botones
        boton1 = new Botones;
        scene->addItem(boton1);
        boton1->setPos(121, 233);
        boton2 = new Botones;
        scene->addItem(boton2);
        boton2->setPos(511, 233);
        //personaje
        boy2 = new personaje2;
        scene->addItem(boy2);
        boy2->setPos(378, 220);



    }
    //nivel 1
    else if(nivel==1){
    this->setGeometry(450,20,398,5548);
    scene=new QGraphicsScene(450,20,398,5548);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setFixedSize(398,5548);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Nivel1.png")));

    tiempo=new QTimer();
    Temporizador=new QTimer();
    Temporizador2=new QTimer();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(reducciontime()));
    connect(this,SIGNAL(aviso2(int)),this,SLOT(muerte()));
    connect(Temporizador,SIGNAL(timeout()),this,SLOT(temporizador()));
    connect(Temporizador2,SIGNAL(timeout()),this,SLOT(temporizador2()));

    tiempo->start(30);
    Temporizador->start(1000);
    Temporizador2->start(1000);

    //personaje
    boy = new personaje;
    scene->addItem(boy);
    boy->setPos(106, 250);
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
    punto4->setPos(104,5550);
    punto5 = new puntos();
    scene->addItem(punto5);
    punto5->setPos(197,2905);
    punto6 = new puntos();
    scene->addItem(punto6);
    punto6->setPos(162,3717);
    punto7 = new puntos();
    scene->addItem(punto7);
    punto7->setPos(129,4249);
    punto8 = new puntos();
    scene->addItem(punto8);
    punto8->setPos(104,4553);
    //bloque menu
    bloquemenu = new Bloquemenu();
    scene->addItem(bloquemenu);
    bloquemenu->setPos(195,22);
    //corazon
    corazon = new Corazon();
    scene->addItem(corazon);
    corazon->setPos(85,35);


    }
    //nivel 2
    else if(nivel==2){
    this->setGeometry(0,0,1000,327);
    scene=new QGraphicsScene(0,0,7091,327);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setFixedSize(1000,327);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Nivel2.png")));
    tiempo=new QTimer();
    Temporizador=new QTimer();
    Temporizador2=new QTimer();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(reducciontime()));
    connect(this,SIGNAL(aviso2(int)),this,SLOT(muerte()));
    connect(Temporizador,SIGNAL(timeout()),this,SLOT(temporizador()));
    connect(Temporizador2,SIGNAL(timeout()),this,SLOT(temporizador2()));

    tiempo->start(30);
    Temporizador->start(1000);
    Temporizador2->start(1000);

    //personaje
    boy2 = new personaje2;
    scene->addItem(boy2);
    boy2->setPos(400, 250);
    boyPosX = boy2->x();
    boyPosY = boy2->y();
    //fantasma
    fantasma = new Fantasma;
    scene->addItem(fantasma);
    fantasma->setPos(90, 235);
    //bloque menu
    bloquemenu = new Bloquemenu();
    scene->addItem(bloquemenu);
    bloquemenu->setPos(195,29);
    //corazon
    corazon = new Corazon();
    scene->addItem(corazon);
    corazon->setPos(85,39);
    //puntos
    punto = new puntos();
    scene->addItem(punto);
    punto->setPos(961,232);
    punto2 = new puntos();
    scene->addItem(punto2);
    punto2->setPos(1527,232);
    punto3 = new puntos();
    scene->addItem(punto3);
    punto3->setPos(2403,244);
    punto4 = new puntos();
    scene->addItem(punto4);
    punto4->setPos(3033,248);
    punto5 = new puntos();
    scene->addItem(punto5);
    punto5->setPos(3726,263);
    punto6 = new puntos();
    scene->addItem(punto6);
    punto6->setPos(4604,260);
    punto7 = new puntos();
    scene->addItem(punto7);
    punto7->setPos(5340,203);
    punto8 = new puntos();
    scene->addItem(punto8);
    punto8->setPos(6016,230);
    //bloques
    bloque = new Bloque();
    scene->addItem(bloque);
    bloque->setPos(3726,275);
    bloque2 = new Bloque();
    scene->addItem(bloque2);
    bloque2->setPos(7000,275);
    bloque3 = new Bloque();
    scene->addItem(bloque3);
    bloque3->setPos(15000,275);
    bloque4 = new Bloque();
    scene->addItem(bloque4);
    bloque4->setPos(13000,275);
    //cajas
    caja = new Caja();
    scene->addItem(caja);
    caja->setPos(2815,-30);
    caja2 = new Caja();
    scene->addItem(caja2);
    caja2->setPos(3133,-60);
    caja3 = new Caja();
    scene->addItem(caja3);
    caja3->setPos(3262,-100);

    }

}


MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
void MainWindow::animar()
{
    //menu
    if(nivel==0){

    if(moverDx1){
            boy2->setPos(boy2->x()+5,boy2->y());
            boyPosX+=5;
    }
    if(moverIx1){
            boy2->setPos(boy2->x()-5,boy2->y());
            boyPosX-=5;

    }
    if(boy2->collidesWithItem(boton1))emit aviso3(9);

    else if(boy2->collidesWithItem(boton2))emit aviso3(9);

    }
    //nivel 1
    else if(nivel==1){
    QImage image(":/Imagenes/Nivel1rojo.png");
    //animacion movimiento del mundo
    if(exit==1)vmundo+=8;
    ui->graphicsView->setSceneRect(QRect(0,vmundo, ui->graphicsView->width(), ui->graphicsView->height()));
    bloquemenu->setPos(bloquemenu->x(),bloquemenu->y()+8);
    corazon->setPos(corazon->x(),corazon->y()+8);
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

    if((r==255 && g==255 && b==255) && (r2==255 && g2==255 && b2==255) && (r3==255 && g3==255 && b3==255)){
        boy->setPos(boy->x(),boy->y()+8);//movimiento del personaje
        boyPosY+=8;
    }
    else if ((r==0 && g==0 && b==0) || (r2==0 && g2==0 && b2==0) || (r3==0 && g3==0 && b3==0))emit aviso2(9);

    //marcador de puntuacion



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
    if(exit==1)vmundo+=7;

    ui->graphicsView->setSceneRect(QRect(vmundo,0, ui->graphicsView->width(), ui->graphicsView->height()));
    bloquemenu->setPos(bloquemenu->x()+7,bloquemenu->y());
    corazon->setPos(corazon->x()+7,corazon->y());
    fantasma->setPos(fantasma->x()+7,fantasma->y());
    bloque->setPos(bloque->x()-16,bloque->y());
    bloque2->setPos(bloque2->x()-16,bloque2->y());
    bloque3->setPos(bloque3->x()-16,bloque3->y());
    bloque4->setPos(bloque4->x()-16,bloque4->y());

    if(Ntemporizador3<20){
        caja->setPos(caja->x(),caja->y()+5);
        caja2->setPos(caja2->x(),caja2->y()+5);
        caja3->setPos(caja3->x(),caja3->y()+5);
    }
    QRgb pixelValueY = image.pixel(boyPosX, boyPosY+25);
    int r, g, b;

    QColor color(pixelValueY);
    color.getRgb(&r, &g, &b);
    if(r==255 && g==255 && b==255){
        boy2->setPos(boy2->x()+7,boy2->y());
        boyPosX+=7;
    }

    else if((r==0 && g==0 && b==0))emit aviso2(9);


    if(moverDx1){
        QRgb pixelValueY = image.pixel(boyPosX, boyPosY+25);
        int r, g, b;

        QColor color(pixelValueY);
        color.getRgb(&r, &g, &b);
        if(r==255 && g==255 && b==255){
            boy2->setPos(boy2->x()+5,boy2->y());
            boyPosX+=5;
        }

        else if((r==0 && g==0 && b==0))emit aviso2(9);
    }
    if(moverIx1){
        QRgb pixelValueY = image.pixel(boyPosX, boyPosY+25);
        int r, g, b;

        QColor color(pixelValueY);
        color.getRgb(&r, &g, &b);
        if(r==255 && g==255 && b==255){
            boy2->setPos(boy2->x()-5,boy2->y());
            boyPosX-=5;
        }

        else if((r==0 && g==0 && b==0))emit aviso2(9);
    }

    //colision con fantasma
    if(boy2->collidesWithItem(fantasma))emit aviso2(9);

    //colision con bloques
    if(boy2->collidesWithItem(bloque))emit aviso2(9);

    if(boy2->collidesWithItem(bloque2))emit aviso2(9);

    if(boy2->collidesWithItem(bloque3))emit aviso2(9);

    if(boy2->collidesWithItem(bloque4))emit aviso2(9);
    //colision con cajas
    if(boy2->collidesWithItem(caja)) emit aviso2(9);

    if(boy2->collidesWithItem(caja2)) emit aviso2(9);

    if(boy2->collidesWithItem(caja3)) emit aviso2(9);

    //colision con puntos
    if(boy2->collidesWithItem(punto))
    {
        if(punto->isVisible()){
            punto->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto2))
    {
        if(punto2->isVisible()){
            punto2->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto3))
    {
        if(punto3->isVisible()){
            punto3->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto4))
    {
        if(punto4->isVisible()){
            punto4->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto5))
    {
        if(punto5->isVisible()){
            punto5->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto6))
    {
        if(punto6->isVisible()){
            punto6->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto7))
    {
        if(punto7->isVisible()){
            punto7->hide();
            emit aviso(9);
        }
    }
    if(boy2->collidesWithItem(punto8))
    {
        if(punto8->isVisible()){
            punto8->hide();
            emit aviso(9);
        }
    }

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

    else if (ev->key() == Qt::Key_Space)
    {
        if(nivel==2){
            boy2->setPos(boy2->x(),boy2->y()-40);
            boyPosY-=40;
        }
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
    else if (ev->key() == Qt::Key_Space)
    {
        if(nivel==2){
            boy2->setPos(boy2->x(),boy2->y()+40);
            boyPosY+=40;
        }
    }

}


void MainWindow::reducciontime()
{
    Ntemporizador2=5;
    puntosparaganar++;
    ui->contadorpuntos->display(puntosparaganar);
    if(nivel==1){
        if(puntosparaganar==6){
            ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/win.png")));
            exit=0;
            nivel=0;
        }
    }
    if(nivel==2){
        if(puntosparaganar==8){
            ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/win.png")));
            exit=0;
            nivel=0;
        }
    }
}

void MainWindow::muerte()
{
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/gameover.jpg")));
    if(nivel==1){if(boy->isVisible())boy->hide();}
    else if(nivel==2){if(boy2->isVisible())boy2->hide();}
    exit=0;
    nivel=0;
}
void MainWindow::seleccion(){
    nivel=1;
}
void MainWindow::temporizador(){
    if(nivel==1){
        ui->temporizador->display(Ntemporizador);
        if(Ntemporizador>0 && nivel!=0)Ntemporizador--;
        else if(Ntemporizador==0){
            Ntemporizador=0;
            ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/gameover.jpg")));
            exit=0;
            nivel=0;
        }
    }
    else if(nivel==2){
        ui->temporizador->display(Ntemporizador3);
        if(Ntemporizador3>0 && nivel!=0)Ntemporizador3--;
        else if(Ntemporizador3==0){
            Ntemporizador3=0;
            ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/gameover.jpg")));
            exit=0;
            nivel=0;
        }
    }
}
void MainWindow::temporizador2(){
    ui->temporizador2->display(Ntemporizador2);
    if(Ntemporizador2>0 && nivel!=0)Ntemporizador2--;
    else if(Ntemporizador2==0){
        Ntemporizador2=0;
        ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/gameover.jpg")));
        exit=0;
        nivel=0;
    }
}


