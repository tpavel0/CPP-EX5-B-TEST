#ifndef COMPRESS_HPP
#define COMPRESS_HPP
#include <iostream>
#include <vector>

namespace itertools{
    template<typename CONT_1, typename CONT_2>
    class compress {
        CONT_1 Containerr;
        CONT_2 BoolContainer;
        typedef typename CONT_1::value_type value_type;

    public:
        compress(CONT_1 cont, CONT_2 BoolCont): Containerr(cont), BoolContainer(BoolCont){}

        class iterator{
            typename CONT_1::iterator it;
            typename CONT_1::iterator endd;
            typename CONT_2::iterator BoolIt;
        public:
            explicit iterator(typename CONT_1::iterator Itera, typename CONT_1::iterator end, typename CONT_2::iterator boolit)
                : it(Itera), endd(end), BoolIt(boolit){
                while (it != endd && !(*BoolIt)){
                    it++;
                    BoolIt++;
                }
            }
            iterator(const iterator& tempIT) = default;

            iterator& operator=(const iterator& tempIT){
                if(this != &tempIT)
                    this->it = tempIT.it;
                return *this;
            };
            iterator& operator ++(){
                    it++;
                    BoolIt++;
                while (it != endd && !(*BoolIt)){
                    it++;
                    BoolIt++;
                }
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
            return iterator(Containerr.begin(), Containerr.end(), BoolContainer.begin());
        }
        iterator end(){
            return iterator(Containerr.end(), Containerr.end(), BoolContainer.end());
        }
    };
}


#endif 
