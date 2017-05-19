#include "pendialog.h"
#include "ui_pendialog.h"

PenDialog::PenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PenDialog)
{
    ui->setupUi(this);
}

PenDialog::~PenDialog()
{
    delete ui;
}

std::pair<QColor, int> PenDialog::getPen(QWidget *parent)
{
    PenDialog dialog(parent);
    dialog.exec();

    int width = dialog.ui->spinBox->value();
    QColor color = dialog.getColor();
    return std::make_pair(color, width);
}

QColor PenDialog::getColor()
{
    QColor color{ 255, 255 ,255 };

    if(ui->radioButton_blue->isChecked())
    {
        color.setRgb(0, 0 ,255);
    }
    else if(ui->radioButton_green->isChecked())
    {
        color.setRgb(0, 255 ,0);
    }
    else if(ui->radioButton_red->isChecked())
    {
        color.setRgb(255, 0 ,0);
    }
    else
    {
        color.setRgb(255, 255 ,255);
    }

    return color;
}
