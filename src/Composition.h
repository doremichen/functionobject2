/*
 * Composition.h
 *
 *  Created on: 2014/1/23
 *      Author: AdamChen
 */

#ifndef COMPOSITION_H_
#define COMPOSITION_H_

template<class X, class Y> class Com_base {
public:
	virtual Y operator() (X) const = 0;
	virtual Com_base* clone() const = 0;
	virtual ~Com_base() {}

};

template<class F, class G, class X, class Y>
class Comp: public Com_base<X, Y> {
public:
	Comp(F f0, G g0): f(f0), g(g0) {}
	Y operator() (X x) const { return f(g(x));}
	Com_base<X, Y>* clone() const
	{
    	return new Comp(*this);
	}

private:
	F f;
	G g;
};

//Composition class
template<class X, class Y>
class Composition {
public:
	template<class F, class G> Composition(F, G);
	Composition(const Composition&);
	Composition& operator=(const Composition&);
	Y operator() (X) const;
	~Composition();
private:
	Com_base<X, Y>* p;
};


template<class X, class Y>
template<class F, class G>
Composition<X, Y>::Composition(F f, G g):
	p(new Comp<F, G, X, Y>(f, g)) {}

template<class X, class Y>
Composition<X, Y>::~Composition()
{
	delete p;
}

template<class X, class Y>
Composition<X, Y>::Composition(const Composition& c):p(c.p->clone())
{ }

template<class X, class Y>
Composition<X, Y>& Composition<X, Y>::operator=(const Composition& c)
{
	if(this != c) {
		delete p;
		p = c.p->clone();
	}
	return *this;
}

template<class X, class Y>
Y Composition<X, Y>::operator() (X x) const
{
	return (*p)(x);
}


#endif /* COMPOSITION_H_ */
