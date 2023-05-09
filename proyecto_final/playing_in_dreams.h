#ifndef PLAYING_IN_DREAMS_H
#define PLAYING_IN_DREAMS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class playing_in_dreams; }
QT_END_NAMESPACE

class playing_in_dreams : public QMainWindow
{
    Q_OBJECT

public:
    playing_in_dreams(QWidget *parent = nullptr);
    ~playing_in_dreams();

private:
    Ui::playing_in_dreams *ui;
};
#endif // PLAYING_IN_DREAMS_H
