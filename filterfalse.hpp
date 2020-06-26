#ifndef FILTERFALSE_HPP
#define FILTERFALSE_HPP
#include <iostream>
#include <vector>

namespace itertools{
    template<typename FUNC, typename CONT>
    class filterfalse {
        FUNC Fun;
        CONT Containerr;
        typedef typename CONT::value_type value_type;

    public:
        filterfalse(FUNC f, CONT container): Fun(f), Containerr(container){}

        class iterator{
            typename CONT::iterator it;
            typename CONT::iterator endd;
            FUNC Fun;
        public:
            explicit iterator(typename CONT::iterator Itera, typename CONT::iterator end, FUNC f)
                : it(Itera), endd(end), Fun(f){

                while (it != endd && Fun(*it))
                    it++;
            }
            iterator(const iterator& tempIT) = default;

            iterator& operator=(const iterator& tempIT){
                if(this != &tempIT) {
                    this->it = tempIT.it;
                    this->endd = tempIT.endd;
                    this->Fun = tempIT.Fun;
                }
                return *this;
            };
            iterator& operator ++(){
                    it++;
                while (it != endd && Fun(*it))
                    it++;
                return *this;
            }
            iterator operator ++(int){
                iterator temp = *this;
                (*this)++;
                return temp;
            }
            bool operator ==(const iterator& tempIT) {
                if(it == tempIT.it)
                    return true;
                return false;
            }
            bool operator !=(const iterator& tempIT) {
                if(it != tempIT.it)
                    return true;
                return false;
            }
            value_type operator *(){
                return *it;
            }

        };
        iterator begin(){
            return iterator(Containerr.begin(), Containerr.end(), Fun);
        }
        iterator end(){
            return iterator(Containerr.end(), Containerr.end(), Fun);
        }
    };
}
#endif 
