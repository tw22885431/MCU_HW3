#include "magic_squres.h"
#include "ui_magic_squres.h"
#include <QMessageBox>

using namespace std;

Magic_Squres::Magic_Squres(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Magic_Squres)
{
    ui->setupUi(this);

    ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

    ui->tableView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);

    ui->tableView->setModel(&Squares);
}

Magic_Squres::~Magic_Squres()
{
    delete ui;
}

void Magic_Squres::on_Generation_clicked()
{

    int Input;

    bool InputOK;

    Input  = ui-> Square -> text().toInt(&InputOK);

    if (!InputOK){

        QMessageBox :: warning(this, "Input Error","No Available Value, Please to check the Input when you enter it.");

        return;

    }

    if (Input < 3){

        QMessageBox :: warning(this, "Input Error ", "Input Number must be bigger than 3");

        return;

    }

    if (Input % 2 == 0){

        QMessageBox :: warning(this ,"Input Error", "Input Number must be a odd number");

        return;

    }

    square::Direction direction = square::Direction::Default;

    if (ui->Left_To_Up->isChecked())

        direction = square::Direction::Left_To_Up;

    if (ui->Left_To_Down->isChecked())

        direction = square::Direction::Left_To_Down;

    if (ui->Right_To_Up->isChecked())

        direction = square::Direction::Right_To_Up;

    if(ui->Right_To_Down->isChecked())

        direction = square::Direction::Right_To_Down;

    Squares.resize(Input,direction);

}
