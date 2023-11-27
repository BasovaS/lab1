#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Array
{
public:

    typedef double
        value_type;
    typedef double*
        iter;
    typedef const double*
        const_iter;
    typedef double&
        reference;
    typedef const double&
        const_reference;
    typedef size_t
        size_type;

    Array(const size_type n);
    Array(const Array& array);
    Array(iter first, iter last);

    ~Array(){ delete[]ptr; }

    Array& operator=(const Array&);

    iter begin() { return ptr; }
    const_iter begin() const { return ptr; }
    iter end() { return ptr + Count; }
    const_iter end() const { return ptr + Count; }

    size_type size() const{
        return Count;
    }

    void resize(size_type newsize);

    size_type capacity() const{
        return msize;
    }

    bool empty() const{
        if (Count == 0)
            return true;
        else
            return false;
    }

    refoperator[](size_type index);
    const_refoperator[](size_type index) const;
    reffront() { return ptr[0]; }
    const_reffront() const { return ptr[0]; }

    refback(){
        return ptr[size() - 1];
    }

    const_refback() const { return ptr[size() - 1]; }

    void swap(Array& other);

    void push_back(const value_type& v);

    void pop_back(){
        ptr[Count - 1] = 0;
        Count--;
    }

    // очистить массив
    void clear(){
        Count = 0;
    }

    void show(){
        for (int i = 0; i < Count; i++){
            cout.precision(3);
            cout <<  fixed << ptr[i] << " ";
        }
        cout << '\n';
    }

private:
    value_type* ptr;
    size_type Count;
    static const size_type min = 10;
    size_type msize;
};

double summary(const Array& arr){
    double sum = 0;

    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    return sum;
}

double average(const Array& arr){
    double aver = summary(arr) / arr.size();

    return aver;
}

void hsum(Array& arr){
    int c;

    float f, negative, halfsum;

    for (int i = 0; i < arr.size(); i++){
        if (arr[i] < 0){
            f = arr[i];

            break;
        }
    }

    for (int i = 0; i < arr.size(); i++){
        if (i == 5){
            negative = arr[i];

            break;
        }
    }

    halfsum = (f + negative) / 2;

    for (int i = 0; i < arr.size(); i++)
        (arr.begin())[i] = (arr.begin())[i] / halfsum;
}

void Array::push_back(const value_type& v){
    if (Count == msize)
        resize(msize * 2);

    ptr[Count++] = v;
}

void Array::resize(size_type newsize){
    value_type* s = new value_type[newsize];

    for (size_type i = 0; i < Count; ++i)
        s[i] = ptr[i];

    delete[] ptr;

    ptr = s;
    msize = newsize;
}

Array::Array(iter first, iter last){
    if (first < last){
        msize = (first - last);
        ptr = new value_type[msize];

        for (int i = 0; i < msize; ++i)
            ptr[i] = *(first + i);

        Count = msize;
    }
}

Array::Array(const size_type n){
    msize = n;
    ptr = new value_type[n];
    Count = 0;
}

double& Array::operator[](size_type index){
    if (index < Count)
        return ptr[index];
}

const double& Array::operator[](size_type index) const{
    if (index < Count)
        return ptr[index];
}

int main(){
    int size, c = 1;
    double elem, sum = 0, aver = 0;

    cin >> size;

    Array arr(size);

    for (int i = 0; i < size; i++)    {
        cin >> elem;

        arr.push_back(elem);
    }

    cout << arr.size() << '\n';

    arr.show();

    sum = summary(arr);
    aver = average(arr);

    arr.push_back(sum);
    arr.push_back(aver);

    arr.show();

    hsum(arr);

    arr.show();

    while (true){
        cin >> c;

        if (c == 0){
            break;
        }

        else{
            switch (c){
            case 1:
                cin >> elem;

                arr.push_back(elem);

                cout << "+:" << arr.size() << '\n';

                arr.show();

                sum = summary(arr);
                aver = average(arr);

                arr.push_back(sum);
                arr.push_back(aver);

                arr.show();

                hsum(arr);

                arr.show();

                break;
            case 2:
                arr.pop_back();

                cout << "-:" << arr.size() << '\n';

                arr.show();

                sum = summary(arr);
                aver = average(arr);

                arr.push_back(sum);
                arr.push_back(aver);

                arr.show();

                hsum(arr);

                arr.show();
                break;
            }
        }
    }
    return 0;
}