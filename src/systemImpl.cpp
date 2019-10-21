#include"systemImpl.hpp"

//SystemImpl::SystemImpl(){}

//SystemBody::~SystemImpl(){}

void SystemBody::add(Stock *s){
    this->vecStock.push_back(s);
}

void SystemBody::add(Flow *f){
    this->vecFlow.push_back(f);
}

void SystemBody::run(int begin, int end){

    int size = this->vecFlow.size();
    float *v = new float[size];

    for(int i = begin ; i < end ; i++){
        for(int j = 0 ; j < size ; j++){
            v[j] = this->vecFlow[j]->equation();
        }

        for( int k = 0 ; k < size ; k++){
            this->vecFlow[k]->getTarget()->setEnergy(this->vecFlow[k]->getTarget()->getEnergy() + v[k]);
            this->vecFlow[k]->getSource()->setEnergy(this->vecFlow[k]->getSource()->getEnergy() - v[k]);
        }
    } 
}

void SystemBody::execute(){
    System *a;
    for(auto i = this->systemContainer.begin(); i != this->systemContainer.end() ; i++){
        *i = a;
        a->run(0,100);
    }
    this->run(0,100);
}
SystemBody* SystemBody::operator=(SystemBody *m){
    if(this == m)
        return this;
    
    this->vecStock = m->vecStock;
    this->vecFlow = m->vecFlow;
    return this;
}

Stock* SystemBody::getVecStock(int position){
    return this->vecStock.at(position);
}

Flow* SystemBody::getVecFlow(int position){
    return this->vecFlow.at(position);
}


Stock* SystemBody::createStock(float energy){
    Stock *s = new StockHandle(energy);
    add(s);
    return s;
}

System* SystemBody::createSystem(){
    System *m = new SystemHandle();
    return m;
}
System* System::createSystem(){
    return SystemBody::createSystem();
}

void SystemBody::remove(Flow *f){
    for(auto itr = this->vecFlow.begin() ; itr != this->vecFlow.end() ; itr++){
        if(*itr == f)
        {
            this->vecFlow.erase(itr);
            break;
        }
    }
}

void SystemBody::remove(Stock *f){
    for(auto itr = this->vecStock.begin() ; itr != this->vecStock.end() ; itr++){
        if(*itr == f)
        {
            this->vecStock.erase(itr);
            break;
        }
    }
}

void SystemBody::addSystemToSystem(System *s){
    this->systemContainer.push_back(s);
}