#ifndef SAVEADJUSTMENTDIALOG_H
#define SAVEADJUSTMENTDIALOG_H

#include <QDialog>

namespace Ui {
    class SaveAdjustmentDialog;
}

class SaveAdjustmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveAdjustmentDialog(QWidget *parent = 0);
    ~SaveAdjustmentDialog();

    std::string getAdjustmentName();

private:
    Ui::SaveAdjustmentDialog *ui;
};

#endif // SAVEADJUSTMENTDIALOG_H
