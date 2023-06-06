#ifndef PERSONAJE2_H
#define PERSONAJE2_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class personaje2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit personaje2(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;

    float ancho;
    float alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Actualizacion();
};
#endif // PERSONAJE2_H
