#ifndef EDITOBJECTDIALOG_H
#define EDITOBJECTDIALOG_H

#include <QDialog>
#include "simulation/object/objectdata.h"
#include <QScrollArea>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
#include <iostream>
#include <vector>
#include <iterator>
#include <QLineEdit>
#include "gui/modelcomponent.h"

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
    void setObjectData(ObjectData*);
    /**
     * @brief Funkcja zwracająca parametry obiektu
     *
     */
    ObjectData getObjectData();

private slots:
    void on_objectBox_valueChanged(int arg1);


    void on_buttonBox_accepted();

private:
    Ui::EditObjectDialog *ui;
    QFrame *frame;
    QGridLayout *layout;
    std::vector<ModelComponent*> mcVector;
};

#endif // EDITOBJECTDIALOG_H
