#include "Vector.h"
#include <assert.h>

#define INFO \
cout<< __FUNCTION__, __FILE__, __LINE__ <<endl; \


#define ASSERT_OK()			\
if (!ok())					\
{							\
	INFO					\
	dump();					\
	assert(!"Object is OK");\
}	




typedef float value_type; // Elements type





//template <typename Type>
//static const POISON = (Type)NAN;

template <typename Type>

Vector<Type>::Vector()
{
	size_ = 10;
	data_ = new Type[10];
	for (size_t i = 0; i < size_; i++)
		*(data_+ i) = 0;
	//std::cout << "Constructor without parametres was called" << endl;
	INFO
	dump();
}

template <typename Type>
Vector<Type>::Vector(size_t size)
{
	data_ = new Type[size];
	size_ = size;
	for (size_t i = 0; i < size_; i++)
		*(data_ + i) = 0;
	//std::cout << "Constructor with parametr was called" << endl;
	INFO
	dump();
}

template <typename Type>
Vector<Type>::~Vector()
{
	for (size_t i = 0; i < size_; i++)
	{
		*(data_ + i) = 1;
		size_ = 1;
	}
	delete[] data_;

	//std::cout << "Distructor was called" << endl;
	INFO
	dump();
}

template <typename Type>

 Vector<Type>::Vector<Type>(Vector<Type> const& that)
{
	ASSERT_OK();
	

	size_ = that.size_;
	//data_ = new value_type[that.size_];

	//data_ = Vector::operator new(size_, 0, data_);
	//new(size_, 0, data_)Vector(that);
	data_ =  new(0)value_type[size_];

	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = that.data_[i];
	}

	//std::cout << "Copy was called" << endl;
	INFO
	dump();
}

template <typename Type>
void Vector<Type>::ReSize(size_t newsize)
{
	ASSERT_OK();
	Vector<Type> t(newsize);
	//size_t p = newsize > size_ ? size_ : newsize;
	if (newsize > size_)
		{
			for (size_t i = 0; i < size_; i++)
			{
				t.data_[i] = data_[i];
			}
			for (size_t i = size_; i < newsize; i++)
			{
				t.data_[i] = 0;
			}
		}
	else
		{
			for (size_t i = 0; i < newsize; i++)
			{
				t.data_[i] = data_[i];
			}
		}
	delete[] data_;
	data_ = new Type[newsize];
	for (size_t i = 0; i < newsize; i++)
	{
		data_[i] = t.data_[i];
	}

	//std::cout << "Function Resize was called" << endl;
	INFO
	dump();
}

template <typename Type>
void Vector<Type>::dump()
{
	std::cout << "Masssive's name: " << data_ << endl;
	std::cout << "size: " << size_ << endl;

	for (size_t i = 0; i < size_; i++)
		std::cout << "[" << i << "] = " << data_[i] << endl;
	INFO
}

template <typename Type>
size_t Vector<Type>::Size()
{
	ASSERT_OK();
	//std::cout << "Function Size was called" << endl;
	INFO
	dump();
	return size_;
}

template <typename Type>
Type Vector<Type>::GetEl(size_t i) const
{
	//std::cout << "Function GetEl was called" << endl;
	INFO
	return data_[i];
}


//---------------------------
//!Check the mass
//---------------------------
template <typename Type>
bool Vector<Type>::ok()
{
	for (size_t i = 0; i < size_; i++)
		if (this->GetEl(i) == POISON || this->size_ == NULL)
		{
			INFO
			return false;
		}
	INFO
	return true;
}

template <typename Type>
Type& Vector<Type>::front()
{
	ASSERT_OK();
	INFO
	return data_[0];
}

template <typename Type>
Type & Vector<Type>::at(size_t i)
{
	if (i <= size_)
	{
		cout << "Provide access unto Vector's element" << endl;
		INFO
		return data_[i];
	}
	else
	{
		cout << "Index is very big, please reduce it, give a provide to the last element" << endl;
		INFO
		_getch();
	}	
	return data_[size_ - 1];
}

template <typename Type>
Type & Vector<Type>::back()
{
	ASSERT_OK();
	INFO
	return *(data_ + size_ - 1);
}

template <typename Type>
void Vector<Type>::swap(Vector<Type>& a)
{
	size_t t = size_;
	size_ = a.size_;
	a.size_ = t;

	cout << "Swaped size_t size_" << endl;

	Type * d = data_;
	data_ = a.data_;
	a.data_ = d;

	cout << "Swaped value_type* data_" << endl;
	
	INFO
}

template <typename Type>
const Type* Vector<Type>::data()
{
	ASSERT_OK();
	INFO
	return data_;
}

template <typename Type>
Type* Vector<Type>::begin()
{
	ASSERT_OK();
	INFO
	return &data_[0];
}

template <typename Type>
Type * Vector<Type>::end()
{
	ASSERT_OK();
	INFO
	return &data_[size_];
}

template <typename Type>
bool Vector<Type>::empty()
{
	ASSERT_OK();
	if (begin() == end())
	{
		INFO
		return true;
	}
	else
	{
		INFO
		return false;
	}
}

template <typename Type>
size_t Vector<Type>::size()
{
	ASSERT_OK();
	size_t size = std::distance(begin(), end());
	INFO
	return size;
}