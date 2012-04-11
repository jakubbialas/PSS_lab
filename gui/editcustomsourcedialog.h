#ifndef EDITCUSTOMSOURCEDIALOG_H
#define EDITCUSTOMSOURCEDIALOG_H

#include <QDialog>
#include "simulation/source/multisourcedata.h"

namespace Ui {
    class EditCustomSourceDialog;
}

class EditCustomSourceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomSourceDialog(QWidget *parent = 0);
    ~EditCustomSourceDialog();

    void setCustomSourceData(MultiSourceData);
    MultiSourceData getCustomSourceData();

private:
    Ui::EditCustomSourceDialog *ui;
};

#endif // EDITCUSTOMSOURCEDIALOG_H
