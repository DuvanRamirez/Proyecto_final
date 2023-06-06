#ifndef BLOQUEMENU_H
#define BLOQUEMENU_H
#include <QGraphicsItem>
#include <QPainter>

class Bloquemenu : public QGraphicsItem
{
public:
    Bloquemenu();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLOQUE_H
