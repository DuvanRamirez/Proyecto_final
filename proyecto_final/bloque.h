#ifndef BLOQUE_H
#define BLOQUE_H
#include <QGraphicsItem>
#include <QPainter>

class Bloque : public QGraphicsItem
{
public:
    Bloque();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLOQUE_H
