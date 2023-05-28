#ifndef CAJA_H
#define CAJA_H
#include <QGraphicsItem>
#include <QPainter>

class Caja : public QGraphicsItem
{
public:
    Caja();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // CAJA_H
