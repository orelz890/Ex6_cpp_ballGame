#pragma once

template<typename T,typename Y> class my_iterator{

    private:
    T* leauge;
    Y* root;
    int pos = 0;

    public:
    // my_iterator();

    // my_iterator(T* _root);

    Y& operator*() const{
        return *this->root;
    }

    Y* operator->() const{
        return this->root;
    }

    // my_iterator& operator++();

    // my_iterator operator++(int);

    // bool operator==(const my_iterator& element) const;

    // bool operator!=(const my_iterator& element) const;
    
    my_iterator() : pos(0), root(nullptr), leauge(nullptr){
    }


    my_iterator(T* _root) : pos(0), root(&((*_root)[0])), leauge(_root){
    }


    my_iterator<T,Y>& operator++(){
        this->pos++;
        if (this->pos >= 20)
        {
            *this = my_iterator<T,Y>{};
            return *this;
        }
        
        this->root = &((*this->leauge)[pos]);
        return *this;
    }


    my_iterator<T,Y> operator++(int){
        my_iterator ans = *this;
        this->pos++;
        if (this->pos >= 20)
        {
            *this = &my_iterator<T,Y>{};
            return *this;
        }
        this->root = &((*this->leauge)[pos]);
        return ans;
    }


    bool operator==(const my_iterator<T,Y>& element) const{
        return this->root == element.root;
    }


    bool operator!=(const my_iterator<T,Y>& element) const{
        return !(*this == element);
    }
};
