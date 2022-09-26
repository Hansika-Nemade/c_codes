//Headers
//#include<cstdio>
//#include<cstdlib>
#include<iostream>

template <typename type>
class Vector
{
    private:
        int  size_vector;
        type  *p_arr;

    public:

        Vector():size_vector(0) , p_arr(NULL)
        {

        }

        void push_back(type data)
        {
            size_vector++;
            p_arr = (type*) realloc(p_arr , size_vector * sizeof(type));
            p_arr[size_vector-1] = data;
           // std::cout<<"data added successfully" << std::endl;
        }

        void show(const char* msg)
        {
           puts(msg);

           for(int le = 0; le < size_vector ; le++)
           {
               std::cout<<"p_arr["<< le <<"] : " << p_arr[le] << std::endl;
           }

           puts("end");
        }

        int length() const
        {
            return(size_vector);
        }

        ~Vector()
        {
            free(p_arr);
            p_arr = NULL;
        }

};

int main(void)
{
    Vector<int> ivec;
    Vector<char> cvec;
    Vector<float> fvec;

    for(int le = 0; le < 10 ; le++)
    {
        ivec.push_back(15 * (le+1));
    }

    for(int le = 0; le < 10 ; le++)
    {
        cvec.push_back(65+le);
    }

    for(int le = 0; le < 5 ; le++)
    {
        fvec.push_back(3.2*(le+1));
    }

    ivec.show("integer vector:");
    cvec.show("character vector: ");
    fvec.show("float vector: ");

    return(0);
}
