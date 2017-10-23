#ifndef MAGIC_SQURES_H
#define MAGIC_SQURES_H
#include "square.h"

#include <QMainWindow>

namespace Ui {
class Magic_Squres;
}

class Magic_Squres : public QMainWindow
{
    Q_OBJECT

public:
    explicit Magic_Squres(QWidget *parent = 0);
    ~Magic_Squres();

private slots:
    void on_Generation_clicked();

private:
    Ui::Magic_Squres *ui;

    square Squares;
};

#endif // MAGIC_SQURES_H
