#include "flowImpl.hpp"

FlowBody::FlowBody(){
    this->target = NULL;
    this->source = NULL;
    this->value = 0;
}

FlowBody::~FlowBody(){}

bool FlowBody::isConnected(){
    if(this->target != NULL && this->source != NULL)
        return true;
    return false;
}

void FlowBody::setSource(Stock* s) {
    this->source = s;
}

Stock* FlowBody::getSource(){
    return this->source;
}

void FlowBody::setTarget(Stock* t) {
    this->target = t;
}

Stock* FlowBody::getTarget(){
    return this->target;
}

FlowBody* FlowBody::operator=(FlowBody* s){

    if(this == s)
        return this;
    this->setSource(s->getSource());
    this->setTarget(s->getTarget());
    return this;
}

void FlowBody::connect(Stock *s1, Stock *s2){
    this->source = s1;
    this->target = s2;
}
double FlowBody::getValue(){
    return this->value;
}
void FlowBody::setValue(double value){
    this->value = value;
}
