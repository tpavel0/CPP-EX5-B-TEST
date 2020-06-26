#ifndef RANGE_HPP
#define RANGE_HPP

namespace itertools{
    class range{
        int Begin, endd;

    public:
        range(int a, int b): Begin(a), endd(b){}

        class iterator{
            int Value;
        public:
            explicit iterator(int val): Value(val) {};
            iterator(const iterator& tempIT) = default;
            iterator& operator=(const iterator& tempIT){
                if(this != &tempIT)
                    this->Value = tempIT.Value;
                return *this;
            };
            iterator& operator ++(){
                Value++;
                return *this;
            }
            iterator operator ++(int){
                iterator temp = *this;
                Value++;
                return temp;
            }
            bool operator ==(const iterator& tempIT) {
                if(Value == tempIT.Value)
                    return true;
                return false;
            }
            bool operator !=(const iterator& tempIT) {
                if(Value != tempIT.Value)
                    return true;
                return false;
            }
            int operator *(){
                return Value;
            }
        };

        iterator begin(){
            return iterator(Begin);
        }
        iterator end(){
            return iterator(endd);
        }


        typedef int	value_type;
    };
}
#endif
