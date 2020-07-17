/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/16 21:52:09 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdint>
#include <stdexcept>
#include <climits>

#define CAP 128

namespace ft
{
    template <typename T>
    class Vector
    {
        private:
		
            T *array;
            size_t total;
            size_t cap;
			
        public:
		
			// iterator (abstract class)
			class AIterator
			{
				protected:
			
					T *array;
					size_t pos;
				
				public:
			
					AIterator(T *array, size_t pos)
					{
						this->array = array;
						this->pos = pos;
					}
						
					virtual ~AIterator()
					{
					}
						
					T& operator*()
					{
						return (this->array[this->pos]);
					}

					size_t get_position()
					{
						return (this->pos);
					}
					
			};
			
			// iterator (random access iterator)
			class Iterator: public AIterator
			{
				public:
		
					Iterator(T *array, size_t pos):
						AIterator(array, pos)
					{
					}

					virtual ~Iterator()
					{
					}

					bool operator==(Iterator const &other) const
					{
						if (this->array != other.array)
							return (false);
						if (this->pos != other.pos)
							return (false);
						return (true);
					}

					bool operator!=(Iterator const &other) const
					{
						if (*this == other)
							return (false);
						return (true);
					}

					Iterator& operator++()
					{
						this->pos++;
						return (*this);
					}

					Iterator& operator++(int)
					{
						Iterator(*this);
						this->pos++;
						return (*this);
					}
					
					Iterator& operator+(size_t n)
					{
						Iterator(*this);
						this->pos += n;
						return (*this);
					}

					Iterator& operator+=(size_t n)
					{
						this->pos += n;
						return (*this);
					}

					Iterator& operator--()
					{
						this->pos--;
						return (*this);
					}

					Iterator& operator--(int)
					{
						Iterator(*this);
						this->pos--;
						return (*this);
					}
					
					Iterator& operator-(size_t n)
					{
						Iterator(*this);
						this->pos -= n;
						return (*this);
					}

					Iterator& operator-=(size_t n)
					{
						this->pos -= n;
						return (*this);
					}
			};

			// reverse_iterator (random access iterator)
			class ReverseIterator: public AIterator
			{
				public:
		
					ReverseIterator(T *array, size_t pos):
						AIterator(array, pos)
					{
					}

					virtual ~ReverseIterator()
					{
					}

					bool operator==(ReverseIterator const &other) const
					{
						if (this->array != other.array)
							return (false);
						if (this->pos != other.pos)
							return (false);
						return (true);
					}

					bool operator!=(ReverseIterator const &other) const
					{
						if (*this == other)
							return (false);
						return (true);
					}
					
					ReverseIterator& operator++()
					{
						this->pos--;
						return (*this);
					}

					ReverseIterator& operator++(int)
					{
						ReverseIterator(*this);
						this->pos--;
						return (*this);
					}
					
					ReverseIterator& operator+(size_t n)
					{
						ReverseIterator(*this);
						this->pos -= n;
						return (*this);
					}

					ReverseIterator& operator+=(size_t n)
					{
						this->pos -= n;
						return (*this);
					}

					ReverseIterator& operator--()
					{
						this->pos++;
						return (*this);
					}

					ReverseIterator& operator--(int)
					{
						ReverseIterator(*this);
						this->pos++;
						return (*this);
					}
					
					ReverseIterator& operator-(size_t n)
					{
						ReverseIterator(*this);
						this->pos += n;
						return (*this);
					}

					ReverseIterator& operator-=(size_t n)
					{
						this->pos += n;
						return (*this);
					}
			};

			// const_iterator (abstract class)
			class AConstIterator
			{
				protected:
			
					const T *array;
					size_t pos;
				
				public:
			
					AConstIterator(T *array, size_t pos)
					{
						this->array = array;
						this->pos = pos;
					}
						
					virtual ~AConstIterator()
					{
					}
						
					const T& operator*() const
					{
						return (this->array[this->pos]);
					}

					size_t get_position()
					{
						return (this->pos);
					}
					
			};

			// const_iterator (random access iterator)
			class ConstIterator: public AConstIterator
			{
				public:
		
					ConstIterator(T *array, size_t pos):
						AConstIterator(array, pos)
					{
					}

					virtual ~ConstIterator()
					{
					}

					bool operator==(ConstIterator const &other) const
					{
						if (this->array != other.array)
							return (false);
						if (this->pos != other.pos)
							return (false);
						return (true);
					}

					bool operator!=(ConstIterator const &other) const
					{
						if (*this == other)
							return (false);
						return (true);
					}

					ConstIterator& operator++()
					{
						this->pos++;
						return (*this);
					}

					ConstIterator& operator++(int)
					{
						ConstIterator(*this);
						this->pos++;
						return (*this);
					}
					
					ConstIterator& operator+(size_t n)
					{
						ConstIterator(*this);
						this->pos += n;
						return (*this);
					}

					ConstIterator& operator+=(size_t n)
					{
						this->pos += n;
						return (*this);
					}

					ConstIterator& operator--()
					{
						this->pos--;
						return (*this);
					}

					ConstIterator& operator--(int)
					{
						ConstIterator(*this);
						this->pos--;
						return (*this);
					}
					
					ConstIterator& operator-(size_t n)
					{
						ConstIterator(*this);
						this->pos -= n;
						return (*this);
					}

					ConstIterator& operator-=(size_t n)
					{
						this->pos -= n;
						return (*this);
					}
			};
			
			// const_reverse_iterator (random access iterator)
			class ConstReverseIterator: public AConstIterator
			{
				public:
		
					ConstReverseIterator(T *array, size_t pos):
						AConstIterator(array, pos)
					{
					}

					virtual ~ConstReverseIterator()
					{
					}

					bool operator==(ConstReverseIterator const &other) const
					{
						if (this->array != other.array)
							return (false);
						if (this->pos != other.pos)
							return (false);
						return (true);
					}

					bool operator!=(ConstReverseIterator const &other) const
					{
						if (*this == other)
							return (false);
						return (true);
					}
					
					ConstReverseIterator& operator++()
					{
						this->pos--;
						return (*this);
					}

					ConstReverseIterator& operator++(int)
					{
						ConstReverseIterator(*this);
						this->pos--;
						return (*this);
					}
					
					ConstReverseIterator& operator+(size_t n)
					{
						ConstReverseIterator(*this);
						this->pos -= n;
						return (*this);
					}

					ConstReverseIterator& operator+=(size_t n)
					{
						this->pos -= n;
						return (*this);
					}

					ConstReverseIterator& operator--()
					{
						this->pos++;
						return (*this);
					}

					ConstReverseIterator& operator--(int)
					{
						ConstReverseIterator(*this);
						this->pos++;
						return (*this);
					}
					
					ConstReverseIterator& operator-(size_t n)
					{
						ConstReverseIterator(*this);
						this->pos += n;
						return (*this);
					}

					ConstReverseIterator& operator-=(size_t n)
					{
						this->pos += n;
						return (*this);
					}
			};

			// default constructor (1)
            Vector()
            {
            	this->array = new T[CAP];
               	this->total = 0;
              	this->cap = CAP;
            }

			// fill constructor (2)		
            Vector(size_t n, const T &val)
            {
                this->array = new T[CAP];
              	this->cap = CAP;
               	this->total = 0;
                for (size_t i = 0; i < n; i++)
                    this->push_back(val);
            }
		
			/* 
			//Does not work with integral types
			//https://stackoverflow.com/questions/45847787/how-to-differentiate-fill-constructor-and-range-constructor-in-c11
			
			// range constructor (3)
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last)
			{
				this->array = new T[CAP];
              	this->cap = CAP;
               	this->total = 0;
				while (first != last)
				{
					this->push_back(*first);
					++first;
				}
			}
			*/
			
			// copy constructor (4)
            Vector(Vector<T> const &other)
            {
                this->array = new T[other.cap];
               	this->total = 0;
              	this->cap = other.cap;
                for (size_t i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
            }
			
			// assignment operator overload
            Vector& operator=(Vector<T> const &other)
            {
                delete[] this->array;
                this->array = new T[other.cap];
              	this->cap = other.cap;
               	this->total = 0;
                for (size_t i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
                return (*this);
            }

			// destructor
            ~Vector()
            {
                delete[] this->array;
            }
			
			Iterator begin()
			{
				return (Iterator(this->array, 0));
			}

			ConstIterator begin() const
			{
				return (ConstIterator(this->array, 0));
			}

			Iterator end()
			{
				return (Iterator(this->array, this->size()));
			}

			ConstIterator end() const
			{
				return (ConstIterator(this->array, this->size()));
			}

			ReverseIterator rbegin()
			{
				return (ReverseIterator(this->array, this->size() - 1));
			}

			ConstReverseIterator rbegin() const
			{
				return (ConstReverseIterator(this->array, this->size() - 1));
			}
			
			ReverseIterator rend()
			{
				return (ReverseIterator(this->array, SIZE_T_MAX));
			}

			ConstReverseIterator rend() const
			{
				return (ConstReverseIterator(this->array, SIZE_T_MAX));
			}
			
            size_t size() const
            {
                return (this->total);
            }
			
            size_t max_size() const
			{
				return (SIZE_T_MAX / sizeof(T));
			}
			
            void resize(size_t n)
            {
                T *temp = new T[n];
                size_t temp_total = 0;
                for (size_t i = 0; i < this->size() && i < n; i++)
                {
                    temp[i] = this->array[i];
                    temp_total++;
                }
                delete[] this->array;
                this->array = temp;
              	this->total = temp_total;
              	this->cap = n;
            }
			
            size_t capacity() const
            {
                return (this->cap);
            }

            bool empty() const
            {
                if (this->total == 0)
                    return (true);
                else
                    return (false);
            }

            void reserve(size_t n)
            {
				if (n > this->capacity())
                	this->resize(n);
            }
			
            T& operator[](size_t n)
            {
				return (this->array[n]);
            }

            const T& operator[](size_t n) const
            {
				return (this->array[n]);
            }
			
            T& at(size_t n)
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }

            const T& at(size_t n) const
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }
			
            T& front()
            {
				return (this->array[0]);
            }

            const T& front() const
            {
				return (this->array[0]);
            }
			
            T& back()
            {
				return (this->array[this->total - 1]);
            }
			
            const T& back() const
            {
				return (this->array[this->total - 1]);
            }

            void push_back(const T &val)
            {
                if (this->total == this->cap)
                    this->resize(this->cap * 2);
                this->array[this->total] = val;
                this->total++;
            }
			
            void pop_back()
            {
                this->array[this->total - 1] = 0;
                this->total--;
            }
			
            void swap(Vector<T> &other)
            {
				Vector<T> temp(other);
				other = *this;
				*this = temp;
            }

            void clear()
            {
               	this->total = 0;
            }
			
			// SAME FUKIN CRAP, CANT DISTINGUISH BETWEEN INT AND ITERATOR
			template <class Iterator>
			void assign(Iterator first, Iterator last)
			{
				this->clear();
				while (first != last)
				{
					this->push_back(*first);
					++first;
				}
			}

			// SAME FUKIN CRAP, CANT DISTINGUISH BETWEEN INT AND ITERATOR
			void assign(size_t n, const T &val)
			{
				this->clear();
				for (size_t i = 0; i < n; i++)
					this->push_back(val);
			}
			
			// NOT CORRECT, NEED BETTER ALGORITHM
			Iterator erase(Iterator pos)
			{
				size_t pos_save = pos.get_position();
				Iterator temp(this->array, pos.get_position());
				while (pos != this->end())
				{
					temp++;
					*pos = *temp;
					pos++;
				}
				this->total -= 1;
				return (Iterator(this->array, pos_save));
			}

			// NOT CORRECT, NEED BETTER ALGORITHM
			Iterator erase(Iterator first, Iterator last)
			{
				size_t first_save = first.get_position();
				size_t last_save = last.get_position();
				while (first.get_position() != last_save) 
				{
					*first = *last;
					first++;
					last++;
					this->total -= 1;
				}
				return (Iterator(this->array, first_save));
			}
			
            /*
				ASSIGN TESTEN
				INSERT ITERATOR TYPE RESEARCHEN
				ERASE PROTOTYPES CHECKEN
				
                assign()
                insert()
                erase()
            */
    };
	
    template <typename T>
    void swap(Vector<T> &first, Vector<T> &second)
    {
		Vector<T> temp(second);
		second = first;
		first = temp;
    }

    template <typename T>
    bool operator==(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

    template <typename T>
    bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (false);
		else
			return (true);
	}

    template <typename T>
    bool operator<(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (false);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (true);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator>(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (false);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (true);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())
			return (false);
		return (true);
	}
}

#endif
