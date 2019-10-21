#ifndef STOCKIMPL_HPP
#define STOCKIMPL_HPP
#include"stock.hpp"
#include"handlebody.hpp"

class StockBody: public Body{
public: 
    /// Constructor: zero references when the object is being built
	StockBody(): Body(){  
	    this->energy_ = 0;
    }
	/// Destructor
	virtual ~StockBody(){}

    StockBody(float v): energy_(v), Body(){}

    float getEnergy(void);//{return this->energy_; }
    virtual void setEnergy(float energy);//{this->energy_ = energy; }

	void run(int a,int b){}

private:

	/// No copy allowed
	StockBody(const StockBody&);

	/// Implementation
	StockBody& operator=(const StockBody&){return *this;}

protected:
    float energy_;

};

class StockHandle: public Stock, public Handle <StockBody>{
public:	
    /// Default constructor
    StockHandle(){  
		pImpl_ = new StockBody(); 
        pImpl_->attach();  
	}
	/// constructor
	StockHandle(float val){  
		pImpl_ = new StockBody( val); 
        pImpl_->attach();  
	}
	
	/// Destructor
	virtual ~StockHandle(){ 
        pImpl_->detach();
    }

	/// assignment operator
	StockHandle& operator=( const StockHandle& hd) {

		if (  this != &hd )
		{
			hd.pImpl_->attach();
			pImpl_->detach();	
			pImpl_  = hd.pImpl_;
		}
		return *this;
	}

public:

    float getEnergy(void){ return pImpl_->getEnergy();  } 
    virtual void setEnergy(float val ){ pImpl_->setEnergy(val); }
	void run(int a, int b){pImpl_->run(a,b);}

};

#endif