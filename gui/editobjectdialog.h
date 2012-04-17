#ifndef EDITOBJECTDIALOG_H
#define EDITOBJECTDIALOG_H

#include <QDialog>
#include "simulation/object/objectdata.h"

namespace Ui {
    class EditObjectDialog;
}

/**
 * @brief Okno dialogowe umiżliwiające edycję zapisanego obiektu
 *
 */
class EditObjectDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     *
     * @param parent
     */
    explicit EditObjectDialog(QWidget *parent = 0);
    /**
     * @brief Destruktor
     *
     */
    ~EditObjectDialog();

    /**
     * @brief Funkcja pozwalająca na ustawienie bierzących parametrów obiektu w oknie
     *
     * @param ObjectData
     */
    void setObjectData(ObjectData);
    /**
     * @brief Funkcja zwracająca parametry obiektu
     *
     */
    ObjectData getObjectData();

private:
    Ui::EditObjectDialog *ui;
};

#endif // EDITOBJECTDIALOG_H
