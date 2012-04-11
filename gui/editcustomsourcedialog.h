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

private slots:

    void on_pushButton_addSource_clicked();

    void on_pushButton_removeSource_clicked();

    void on_comboBox_source_currentIndexChanged(const QString &arg1);

private:
    Ui::EditCustomSourceDialog *ui;

    std::vector<SourceData> sources;

    void updateSourceList();
};

#endif // EDITCUSTOMSOURCEDIALOG_H
