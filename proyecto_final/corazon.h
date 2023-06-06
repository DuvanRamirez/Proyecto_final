#ifndef CORAZON_H
#define CORAZON_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Corazon : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Corazon(QObject *parent = nullptr);

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
#endif // CORAZON_H
