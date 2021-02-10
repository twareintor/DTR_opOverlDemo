

#include <iostream>
#include <map>

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest(); 	friend void intervalMapTest1(); 	friend void intervalMapTest2(); 	friend void intervalMapTest3(); 	
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
	    /***************************************************************/
	    if(keyEnd<keyBegin) return;
	    K itr = keyBegin;
	    if(itr<keyEnd)
	    {
	    	m_map[itr] = val;
	    	itr = m_map.lower_bound(itr)->first;
	    	assign(itr, keyEnd, val);
		}
		else
		{
			m_map[itr] = val;
		}
        /***************************************************************/
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

#include "shelter.h"

void intervalMapTest2()
{
	CAnimal oaie, oaie2, oaie3, capra, capra2, capra3, magar, porc, porc1, porc2, cane, cane2;
	CShelter saivanA, saivanB, saivanC;
	
	CAnimal turma_mea[] = {oaie, oaie2, oaie3, capra, capra2, capra3, magar, porc, porc1, porc2, cane, cane2, };
	CShelter saivane[] = {saivanA, saivanB, saivanC};
			
	interval_map<CAnimal, CShelter> imap(saivanA);
	std::cout<<std::endl; for(auto&& it: turma_mea) std::cout<<it<<"\t"<<imap[it]<<std::endl;	// expected AAAAAAAAAAAAAAAA
	                                                                                                    //  0123456789abcdef
	imap.assign(oaie3, magar, saivanC); std::cout<<"here\n";
	std::cout<<std::endl; for(auto&& it: turma_mea) std::cout<<it<<"\t"<<imap[it]<<std::endl;	// expected AACCAAAAAAAAAAAA
	                                                                                                    //  0123456789abcdef
	
}

void intervalMapTest1()
{
	/* */
	CAnimal oaie;
	CAnimal capra;
	CAnimal magar;
	CAnimal oaie2;
	CAnimal oaie3;
	
	std::vector<CAnimal> turma_mea{oaie, capra, magar, oaie2, oaie3};
	std::vector<CAnimal> turma_ta(7);
	turma_mea.insert(turma_mea.end(), turma_ta.begin(), turma_ta.end());
	
	CShelter saivanA;
	CShelter saivanB;
	CShelter saivanC;
	
    interval_map<CAnimal, CShelter> imap(saivanA);
    imap.m_map = {{magar, saivanC}, {oaie3, saivanA}};
    std::cout<<std::endl; for(auto&& it: turma_mea) std::cout<<it<<"\t"<<imap[it]<<std::endl;	// expected AACCAAAAAAAAA
    return;
    imap.assign(capra, capra, saivanC);
    std::cout<<std::endl; for(auto&& it: turma_mea) std::cout<<it<<"\t"<<imap[it]<<std::endl;	// expected ACCCAAAAAAAAA
	imap.assign(magar, oaie3, saivanB);    	
	std::cout<<std::endl; for(auto&& it: turma_mea) std::cout<<it<<"\t"<<imap[it]<<std::endl;	// expected ...
	imap.assign(magar, oaie3, saivanA);    	
	std::cout<<std::endl; for(auto&& it: turma_mea) std::cout<<it<<"\t"<<imap[it]<<std::endl;	// expected ...
	
}

void IntervalMapTest()
{
	
	intervalMapTest1();
}


