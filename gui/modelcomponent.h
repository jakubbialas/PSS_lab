#ifndef MODELCOMPONENT_H
#define MODELCOMPONENT_H

#include <QWidget>
#include <map>
#include <vector>
#include <QLineEdit>
#include <QHBoxLayout>
#include <simulation/object/modeldata.h>
#include <iterator>

class ModelComponent : public QWidget
{

public:
    ModelData* getModelData();
    void setModelData( ModelData*) const;
    explicit ModelComponent(QWidget *parent = 0);
    ~ModelComponent();

private:
    char elements[5];
    std::map<char, std::vector<double> > data;
    std::map<char, QLineEdit* > components;
    QHBoxLayout *layout;
};

#endif // MODELCOMPONENT_H
