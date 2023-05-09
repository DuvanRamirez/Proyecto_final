#include "playing_in_dreams.h"
#include "ui_playing_in_dreams.h"

playing_in_dreams::playing_in_dreams(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::playing_in_dreams)
{
    ui->setupUi(this);
}

playing_in_dreams::~playing_in_dreams()
{
    delete ui;
}

