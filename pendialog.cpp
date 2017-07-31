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

std::pair<QColor, int> PenDialog::getPen(QWidget *parent, int oldVal, QColor oldColor)
{
    PenDialog dialog(parent);
    dialog.ui->spinBox->setValue(oldVal);

    if(oldColor.name() == "#0000ff")//blue
    {
        dialog.ui->radioButton_blue->setChecked(true);
    }
    else if(oldColor.name() == "#00ff00")//green
    {
        dialog.ui->radioButton_green->setChecked(true);
    }
    else if(oldColor.name() == "#ff0000")//red
    {
        dialog.ui->radioButton_red->setChecked(true);
    }
    else
    {
        dialog.ui->radioButton_black->setChecked(true);
    }
    dialog.exec();

    int width = dialog.ui->spinBox->value();
    QColor color = dialog.getColor();
    return std::make_pair(color, width);
}

QColor PenDialog::getColor()
{
    QColor color{ 0, 0, 0 };

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
        color.setRgb(0, 0, 0);
    }

    return color;
}
