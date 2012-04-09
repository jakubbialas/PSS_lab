#ifndef EDITOBJECTDIALOG_H
#define EDITOBJECTDIALOG_H

#include <QDialog>
#include "simulation/object/objectdata.h"

namespace Ui {
    class EditObjectDialog;
}

class EditObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditObjectDialog(QWidget *parent = 0);
    ~EditObjectDialog();

    void setObjectData(ObjectData);
    ObjectData getObjectData();

private:
    Ui::EditObjectDialog *ui;
};

#endif // EDITOBJECTDIALOG_H
