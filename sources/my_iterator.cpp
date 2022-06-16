
// #include "my_iterator.hpp"

// template<typename T,typename Y>
// my_iterator<T,Y>::my_iterator() : pos(0), root(nullptr){
// }


// template<typename T,typename Y>
// my_iterator<T,Y>::my_iterator(T* _root) : pos(0), root(&((*_root)[0])){
// }


// template<typename T,typename Y>
// my_iterator<T,Y>& my_iterator<T,Y>::operator++(){
//     this->pos++;
    // if (this->pos >= 20)
    // {
    //     *this = my_iterator<T,Y>{};
    //     return *this;
    // }

//     this->root = &((*this->root)[pos]);
//     return *this;
// }


// template<typename T,typename Y>
// my_iterator<T,Y> my_iterator<T,Y>::operator++(int){
//     my_iterator ans = *this;
    // if (this->pos >= 20)
    // {
    //     *this = my_iterator<T,Y>{};
    //     return *this;
    // }

//     this->pos++;
//     this->root = &((*this->root)[pos]);
//     return ans;
// }


// template<typename T,typename Y>
// bool my_iterator<T,Y>::operator==(const my_iterator<T,Y>& element) const{
//     return this->root == element.root;
// }


// template<typename T,typename Y>
// bool my_iterator<T,Y>::operator!=(const my_iterator<T,Y>& element) const{
//     return !(*this == element);
// }
