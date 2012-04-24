#include "modelcomponent.h"


ModelComponent::ModelComponent(QWidget *parent): QWidget(parent){
    layout = new QHBoxLayout(this);
    std::vector<char> elements;

    elements.push_back('t'); elements.push_back('B');  elements.push_back('A');  elements.push_back('k');


    for(std::vector<char>::iterator i = elements.begin(); i != elements.end(); i++){
        QLineEdit *edit = new QLineEdit();
        components[(*i)] = edit;
        layout->addWidget(edit);
    }

}

ModelData* ModelComponent::getModelData(){
    ModelData *md = new ModelData();
    std::map<char,std::vector<QString>* > numbers;

    for(std::map<char, QLineEdit*>::iterator i = components.begin(); i != components.end(); i++){

        QString txt = i->second->text();
        int count = 0;

        std::vector<QString> *vecString = new std::vector<QString>();
        vecString->push_back("");
        numbers[i->first] = vecString;

        QString::iterator j = txt.begin();

        for(QString::iterator j = txt.begin(); j != txt.end(); j++){

            if(((*j) >= '0' && (*j) <= '9') || (*j) == ',' || (*j) == '.' || (*j)=='-'){ //ten warunek mozna poprawic(chodzi o wystapienie dwoch kropek albo minusow
                vecString->at(count).push_back( (*j));
            }else if((*j) == 32){
                    count++;
                    vecString->push_back("");
            }else{
                break;
                //TODO throw execption
            }
        }

        if(vecString->back() == "" ){
            vecString->pop_back();
        }
    }

    std::vector<QString>* A = numbers.at('A');
    std::vector<double> Adouble;

    for(std::vector<QString>::iterator i = A->begin(); i != A->end(); i++){
        Adouble.push_back((*i).toDouble());
    }
    md->setA(Adouble);

    std::vector<QString>* B = numbers.at('B');
    std::vector<double> Bdouble;
    for(std::vector<QString>::iterator i = B->begin(); i != B->end(); i++){
        Bdouble.push_back((*i).toDouble());
    }
    md->setB(Bdouble);

    std::vector<QString>* k = numbers.at('k');
    md->setK(k->at(0).toDouble());

    std::vector<QString>* t = numbers.at('t');
    md->setT(t->at(0).toDouble());

    return md;
}

void ModelComponent::setModelData( ModelData* md) const{
    std::vector<double> A = md->getA();
    QString no;

    for(std::vector<double>::iterator i = A.begin(); i !=A.end(); i++){

        components.at('A')->setText(components.at('A')->text()+no.setNum(*i) + " ");
    }

    std::vector<double> B = md->getB();
    for(std::vector<double>::iterator i = B.begin(); i !=B.end(); i++){
        components.at('B')->setText(components.at('B')->text()+ no.setNum(*i) + " ");
    }

    components.at('k')->setText( no.setNum(md->getK()));
    components.at('t')->setText( no.setNum(md->getT()));

}

ModelComponent::~ModelComponent(){

}

