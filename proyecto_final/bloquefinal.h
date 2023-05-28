#ifndef BLOQUEFINAL_H
#define BLOQUEFINAL_H
#include <QGraphicsItem>
#include <QPainter>

class Bloquefinal : public QGraphicsItem
{
public:
    Bloquefinal();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLOQUE_H
