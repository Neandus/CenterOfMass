#ifndef PENDIALOG_H
#define PENDIALOG_H

#include <QDialog>

namespace Ui {
class PenDialog;
}

class PenDialog : public QDialog
{
    Q_OBJECT

public:

    static std::pair<QColor, int> getPen(QWidget *parent, int oldVal, QColor oldColor);

private:

    explicit PenDialog(QWidget *parent = 0);
    ~PenDialog();
    QColor getColor();

    Ui::PenDialog *ui;
};

#endif // PENDIALOG_H
