#ifndef ACCUMULATE_HPP
#define ACCUMULATE_HPP
namespace itertools{
    typedef struct{
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } plus;

    template <typename CONT, typename  FUNC = plus>
    class accumulate{
        CONT containerr;
        FUNC function;
        typedef typename CONT::value_type value_type;
    public:
        explicit accumulate(CONT container, FUNC func = plus())
                : containerr(container), function(func){}

        class iterator{
            typename CONT::value_type data;
            typename CONT::iterator it;
            typename CONT::iterator endd;
            FUNC function;
        public:
            explicit iterator(typename CONT::iterator Itera, typename CONT::iterator end, FUNC func)
                    : it(Itera), endd(end), function(func)
                    {
                        if (it != end)
                        data =*Itera;
                    };
            iterator(const iterator& tempIT) = default;
            iterator& operator=(const iterator& tempIT){
                if(this != &tempIT) {
                    this->data = tempIT.data;
                    this->it = tempIT.it;
                    this->endd = tempIT.endd;
                    this->function = tempIT.function;
                }
                return *this;
            };
            iterator& operator ++(){
                it++;
                if(it != endd)
                    data = function(data, *it);
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

            auto operator *(){
                return data;
            }
        };


        iterator begin(){
            return iterator(containerr.begin(), containerr.end(), function);
        }
        iterator end(){
            return iterator(containerr.end(), containerr.end(), function);
        }

    };
}

#endif 
