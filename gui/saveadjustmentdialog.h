#ifndef SAVEADJUSTMENTDIALOG_H
#define SAVEADJUSTMENTDIALOG_H

#include <QDialog>

namespace Ui {
    class SaveAdjustmentDialog;
}

/**
 * @brief Okno dialogowe z zapytaniam o nazwe zapisywanej nastawy
 *
 */
class SaveAdjustmentDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor okna
     *
     * @param parent
     */
    explicit SaveAdjustmentDialog(QWidget *parent = 0);
    /**
     * @brief Destruktor
     *
     */
    ~SaveAdjustmentDialog();

    /**
     * @brief Funkcja zwraca podaną nazwę nastawy
     *
     */
    std::string getAdjustmentName();

private:
    Ui::SaveAdjustmentDialog *ui; /**< ui */
};

#endif // SAVEADJUSTMENTDIALOG_H
