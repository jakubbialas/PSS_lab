#ifndef EDITCUSTOMSOURCEDIALOG_H
#define EDITCUSTOMSOURCEDIALOG_H

#include <QDialog>
#include "simulation/source/multisourcedata.h"

namespace Ui {
    class EditCustomSourceDialog;
}

/**
 * @brief Okno dialogowe do edycji zdefiniowanych źródeł
 *
 */
class EditCustomSourceDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     *
     * @param parent
     */
    explicit EditCustomSourceDialog(QWidget *parent = 0);
    /**
     * @brief Destruktor
     *
     */
    ~EditCustomSourceDialog();

    /**
     * @brief Funkcja ustawia bierzące dane modyfikowanego źródła
     *
     * @param MultiSourceData
     */
    void setCustomSourceData(MultiSourceData);
    /**
     * @brief funkcja zwraca dane źródła
     *
     */
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
