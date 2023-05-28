#ifndef CARRO_H
#define CARRO_H
#include <QGraphicsItem>
#include <QPainter>

class Carro : public QGraphicsItem
{
public:
    Carro();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // CARRO_H
